// Brian Engel

#include <iostream>     // for input output
#include <string>       // for using strings
#include <vector>       // for using vectors

using namespace std;    // don't have to type std:: 

class TimeClock {       // Class to contain all variables and functions for the timeclock
    private:                               // private variables
        vector<int> timeInts{0, 0, 0};     // vector to hold hours, minutes, and seconds
        string timeString;                 // string for the time

    private:                               // private functions
        string formatDigits(int timeInt) {      // function that takes an int and returns the number as a 2 digit string 
            if (timeInt < 10) {                 // if int is only 1 digit return string with 0 in front
                return "0" + to_string(timeInt);
            }
            else {                              // if int is 2 digit return as string
                return to_string(timeInt);
            }
        }

        string format24Hours(vector<int> timeInts) {    // function to format the vector of ints to a string in 24 hour format
            string tempTimeString = "";                 // string to create time
            for (int i = 0; i < 3; ++i) {               // loop through each element of vector
                tempTimeString += formatDigits(timeInts.at(i));     // string gets element turned to string
                if (i < 2) {                            // if it is not on the last element insert a : in string
                    tempTimeString += ":";
                }
            }
            return tempTimeString;                      
        }

        string format12Hours(vector<int> timeInts) {    // function to format the vector of ints to a string in 12 hour format
            string tempTimeString = "";                 // string to create time
            if (timeInts.at(0) > 12) {                  // if hour is greater than 12 subtract 12 and add to string
                tempTimeString += formatDigits(timeInts.at(0) - 12);
            }
            else {
                tempTimeString += formatDigits(timeInts.at(0));
            }
            tempTimeString += ":" + formatDigits(timeInts.at(1));   // add : and minutes to string
            tempTimeString += ":" + formatDigits(timeInts.at(2));   // add : and seconds to string
            if (timeInts.at(0) > 12) {                              // if hour is greater than 12 add pm to string else add am
                tempTimeString += " P M";
            }
            else {
                tempTimeString += " A M";
            }
            return tempTimeString;
        }

        string createCharString(char character, int number) {       // function to create a string of chars that is number long
            string temp;
            for (int i = 0; i < number; ++i) {
                temp += character;
            }
            return temp;
        }

        void clearScreen() {                        // function to clear screen by printing newlines
            for (int i = 0; i < 40; ++i) {
                cout << endl;
            }
        }

        void incHour() {                    // function to increment hour
            ++timeInts.at(0);               // increment vector at hours
            if (timeInts.at(0) > 23) {      // if hours is greater than 23 subtract 24 from hours
                timeInts.at(0) -= 24;
            }
        }

        void incMinutes() {                 // function to increment minutes
            ++timeInts.at(1);               // increment vector at minutes
            if (timeInts.at(1) > 59) {      // if minutes is greater than 59 subtract 60 from minutes and increment hour
                timeInts.at(1) -= 60;
                incHour();                  
            }
        }

        void incSeconds() {                 // function to increment seconds
            ++timeInts.at(2);               // increment vector at seconds
            if (timeInts.at(2) > 59) {      // if seconds is greater than 59 subtract 60 from seconds and increment minute
                timeInts.at(2) -= 60;
                incMinutes();
            }
        }
    public:                 // public functions

        TimeClock() {       // constructor with no parameters (sets default vector {0, 0, 0}

        }

        TimeClock(vector<int> tempVector) {     // constructor with parameter for vector
            timeInts = tempVector;              // sets vector to argument passed
        }

        bool getUserInput() {                   // function for getting user input
            char userInput;                     // variable for user input
            cin >> userInput;                   // input for variable
            if (userInput == '1') {             // if input is 1 incHour() and return true to continue
                incHour();
                return true;
            }
            else if (userInput == '2') {        // if input is 2 incMinutes() and return true to continue
                incMinutes();
                return true;
            }
            else if (userInput == '3') {        // if input is 3 incSeconds() and return true to continue
                incSeconds();
                return true;
            }
            else if (userInput == '4') {        // if input is 4 return false to exit program
                return false;
            }
            else {                              // if input is anything else output invalid input and get input again
                cout << "Invalid Input" << endl;
                getUserInput();
            }
        }

        void printClock() {     // function to print the clocks
            clearScreen();      
            cout << endl << endl;
            cout << createCharString(' ', 6) << createCharString('*', 27) << createCharString(' ', 6) << createCharString('*', 27) << endl;
            cout << createCharString(' ', 6) << createCharString('*', 1) << createCharString(' ', 6) << "12-Hour Clock" << createCharString(' ', 6) << createCharString('*', 1);
            cout << createCharString(' ', 6) << createCharString('*', 1) << createCharString(' ', 6) << "24-Hour Clock" << createCharString(' ', 6) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 6) << createCharString('*', 1) << createCharString(' ', 7) << format12Hours(timeInts) << createCharString(' ', 6) << createCharString('*', 1);
            cout << createCharString(' ', 6) << createCharString('*', 1) << createCharString(' ', 9) << format24Hours(timeInts) << createCharString(' ', 8) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 6) << createCharString('*', 27) << createCharString(' ', 6) << createCharString('*', 27) << endl;
            cout << endl << endl;
        }

        void printMenu() {         // function to print menu
            cout << endl << endl;
            cout << createCharString(' ', 22) << createCharString('*', 27) << endl;
            cout << createCharString(' ', 22) << createCharString('*', 1) << createCharString(' ', 1) << "1 - Add One Hour" << createCharString(' ', 8) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 22) << createCharString('*', 1) << createCharString(' ', 1) << "2 - Add One Minute" << createCharString(' ', 6) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 22) << createCharString('*', 1) << createCharString(' ', 1) << "3 - Add One Second" << createCharString(' ', 6) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 22) << createCharString('*', 1) << createCharString(' ', 1) << "4 - Exit Program" << createCharString(' ', 8) << createCharString('*', 1) << endl;
            cout << createCharString(' ', 22) << createCharString('*', 27) << endl;
            cout << endl << endl;
        }
};

int main() {
    bool cont = true;                           // bool variable for continuing the program
    TimeClock centralTime;                      // object of class TimeClock

    while (cont) {                              // while loop to continue until cont is false
        centralTime.printClock();               // print clock
        centralTime.printMenu();                // print menu
        cont = centralTime.getUserInput();      // get user input
    }
}

