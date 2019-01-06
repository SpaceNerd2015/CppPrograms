/*
CS 121 Programming Assignment 3
File: Program3Main.cpp
Author: Hayley Andrews
Description: Option 1 (ICAO Translating)
Date: April 6, 2017

I attest that this program is entirely my own work.
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//~~~~~~~~Intializing Variables~~~~~~~~
string code[26];
string choice;

//~~~~~~~~Function Prototypes~~~~~~~~
void BuildCodeArray(string code[]);
void TranslateString(string code[], char sInput[100]);

//~~~~~~~~Main Function~~~~~~~~
int main()
{
		BuildCodeArray(code);

	do
	{
		char sInput[100] = {};
		cout << "Enter a word or phrase to be translated into ICAO Phonetics." << endl;
		cin.getline(sInput, 100);

		for (int i = 0;i < strlen(sInput);i++)
		{
			sInput[i] = toupper(sInput[i]);
		}

		TranslateString(code, sInput);
		cout << endl << endl;

		//Prompts user to either continue or quit
		cout << "Would you like to translate another phrase? (yes/no)" << endl;
		cin >> choice;

		cin.ignore();

	} while (choice == "yes");

}

//~~~~~~~~Function Definitions~~~~~~~~
void BuildCodeArray(string code[])
{
	code[0] = "Alpha";
	code[1] = "Bravo";
	code[2] = "Charlie";
	code[3] = "Delta";
	code[4] = "Echo";
	code[5] = "Foxtrot";
	code[6] = "Golf";
	code[7] = "Hotel";
	code[8] = "India";
	code[9] = "Juliet";
	code[10] = "Kilo";
	code[11] = "Lima";
	code[12] = "Mike";
	code[13] = "November";
	code[14] = "Oscar";
	code[15] = "Papa";
	code[16] = "Quebec";
	code[17] = "Romeo";
	code[18] = "Sierra";
	code[19] = "Tango";
	code[20] = "Uniform";
	code[21] = "Victor";
	code[22] = "Whiskey";
	code[23] = "X-Ray";
	code[24] = "Yankee";
	code[25] = "Zulu";
}

void TranslateString(string code[26], char sInput[100])
{
	for (int i = 0;i < strlen(sInput);i++)
	{
		switch (sInput[i])
		{
		case 'A':
			cout << code[0] <<" ";
			break;
		case 'B':
			cout << code[1] << " ";
			break;
		case 'C':
			cout << code[2] << " ";
			break;
		case 'D':
			cout << code[3] << " ";
			break;
		case 'E':
			cout << code[4] << " ";
			break;
		case 'F':
			cout << code[5] << " ";
			break;
		case 'G':
			cout << code[6] << " ";
			break;
		case 'H':
			cout << code[7] << " ";
			break;
		case 'I':
			cout << code[8] << " ";
			break;
		case 'J':
			cout << code[9] << " ";
			break;
		case 'K':
			cout << code[10] << " ";
			break;
		case 'L':
			cout << code[11] << " ";
			break;
		case 'M':
			cout << code[12] << " ";
			break;
		case 'N':
			cout << code[13] << " ";
			break;
		case 'O':
			cout << code[14] << " ";
			break;
		case 'P':
			cout << code[15] << " ";
			break;
		case 'Q':
			cout << code[16] << " ";
			break;
		case 'R':
			cout << code[17] << " ";
			break;
		case 'S':
			cout << code[18] << " ";
			break;
		case 'T':
			cout << code[19] << " ";
			break;
		case 'U':
			cout << code[20] << " ";
			break;
		case 'V':
			cout << code[21] << " ";
			break;
		case 'W':
			cout << code[22] << " ";
			break;
		case 'X':
			cout << code[23] << " ";
			break;
		case 'Y':
			cout << code[24] << " ";
			break;
		case 'Z':
			cout << code[25] << " ";
			break;
		default:
			break;
		}
	}
}

