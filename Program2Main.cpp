/*
CS 121 Programming Assignment 2
File: Program2Main.cpp
Author: Hayley Andrews
Description: Option 1--User enters weight and the program prints the weight 
						of the user on a desired planet
Date: 3/8/17

I attest that this program is entirely my own work
*/

#include <iostream>
#include <string>
using namespace std;

//Initialization of variables
float weight, newweight;
string planet;
string choice;

//Weight Factors
float Mercury = 0.4155f, Venus = 0.8975f, Earth = 1.0f;
float Moon = 0.166f, Mars = 0.3507f, Jupiter = 2.5374f;
float Saturn = 1.0677f, Uranus = 0.8947f, Neptune = 1.1794f;
float Pluto = 0.0899f;

int main()
{
	//Do-while loop enables user to check weight again
	//and runs at least once without saying "yes" to the choice
	do
	{
		//User enters weight and program reads it in
		cout << "Enter your weight in pounds. ";
		cout << "Example: 185.7" << endl;
		cin >> weight;

		//User enters planet name and program reads it in
		cout << "Enter the desired planet or moon from the following:" << endl;
		cout << "Mercury\tVenus\tEarth\tMoon\tMars\n";
		cout << "Jupiter\tSaturn\tUranus\tNeptune\tPluto\n";
		cin >> planet;

		//Calculates and prints new weight based on planet chosen
		if (planet == "Mercury")
		{
			newweight = weight*Mercury;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Venus")
		{
			newweight = weight*Venus;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Earth")
		{
			newweight = weight*Earth;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Moon")
		{
			newweight = weight*Moon;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Mars")
		{
			newweight = weight*Mars;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Jupiter")
		{
			newweight = weight*Jupiter;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Saturn")
		{
			newweight = weight*Saturn;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Uranus")
		{
			newweight = weight*Uranus;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Neptune")
		{
			newweight = weight*Neptune;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else if (planet == "Pluto")
		{
			newweight = weight*Pluto;
			cout << "Your weight on " << planet << " is " << newweight << "." << endl;
		}
		else
		{
			cout << "Please enter a valid planet name from the list." << endl;
		}

		//Asks user if they would like to check weight on another planet
		cout << "Would you like to check another weight? (yes/no)" << endl;
		cin >> choice;

	} while (choice == "yes");
}
