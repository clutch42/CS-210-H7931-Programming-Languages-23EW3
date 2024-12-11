// Brian Engel

#include <iostream>
#include <conio.h>
#include <iomanip>
#include "BankCustomer.h"
using namespace std;

// function for printing specific # of chars
// loop through num times and add character to the temp string each time, then return the string
string BankCustomer::numOfChars(int num, char character) {
	string temp = "";
	for (int i = 0; i < num; ++i) {		
		temp += character;
	}
	return temp;
}

// function to set investment from user input and validate it
void BankCustomer::setInvestment() {
		cin >> investment;
		if (!cin || !(investment > 0)) {		// validation - if error on cin or investment is not positive
			cout << "Invalid Input" << endl;	// output error
			cin.clear();						// clear cin error
			cin.ignore(1000, '\n');				// clear cin
			setInvestment();					// call the function again
		}
}

// function to set investment from in the program
void BankCustomer::setInvestment(double& newAmount) {		
	investment = newAmount;
}

// function to return investment
double BankCustomer::getInvestment() {
	return investment;
}

// function to set monthlyDeposit from user input and validate it
void BankCustomer::setMonthlyDeposit() {
	cin >> monthlyDeposit;
	if (!cin) {								// validation - if error on cin
		cout << "Invalid Input" << endl;	// output error
		cin.clear();						// clear cin error
		cin.ignore(1000, '\n');				// clear cin
		setMonthlyDeposit();				// call the function again
	}
}

// function to return monthlyDeposit
double BankCustomer::getMonthlyDeposit() {
	return monthlyDeposit;
}

// function to set annualInterest from user input and validate it
void BankCustomer::setAnnualInterest() {
	cin >> annualInterest;
	if (!cin) {								// validation - if error on cin
		cout << "Invalid Input" << endl;	// output error
		cin.clear();						// clear cin error
		cin.ignore(1000, '\n');				// clear cin
		setAnnualInterest();				// call the function again
	}
}

// function to return annualInterest
double BankCustomer::getAnnualInterest() {
	return annualInterest;
}

// function to set numberOfYears from user input and validate it
void BankCustomer::setNumberOfYears() {
	cin >> numberOfYears;
	if (!cin) {								// validation - if error on cin
		cout << "invalid input" << endl;	// output error
		cin.clear();						// clear cin error
		cin.ignore(1000, '\n');				// clear cin
		setNumberOfYears();					// call the function again
	}
}

// function to return numberOfYears
int BankCustomer::getNumberOfYears() {
	return numberOfYears;
}

// function to take in string, print it, get char from user, and return it
char BankCustomer::enterChar(string message) {
	cout << message;
	char temp = _getch();	// takes input without having to hit enter
	return temp;
}

// function to get user input for all variables
void BankCustomer::getInput() {
	cout << numOfChars(80, '*') << endl;		// output to terminal
	cout << numOfChars(34, '*') << " Data Input " << numOfChars(34, '*') << endl;		// output to terminal
	cout << "Initial Investment Amount: ";		// output to terminal
	setInvestment();							// set the investment amount
	cout << "Monthly Deposit: ";			
	setMonthlyDeposit();						// set the monthly deposit amount
	cout << "Annual Interest: ";
	setAnnualInterest();						// set the annual interest amount
	cout << "Number of years: ";
	setNumberOfYears();							// set the number of years
	enterChar("Press any key to continue");		// pause screen to review inputs until user hits a key
	clearScreen();								// clear the screen
}

// function to output for if there is a monthly deposit
void BankCustomer::printWithDeposit() {
	cout << setw(80) << "Balance and Interest With Additional Monthly Deposits             " << endl;
}

// function to output for if there is not a monthly deposit
void BankCustomer::printWithoutDeposit() {
	cout << setw(80) << "Balance and Interest Without Additional Monthly Deposits            " << endl;
}

// calculates the new balance for 1 month and saves it as investment, and returns the interest accumulated for month
double BankCustomer::calculateOneMonth() {
	double tempBalance;				// variable for tempBalsnce
	double tempMonthlyInterest;		// variable for tempMonthlyInterest
	tempBalance = getInvestment() + getMonthlyDeposit();	// tempBalance = investment + monthly deposit
	tempMonthlyInterest = tempBalance * getAnnualInterest() / 12 / 100;		// temp interest = tempBalance * monthly interest rate
	tempBalance += tempMonthlyInterest;		// tempBalance added with tempMonthlyInterest
	setInvestment(tempBalance);				// update the original investment amount
	return tempMonthlyInterest;				// return the tempMonthlyInterest
}

// function to calculate and print results and return user char for continue or not
char BankCustomer::printResults() {
	double tempMonthlyInterest = 0;		// variable for monthly interest
	if (monthlyDeposit == 0) {			// if statement to print different heading for with or without monthly deposit
		printWithoutDeposit();
	}
	else {
		printWithDeposit();
	}
	cout << numOfChars(80, '=') << endl;	// output to terminal
	cout << setw(10) << "Year" << setw(35) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;		// output to terminal
	cout << numOfChars(80, '-') << endl;		// output to terminal
	for (int i = 1; i <= 12 * getNumberOfYears(); ++i) {	// for loop to run calculateOneMonth for each month and save interest to temp interest
		tempMonthlyInterest += calculateOneMonth();
		if (i % 12 == 0) {		// if i is 12 (one year) print the results
			cout << fixed << setprecision(2) <<setw(10) << i / 12 << setw(35) << getInvestment() << setw(35) << tempMonthlyInterest << endl;
			tempMonthlyInterest = 0; // reset temp monthly interest for next year
		}
	}
	return enterChar("Press q to quit or any other key to continue\n"); // user hits q to quit or anything else to continue and returns the char to main
}

// function to output newlines to clear the screen
void BankCustomer::clearScreen() {
	for (int i = 0; i < 40; ++i) {
		cout << "\n";
	}
}
