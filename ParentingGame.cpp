/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	ParentingGame.cpp
	An adventurous day in the life of a parent
	Author: Hayley Andrews
	This program is entirely my own work.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <string>
using namespace std;

/*~~~~~~~~~~~~~~~~~~
Function Prototypes
~~~~~~~~~~~~~~~~~~~~*/
void DescribeRoomContents(int roomDesc, int Row, int Column);
void BuildRooms(unsigned int rooms[][4]);
int TakeItem(unsigned int rooms[][4], int NumberRows, int NumberColumns, string Object);
void DescribePatio();
void DescribeBackyard1();
void DescribeBackyard2();
void DescribeLaundryRoom();
void DescribeDiningRoom();
void DescribeKitchen();
void DescribeDen();
void DescribeBedroom();
void DescribeBathroom();
void DescribeHallway1();
void DescribeHallway2();
void DescribeNursery();
void DescribeLivingRoom();
void DescribeFoyer();
void DescribeSidewalk();
void DescribeGarage();

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Defining Doors, Treasures, Items, and Creatures
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//Define Doors
#define NorthDoor		0x00000001
#define EastDoor		0x00000002
#define SouthDoor		0x00000004
#define WestDoor		0x00000008
//Define Treasure Items (Nibble 1)
#define StackofDiapers	0x00000010
#define BabyBottle		0x00000020
#define Wipes			0x00000040
#define Formula			0x00000080
//Define Creatures (Nibbles 2 and 3)
#define DustBunny		0x00000100
#define Booger			0x00000200
#define ScooterTheDog	0x00000400
#define PileOfLaundry	0x00000800
#define Neighbor		0x00001000
#define SimbaTheCat		0x00002000
#define TheSandman		0x00004000
#define Snake			0x00008000
//Define Dangerous Creatures (Nibble 4)
#define DEADLY			0x00010000
#define DANGEROUS		0x00020000
#define CAUTION			0x00040000
#define FRIENDLY		0x00080000
//Define Other Takeable Items (Nibbles 5 and 6)
#define	RemoteControl	0x00100000
#define	FruitSnacks		0x00200000
#define	VacuumCleaner	0x00400000
#define	BabyBlanket		0x00800000
#define	FeltBook		0x01000000
#define	ToiletPaper		0x02000000
#define	CoffeeCup		0x04000000
#define	BabySock		0x08000000

