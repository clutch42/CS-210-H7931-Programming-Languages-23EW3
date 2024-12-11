// Brian Engel

#include <iostream>
#include "BankCustomer.h"
using namespace std;

int main() {
	char quit = ' ';			// variable for quiting program
	while (quit != 'q') {		// while loop to continue until user enters 'q'
		BankCustomer customer1;		// instance of class BankCustomer
		customer1.getInput();		// get the input from user
		quit = customer1.printResults();	// output results and see if user wants to continue
	}

	return 0;
}