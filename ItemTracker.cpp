// Brian Engel
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "ItemTracker.h"

void ItemTracker::getUserFile(const string& fileName) { // function to read items sold from a file
    ifstream itemInput; // input file stream variable
    string item;        // temporary variable for reading item

    itemInput.open(fileName);   // open file

    if (!itemInput.is_open()) {     // if file didn't open output could not open
        cout << "Could not open file " << fileName << endl;
    }
    else {      // if the file opened
        while (!itemInput.eof()) {      // while it is not the end of file
            itemInput >> item;          // item = value of the line in file
            if (this->itemsSold.count(item) == 0) { // if item is not a key in the map
                this->itemsSold.emplace(item, 1);   // make item key in map with value of 1
            }
            else {                              // if item is a key in the map
                this->itemsSold.at(item) += 1;  // add 1 to the value of the key
            }
        }
        itemInput.close();      // close the file
    }
}

// function to print map keys and values as integer
void ItemTracker::printAllNumericQuantities() {

    vector<string> keys;    // vector to store all the key values in the map
    for (auto it = this->itemsSold.begin(); it != this->itemsSold.end(); ++it) {    // loop through all keys
        keys.push_back(it->first);  // add key to vector
    }

    for (const auto& key : keys) {  // loop through vector of keys
        cout << setw(60) << key << " " << this->itemsSold.at(key) << endl; // output key and integer value
    }

}

// function to print map keys and values as histogram
void ItemTracker::printHistogram() {

    vector<string> keys;    // vector to store all the key values in the map
    for (auto it = this->itemsSold.begin(); it != this->itemsSold.end(); ++it) {    // loop through all keys
        keys.push_back(it->first);  // add key to vector
    }

    for (const auto& key : keys) {  // loop through vector of keys
        cout << setw(60) << key << " "; // output key
        for (int i = 0; i < this->itemsSold.at(key); ++i) { // print * for integer value
            cout << "*";
        }
        cout << endl;
    }

}

// function to search for specific item and print quantity
void ItemTracker::searchForItem() {
    string userInput;   // variable for user input
    cout << setw(60) << "Enter item to search for: ";
    getline(cin, userInput);    // get user input
    if (this->itemsSold.count(userInput) == 0) {    // if user input is not found in map
        cout << setw(60) << "Item not found" << endl;
    }
    else {  // if user input is found in map
        cout << setw(60) << "Quantity: " << this->itemsSold.at(userInput) << endl; // print value of key user input
    }
}

// function to write key and value as integer to file
void ItemTracker::backupItems(const string& fileName) {
    ofstream outFS; // output file stream variable
    vector<string> keys;    // vector for keys

    outFS.open(fileName);   // open file

    if (!outFS.is_open()) {     // if file didn't open output could not open
        cout << "Could not open file " << fileName << endl;
    }

    for (auto it = this->itemsSold.begin(); it != this->itemsSold.end(); ++it) {    // loop through all keys
        keys.push_back(it->first);  // add key to vector
    }

    for (const auto& key : keys) {  // loop through vector of keys
        outFS << key << " " << this->itemsSold.at(key) << endl; // write key and value to file
    }

    outFS.close();     // close the file
}