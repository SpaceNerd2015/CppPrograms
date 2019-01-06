/*
CS 121 Programming Assignment 1
File: Program1Main.cpp
Author: Hayley Andrews
Description: Option 1 (Potential Team Arrangments/Permutations)
Date: February 23, 2017

I attest that this program is entirely my own work.
*/

#include <iostream>
#include <math.h>
using namespace std;

//Initialize Variables
double n = 18.0, r = 3.0, y;						// 18 people, 3 spots to fill on team, y=(n-r)
double factr=3.0, factn=18.0, factnminusr=15.0;		// Factorial values for r!, n!, and (n-r)! and initialization
double perm;										// Permutation (Number of Team Arrangements)

int main()
{
	y = n - r;		// y is the variable that describes n-r

	//Factorial Functions
	// n!
	while (n > 2.0)
	{
		factn = factn*(n - 1.0);
		n = n - 1.0;
	}

	// r!
	while (r > 2.0)
	{
		factr = factr*(r - 1.0);
		r = r - 1.0;
	}
	
	// (n-r)! labeled as y!
	while (y > 2.0)
	{
		factnminusr = factnminusr*(y - 1.0);
		y = y - 1.0;
	}

	perm = factn / ((factr)*(factnminusr));
	cout << "The number of potential team arrangments is " << perm << endl;

}