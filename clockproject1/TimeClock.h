// Brian Engel

#include <iostream>
#include <string>

#include <vector>
using namespace std;

class TimeClock {
private:
    vector<int> timeInts{ 0, 0, 0};
    string timeString;

private:
    string formatDigits(int timeInt) {};

    string format24Hours(vector<int> timeInts) {
        string tempTimeString = "";
        for (int i = 0; i < 3; ++i) {
            tempTimeString += formatDigits(timeInts.at(i));
            if (i < 2) {
                tempTimeString += ":";
            }
        }
        return tempTimeString;
    }

    string format12Hours(vector<int> timeInts) {
        string tempTimeString = "";
        if (timeInts.at(0) > 12) {
            tempTimeString += formatDigits(timeInts.at(0) - 12);
        }
        else {
            tempTimeString += formatDigits(timeInts.at(0));
        }
        tempTimeString += ":" + formatDigits(timeInts.at(1));
        tempTimeString += ":" + formatDigits(timeInts.at(2));
        if (timeInts.at(0) > 12) {
            tempTimeString += " P M";
        }
        else {
            tempTimeString += " A M";
        }
        return tempTimeString;
    }

    string createCharString(char character, int number) {
        string temp;
        for (int i = 0; i < number; ++i) {
            temp += character;
        }
        return temp;
    }

    void clearScreen() {
        for (int i = 0; i < 40; ++i) {
            cout << endl;
        }
    }

    void incHour() {
        ++timeInts.at(0);
        if (timeInts.at(0) > 23) {
            timeInts.at(0) -= 24;
        }
    }

    void incMinutes() {
        ++timeInts.at(1);
        if (timeInts.at(1) > 59) {
            timeInts.at(1) -= 60;
            incHour();
        }
    }

    void incSeconds() {
        ++timeInts.at(2);
        if (timeInts.at(2) > 59) {
            timeInts.at(2) -= 60;
            incMinutes();
        }
    }
public:

    bool getUserInput() {
        char userInput;
        cin >> userInput;
        if (userInput == '1') {
            incHour();
            return true;
        }
        else if (userInput == '2') {
            incMinutes();
            return true;
        }
        else if (userInput == '3') {
            incSeconds();
            return true;
        }
        else if (userInput == '4') {
            return false;
        }
        else {
            cout << "Invalid Input" << endl;
            getUserInput();
        }
    }

    void printClock() {
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

    void printMenu() {
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