#include "GPROFinal/input.h"
using namespace std;

int getIntFromUser(string prompt)
{
	int inpt;
	cout << prompt;
	cin >> inpt;
	return inpt;
}

string getStringFromUser(string prompt)
{
	string inpt;
	cout << prompt;
	cin >> inpt;
	return inpt;
}