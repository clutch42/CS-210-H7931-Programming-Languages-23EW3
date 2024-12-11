/*
 * Calculator.cpp
 *
 *  Date: 1/13/2023
 *  Author: Brian Engel
 */

#include <iostream>

using namespace std;

int main() {  // changed return type to int and moved {
	// char statement[100]; not sure what this is for
	int op1, op2;
	char operation;
	char answer = 'Y';  // added semicolon, changed double quotes to single quotes since its a char
	while (answer == 'y' || answer == 'Y')	{	// added condition for 'Y', moved {
		cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2;		// switched int inputs so output would be consistent
		if (operation == '+') {		// changed double quotes to single quotes, got rid of ;, added {
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;  // changed >> to <<
		}	// added }
		if (operation == '-') {		// got rid of ;, added {
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;	// changed >> to <<
		}	// added }
		if (operation == '*') {		// added {
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;	// added semicolon, changed / to *
		}	// added }
		if (operation == '/') {		// added {
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;	// changed * to /
		}		// added }
			
		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}
	cout << "Program finished.";	// added this to complete project requirements
}