/*~~~~~~~~~~~~
Main Function
~~~~~~~~~~~~~~*/
int main()
{
	string cmdVerb;
	string cmdObj;
	string Object;
	int index;		//Initialize 'index' for all caps command
	bool bQuitGame;	//Initialize 'bQuitGame'
	unsigned int Parenting[4][4];	//2-D array of ints to define room contents, etc.
	//int roomTest = 0xFFFFFFFF;
	int iPlayer = 0;
	int endRow = 3;
	int endColumn = 3;

	//Make sure the array is initially all zeros
	for (int NumberRows = 0;NumberRows < 5;NumberRows++)
	{
	for (int NumberColumns = 0;NumberColumns < 5;NumberColumns++)
		Parenting[NumberRows][NumberColumns] = 0;
	}

	BuildRooms(Parenting);	//Build the rooms

	//Initialize location variables
	int Row = 3, Column = 1, NumberRows = 4, NumberColumns = 4;
	//Start in Foyer (Column 1, Row 3)
	//Row=current row, Column=current column
	//NumberRows=total rows, NumberColumns=total columns

//Prints Instructions to Player
	cout << "\t                                 _____   _____   _____   _____ " << endl;
	cout << "\tPARENTING. . .			|\\____\\ |\\____\\ |\\____\\ |\\____\\ " << endl;
	cout << "\tAN ADVENTURE!			|| B  | || A  | || B  | || Y  | " << endl;
	cout << "\t				\\|____| \\|____| \\|____| \\|____| " << endl << endl;
cout << "\tCongratulations! You are a new parent of a beautiful baby boy!" << endl;
cout << "\tHe is happy, healthy, and everything you've ever dreamed of." << endl;
cout << "\tUnfortunately, this morning you are running late for work" << endl;
cout << "\tbut must drop off your baby at daycare first. Before you can\n\tleave the house,";
cout << "you must collect all the items you need for your\n\tbaby's diaper bag.";
cout << " You'll need a stack of diapers, a baby bottle,\n\twipes, and formula.";
cout << " When you have collected every item, bring\n\tthem to the car in the garage."<< endl;
cout << "\tTo travel from one area to the next, use the following commands:" << endl;
cout << "\tGO NORTH, GO SOUTH, GO EAST, or GO WEST." << endl;
cout << "\tTo pick up an item, like a bottle, use the command TAKE BOTTLE." << endl;
cout << "\tBe careful, though, in some areas, there are 'creatures'" << endl;
cout << "\tthat may ruin your morning!" << endl << endl;

//Prompt to Begin Playing
cout << "Press 'Enter' to begin" << endl;
getc(stdin);	//Get a single key press
//Describe the first room
DescribeFoyer();

//~~~~~~~~~~~~~~~~~~~~~
//START GAME LOOP HERE
//~~~~~~~~~~~~~~~~~~~~~

bQuitGame = false;	//Initialize end of game flag
while (!bQuitGame)	//While NOT bQuitGame
{

	//Player is prompted and enters command
	cout << "What would you like to do? ";
	cin >> cmdVerb >> cmdObj;
	cout << endl;

	//Commands in all CAPS
	index = 0;	//Set index to 0
	for (index = 0;index < cmdVerb.length();index++)
	{
		cmdVerb[index] = toupper(cmdVerb[index]);
	}
	for (index = 0;index < cmdObj.length();index++)
	{
		cmdObj[index] = toupper(cmdObj[index]);
	}

	//Command List			Object List
	//		GO			NORTH, SOUTH, EAST, WEST
	//		TAKE				TBD
	//		QUIT				GAME

	// Check the GO command
	if (cmdVerb == "GO")
	{
		//cout << "Command verb is GO" << endl;
		//Check direction
		if (cmdObj == "NORTH")
		{
			//Can we move that way?
			if (Parenting[Row][Column] & NorthDoor)
			{
				Row--;
				DescribeRoomContents(Parenting[Row][Column], Row, Column);
			}
			else
				cout << "There is no door to the North." << endl;
		}
		else if (cmdObj == "SOUTH")
		{
			if (Parenting[Row][Column] & SouthDoor)
			{
				Row++;
				DescribeRoomContents(Parenting[Row][Column], Row, Column);
			}
			else
				cout << "There is no door to the South." << endl;
		}
		else if (cmdObj == "EAST")
		{
			if (Parenting[Row][Column] & EastDoor)
			{
				Column++;
				DescribeRoomContents(Parenting[Row][Column], Row, Column);
			}
			else
				cout << "There is no door to the East." << endl;
		}
		else if (cmdObj == "WEST")
		{
			if (Parenting[Row][Column] & WestDoor)
			{
				Column--;
				DescribeRoomContents(Parenting[Row][Column], Row, Column);
			}
			else
				cout << "There is no door to the West." << endl;
		}
		else
		{
			cout << "I don't understand GO " << cmdObj << endl;
		}
		if ((Row == endRow) && (Column == endColumn))	//Are we there yet?
			if ((iPlayer&StackofDiapers) && (iPlayer&BabyBottle) && (iPlayer&Wipes) && (iPlayer&Formula))
			{
				//Yes, so tell the player
				cout << "\n\n\tCONGRATULATIONS! You have successfully packed the diaper bag \n\tand gotten in the car!\n\n";
				cout << "\tAfter grabbing the Stack of Diapers, Baby Bottle, Wipes, and Formula,\n";
				cout << "\tyou are ready to drop the baby off at daycare and will be just \n\tin time for work.";
				cout << " Drive safe!" << endl << endl;
				bQuitGame = true;	//Set boolean flag to end the game
			}
		}

		//Check TAKE command
		else if (cmdVerb == "TAKE")
		{
			int takeVal = TakeItem(Parenting, Row, Column, cmdObj);
			if (takeVal)
			{
				iPlayer |= takeVal;	//Add this item to the player
				cout << "You are now carrying the " << cmdObj << endl;
			}
			else
				cout << "You cannot take the " << cmdObj << " from this location." << endl;
		}
		//Check QUIT command
		else if (cmdVerb == "QUIT")
		{
			//cout << "Command verb is QUIT" << endl;
			return 0;	//Ends Game
		}

		//Other commands
		else
		{
			cout << "I don't understand " << cmdVerb << endl;
		}

		
		/*//Output command for Testing
		cout << "Command is: " << cmdVerb << " " << cmdObj << endl;
		cout << "Location is: Row " << Row << ", Column " << Column << endl;

		//cout << "Current row is " << Row << endl;
		//cout << "Current column is " << Column << endl;
		//cout << "The number of rows in the grid is " << NumberRows << endl;
		//cout << "The number of columns in the grid is " << NumberColumns << endl;
		*/
	}

//~~~~~~~~~~~~~~~~~~~
//END GAME LOOP HERE
//~~~~~~~~~~~~~~~~~~~

	/*
	//Testing room functions
	DescribePatio();
	cout << endl;
	DescribeBackyard1();
	cout << endl;
	DescribeBackyard2();
	cout << endl;
	DescribeLaundryRoom();
	cout << endl;
	DescribeDiningRoom();
	cout << endl;
	DescribeKitchen();
	cout << endl;
	DescribeDen();
	cout << endl;
	DescribeBedroom();
	cout << endl;
	DescribeBathroom();
	cout << endl;
	DescribeHallway1();
	cout << endl;
	DescribeHallway2();
	cout << endl;
	DescribeNursery();
	cout << endl;
	DescribeLivingRoom();
	cout << endl;
	DescribeFoyer();
	cout << endl;
	DescribeSidewalk();
	cout << endl;
	DescribeGarage();
	cout << endl;
*/

}

