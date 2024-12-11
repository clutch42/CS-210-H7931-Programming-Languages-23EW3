// Brian Engel

#ifndef BANK_CUSTOMER_H				// check to see if BANK_CUSTOMER_H has been defined yet
#define BANK_CUSTOMER_H

#include <string>
using namespace std;

class BankCustomer {
private:		// private attributes
	double investment = 0.0;		// variable for the investment amount
	double monthlyDeposit = 0.0;	// variable for amount of monthly deposit
	double annualInterest = 0.0;	// variable for interest rate
	int numberOfYears = 0;			// variable for number of years

	string numOfChars(int num, char character);		// function for printing specific # of chars
	void setInvestment();							// function to set investment from user input and validate it
	void setInvestment(double& newAmount);			// function to set investment from in the program
	double getInvestment();							// function to return investment
	void setMonthlyDeposit();						// function to set monthlyDeposit from user input and validate it
	double getMonthlyDeposit();						// function to return monthlyDeposit
	void setAnnualInterest();						// function to set annualInterest from user input and validate it
	double getAnnualInterest();						// function to return annualInterest
	void setNumberOfYears();						// function to set numberOfYears from user input and validate it
	int getNumberOfYears();							// function to return numberOfYears
	char enterChar(string message);					// function to take in string, print it, get char from user, and return it
	void printWithDeposit();						// function to output for if there is a monthly deposit
	void printWithoutDeposit();						// function to output for if there is not a monthly deposit
	void clearScreen();								// function to output newlines to clear the screen
	double calculateOneMonth();						// calculates the new balance for 1 month and saves it as investment, and returns the interest accumulated for month

public:
	void getInput();								// function to get user input for all variables
	char printResults();							// function to calculate and print results and return user char for continue or not
};

#endif