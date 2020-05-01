//Contributors: Jacob Myers, Justin Marko
//File Purpose: Definitions for generalized input funcitons

#include "GPROFinal/input.h"
using namespace std;

//Gets an integer from the user given a prompt and returns it
int getIntFromUser(string prompt)
{
	int inpt;
	cout << prompt;
	cin >> inpt;
	return inpt;
}

//Gets a string from the user given a prompt and returns it
string getStringFromUser(string prompt)
{
	string inpt;
	cout << prompt;
	cin >> inpt;
	return inpt;
}