/*
Describe the room contents based on the int flag
	roomDesc-int defining room contents as a series of bit flags
	Row, Column-ints giving current row and column of room
*/

/*~~~~~~~~~~~~~~~~~~~~
Function Definitions
~~~~~~~~~~~~~~~~~~~~~~*/
//~~~~~~~~Take an Object~~~~~~~~
// Args:	rooms-2D array of unsigned int defining contents of all rooms
//			NumberRow-index of row of room player is now in
//			NumberColumn-index of column of room player is now in
//			Object-string naming the object the player wants to take
int TakeItem(unsigned int rooms[][4], int NumberRows, int NumberColumns, string Object)
{
	//Is player trying to take the Stack of DIAPERS?
	if ((Object == "DIAPERS") && (rooms[NumberRows][NumberColumns] & StackofDiapers))
	{
		rooms[NumberRows][NumberColumns] ^= StackofDiapers;	//Clears bit in this room using XOR(^)
		return StackofDiapers;	//Returns appropriate flag for this item
	}
	//Is player trying to take the Baby BOTTLE?
	else if ((Object == "BOTTLE") && (rooms[NumberRows][NumberColumns] & BabyBottle))
	{
		rooms[NumberRows][NumberColumns] ^= BabyBottle;
		return BabyBottle;
	}
	//Is player trying to take the WIPES?
	else if ((Object == "WIPES") && (rooms[NumberRows][NumberColumns] & Wipes))
	{
		rooms[NumberRows][NumberColumns] ^= Wipes;
		return Wipes;
	}
	//Is player trying to take FORMULA?
	else if ((Object == "FORMULA") && (rooms[NumberRows][NumberColumns] & Formula))
	{
		rooms[NumberRows][NumberColumns] ^= Formula;
		return Formula;
	}
	return 0;	//Didn't find object to TAKE so return zero
}
void BuildRooms(unsigned int rooms[][4])
{
	//~~~~~~~~Build rooms in the first row~~~~~~~~~
	//Build room 1-Patio
	rooms[0][0] = EastDoor | SouthDoor | Neighbor | FruitSnacks | FRIENDLY;
	//Build room 2-Backyard 1
	rooms[0][1] = EastDoor | WestDoor | Snake | BabySock | DANGEROUS;
	//Build room 3-Backyard 2
	rooms[0][2] = WestDoor | SimbaTheCat | DANGEROUS;
	//Build room 4-Laundry Room
	rooms[0][3] = SouthDoor | PileOfLaundry |  BabyBlanket | CAUTION;
	//~~~~~~~~Build rooms in the second row~~~~~~~~
	//Build room 5-Dining Room
	rooms[1][0] = NorthDoor | EastDoor | SouthDoor | BabyBottle;
	//Build room 6-Kitchen
	rooms[1][1] = EastDoor | SouthDoor | WestDoor | Formula;
	//Build room 7-Den
	rooms[1][2] = EastDoor | SouthDoor | WestDoor | RemoteControl | ScooterTheDog| FRIENDLY;
	//Build room 8-Bedroom
	rooms[1][3] = NorthDoor | SouthDoor | WestDoor | TheSandman | CoffeeCup| DEADLY;
	//~~~~~~~~Build rooms in the third row~~~~~~~~
	//Build room 9- Bathroom
	rooms[2][0] = EastDoor | ToiletPaper | SouthDoor | Booger | CAUTION;
	//Build room 10-Hallway 1
	rooms[2][1] = NorthDoor | EastDoor | SouthDoor | WestDoor | Wipes;
	//Build room 11-Hallway 2
	rooms[2][2] = NorthDoor | EastDoor | WestDoor;
	//Build room 12-Nursery
	rooms[2][3] = NorthDoor | WestDoor | StackofDiapers;
	//~~~~~~~~Build rooms in the fourth row~~~~~~~~
	//Build room 13-Living Room
	rooms[3][0] = NorthDoor | EastDoor | DustBunny | VacuumCleaner| CAUTION;
	//Build room 14-Foyer
	rooms[3][1] = NorthDoor | EastDoor | WestDoor | FeltBook;
	//Build room 15-Sidewalk
	rooms[3][2] = EastDoor | WestDoor;
	//Build room 16-Garage
	rooms[3][3] = WestDoor;
}
void DescribeRoomContents(int roomDesc, int Row, int Column)
{
	//Call appropriate function to describe room
	switch (Row)
	{
	case 0: //Handle Row 0
		switch (Column)
		{
		case 0: //Handle Column 0
			DescribePatio();
			break;
		case 1: //Handle Column 1
			DescribeBackyard1();
			break;
		case 2:	//Handle Column 2
			DescribeBackyard2();
			break;
		case 3: //Handle Column 3
			DescribeLaundryRoom();
			break;
		}
		break;	//Break from Case Row 0
	case 1:	//Row 1
		switch (Column)
		{
		case 0: //Handle Column 0
			DescribeDiningRoom();
			break;
		case 1: //Handle Column 1
			DescribeKitchen();
			break;
		case 2:	//Handle Column 2
			DescribeDen();
			break;
		case 3: //Handle Column 3
			DescribeBedroom();
			break;
		}
		break;	//Break from Case Row 1
	case 2: //Row 2
		switch (Column)
		{
		case 0: //Handle Column 0
			DescribeBathroom();
			break;
		case 1:	//Handle Column 1
			DescribeHallway1();
			break;
		case 2:	//Handle Column2
			DescribeHallway2();
			break;
		case 3:	//Handle Column 3
			DescribeNursery();
			break;
		}
		break; //Break from Case Row 2
	case 3: //Row 3
		switch (Column)
		{
		case 0: //Handle Column 0
			DescribeLivingRoom();
			break;
		case 1:	//Handle Column 1
			DescribeFoyer();
			break;
		case 2: //Handle Column 2
			DescribeSidewalk();
			break;
		case 3: //Handle Column 3
			DescribeGarage();
			break;
		}
		break;	//Break from Case Row 3
	}
	//Creatures
	if (roomDesc&DustBunny)
		cout << "You see a Dust Bunny hiding in the corner of the room." << endl;
	if (roomDesc&Booger)
		cout << "You see a Booger in the middle of the floor." << endl;
	if (roomDesc&ScooterTheDog)
		cout << "You see Scooter, your dog, wagging his tail happily while looking at you." << endl;
	if (roomDesc&Neighbor)
		cout << "You see your Neighbor and decide to say hello." << endl;
	if (roomDesc&PileOfLaundry)
		cout << "You see a Pile of Laundry. You feels like it is glaring at you." << endl;
	if (roomDesc&SimbaTheCat)
		cout << "You see Simba, your cat, and it appears that it is trying to kill you." << endl;
	if (roomDesc&TheSandman)
		cout << "You see the Sandman. He attempts to lull you into a deep sleep." << endl;
	if (roomDesc&Snake)
		cout << "You see a snake. A shiver runs down your spine." << endl;
	//Creature Danger Check
	if (roomDesc&DEADLY)
		cout << "This creature is deadly. RUN." << endl;
	if (roomDesc&DANGEROUS)
		cout << "This creature is dangerous. Be very careful." << endl;
	if (roomDesc&CAUTION)
		cout << "This creature could be dangerous." << endl;
	if (roomDesc&FRIENDLY)
		cout << "This creature is friendly or harmless." << endl;
	//Takeable Items (Not Treasure Items)
	if (roomDesc&RemoteControl)
		cout << "You see a remote control." << endl;
	if (roomDesc&FruitSnacks)
		cout << "You see a pack of fruit snacks." << endl;
	if (roomDesc&VacuumCleaner)
		cout << "You see a vacuum cleaner." << endl;
	if (roomDesc&BabyBlanket)
		cout << "You see a baby blanket." << endl;
	if (roomDesc&FeltBook)
		cout << "You see a child's felt book." << endl;
	if (roomDesc&ToiletPaper)
		cout << "You see a roll of toilet paper." << endl;
	if (roomDesc&CoffeeCup)
		cout << "You see a coffee cup." << endl;
	if (roomDesc&BabySock)
		cout << "You see a tiny baby sock." << endl;
	//Treasure Items
	if (roomDesc&StackofDiapers)
		cout << "You see a stack of diapers." << endl;
	if (roomDesc&BabyBottle)
		cout << "You see an empty baby bottle." << endl;
	if (roomDesc&Wipes)
		cout << "You see a pack of wipes." << endl;
	if (roomDesc&Formula)
		cout << "You see a can of baby formula." << endl;
	//Check the Doors
	if (roomDesc&NorthDoor)
		cout << "There is a door to the north." << endl;
	if (roomDesc&EastDoor)
		cout << "There is a door to the east." << endl;
	if (roomDesc&SouthDoor)
		cout << "There is a door to the south." << endl;
	if (roomDesc&WestDoor)
		cout << "There is a door to the west." << endl;
}

