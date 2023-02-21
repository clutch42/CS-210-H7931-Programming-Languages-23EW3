// Brian Engel

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>

#include "ItemTracker.h"

using namespace std;

// declarations for functions not in the class

char enterChar(string message = "");
void printMenu();
void clearScreen(int j);
void menuLoop(ItemTracker cornerGrocer);
string printChar(char character, int numberOfTimes);

// definitions for functions not in the class
// 
// function to take in string, print it, get char from user, and return it
char enterChar(string message) {
	cout << message;		// user can send string as parameter to print
	char temp = _getch();	// takes input without having to hit enter
	return temp;			// return the char
}

// function for the menu loop
void menuLoop(ItemTracker cornerGrocer) {
	char quit = ' ';			// variable for quiting program
	while (quit != '4') {		// while loop to continue until user enters '4'
		printMenu();			// print the menu
		clearScreen(13);		// for centering menu vertically
		quit = enterChar();		// get user input for menu
		if (quit == '2') {		// if user enters 2
			cornerGrocer.printAllNumericQuantities();	// print numeric quantities
			enterChar("Press any key to continue");		// pause to see results
		}
		else if (quit == '3') {	// if user enters 3
			cornerGrocer.printHistogram();				// print histogram quantities
			enterChar("Press any key to continue");		// pause to see results
		}
		else if (quit == '1') {	// if user enters 1
			clearScreen(20);							// vertical spacing
			cornerGrocer.searchForItem();				// search for specific item
			clearScreen(13);							// vertical spacing
			enterChar("Press any key to continue");		// pause to see results
		}
		else if (quit == '4') {	// if user enters 4
			cout << "Exiting Program" << endl;			// print exiting program
		}
	}
}
// function to print menu
void printMenu() {
	clearScreen(14);
	cout << printChar(' ', 40) << "Corner Grocer Item Tracker" << endl << endl;
	cout << printChar(' ', 40) << "1. Search for Item" << endl;
	cout << printChar(' ', 40) << "2. Print All Items with Numerical Quantity" << endl;
	cout << printChar(' ', 40) << "3. Print Histogram" << endl;
	cout << printChar(' ', 40) << "4. Quit" << endl;
}

// function to print newlines parameter j times
void clearScreen(int j) {
	for (int i = 0; i < j; ++i) {
		cout << endl;
	}
}

// function to return string of parameter character * parameter numberOfTimes
string printChar(char character, int numberOfTimes) {
	string temp = "";
	for (int i = 0; i < numberOfTimes; ++i) {
		temp += character;
	}
	return temp;
}

int main() {
	ItemTracker cornerGrocer;		// create object of ItemTracker
	string readFileName = "CS210_Project_Three_Input_File.txt";	// variable for input file
	string writeFileName = "frequency.dat";						// variable for output file
	cornerGrocer.getUserFile(readFileName);		// read in input file
	cornerGrocer.backupItems(writeFileName);	// write output file
	menuLoop(cornerGrocer);						// menu for user to access information

	return 0;
}