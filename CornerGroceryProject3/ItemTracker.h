// Brian Engel

#ifndef ITEM_TRACKER_H				// check to see if ITEM_TRACKER_H has been defined yet
#define ITEM_TRACKER_H

#include <string>
#include <map>

using namespace std;

// class definition
class ItemTracker {
private:		// private attributes
	map<string, int> itemsSold;	// variable to hold name and quantity
public:			// public attributes
	void getUserFile(const string& fileName);	// function to read items sold from a file
	void printAllNumericQuantities();			// function to print map keys and values as integer
	void printHistogram();						// function to print map keys and values as histogram
	void searchForItem();						// function to search for specific item and print quantity
	void backupItems(const string& fileName);	// function to write key and value as integer to file
};

#endif