//Name of room, description, items other than takeables, people/creatures other than list
void DescribePatio()
{
	cout << "You are on the patio. You step out onto the wooden floor and see a grill\nto your left.";
	cout << " A large oak tree gives a lovely shade over the patio." << endl;
}
void DescribeBackyard1()
{
	cout << "You are in the backyard. A bright red swing set sits in the middle of the yard." << endl;
	cout << "You can't wait until the baby is old enough to play on the swings." << endl;
}
void DescribeBackyard2()
{
	cout << "You are in the backyard. The shed sits near the fence. A sense of dread" << endl;
	cout << "fills you as you remember that you need to mow the yard." << endl;
}
void DescribeLaundryRoom()
{
	cout << "You are in the laundry room. The room is small but fits both a washing\nmachine and a dryer." << endl;
}
void DescribeDiningRoom()
{
	cout << "You are in the dining room. A large table sits in the middle of the room." << endl;
	cout << "An artificial tree sits in the corner of the room." << endl;
}
void DescribeKitchen()
{
	cout << "You are in the kitchen. You see dark marble countertops that perfectly" << endl;
	cout << "complement the blue backsplash. An medium-sized island is fixed in the\nmiddle of the room." << endl;
}
void DescribeDen()
{
	cout << "You are in the den. Your favorite piece of furniture, the suede couch, sits" << endl;
	cout << "against the wall. It seems to call for you to sit down. A 60-inch" << endl;
	cout << "television is mounted on the wall to your left." << endl;
}
void DescribeBedroom()
{
	cout << "You are in the bedroom. Your California king-sized bed is in the middle" << endl;
	cout << "of the room. Six frilly throw pillows decorate the bed.\nAlso on the bed is your spouse, still asleep." << endl;
}
void DescribeBathroom()
{
	cout << "You are in the bathroom. The jacuzzi tub reminds you of your evening" << endl;
	cout << "plans to relax. You also see the training potty beside the toilet.\nPotty training sounds like a hassle." << endl;
}
void DescribeHallway1()
{
	cout << "You are in the hallway. Family photos line the wall on both sides." << endl;
}
void DescribeHallway2()
{
	cout << "You are in the hallway. Family photos line the wall on both sides." << endl;
}
void DescribeNursery()
{
	cout << "You are in the nursery. The baby blue walls are beautiful and recall some" << endl;
	cout << "wonderful memories of bringing your baby home for the first time." << endl;
}
void DescribeLivingRoom()
{
	cout << "You are in the living room. This area isn't as homey as the den due to the" << endl;
	cout << "fact there is no television in this room." << endl;
}
void DescribeFoyer()
{
	cout << "You are in the foyer. You see a coat rack to your left. Shoes are piled\nunderneath the jackets." << endl;
}
void DescribeSidewalk()
{
	cout << "You are on the sidewalk outside your house. Grass is trying to grow" << endl;
	cout << "into the cracks of the concrete. It is a gorgeous sunny day." << endl;
}
void DescribeGarage()
{
	cout << "You are in the garage. Your car sits idle and the garage door is open." << endl;
	cout << "Various sports equipment and automotive tools line the walls on three sides." << endl;
}