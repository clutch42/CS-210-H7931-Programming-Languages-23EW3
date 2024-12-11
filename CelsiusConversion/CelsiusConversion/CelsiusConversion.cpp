// Brian Engel

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// function for reading in the city and temperature from FahrenheitTemperature.txt
void ReadCityAndTemp(vector<string>& cityList, vector<int>& tempList) {
    ifstream cityAndTempFS;     // input file stream variable
    string city;        // temporary variable to store city from file
    int temperature;    // temporary variable to store temperature from file

    cityAndTempFS.open("FahrenheitTemperature.txt");    // open file

    if (!cityAndTempFS.is_open()) {     // if file didn't open output could not open
        cout << "Could not open file FahrenheitTemperature.txt." << endl;
    }
    else {      // if the file opened
        while (!cityAndTempFS.eof()) {  // while it is not end of file
            cityAndTempFS >> city;      // set city to file stream
            cityAndTempFS >> temperature;   // set temperature to file stream
            cityList.push_back(city);       // add city to the end of cityList
            tempList.push_back(temperature);    // add temperature to the end of tempList
        }
        cityAndTempFS.close();  // close the file
    }
}

// function to display the city and temp (just used for testing if file input correctly and temp was converted correctly
void DisplayCityAndTemp(const vector<string>& cityList, const vector<int>& tempList) {
    for (int i = 0; i < cityList.size(); i++) {     // go through all elements of cityList
        cout <<"City: " << cityList.at(i) << "\tTemp: " << tempList.at(i) << endl;  // print out city and temperature
    }
}

// function to write the city and temp to a file CelsiusTemperature.txt
void WriteCityAndTemp(const vector<string>& cityList, const vector<int>& tempList) {
    ofstream outFS; // output file stream variable

    outFS.open("CelsiusTemperature.txt");   // open file

    if (!outFS.is_open()) {     // if file didn't open output could not open
        cout << "Could not open file CelsiusTemperature.txt." << endl;
    }

    for (int i = 0; i < cityList.size(); i++) {     // go through all elements of cityList
        outFS << cityList.at(i) << " " << tempList.at(i) << endl;   // output city then space then temperature then endline to file for each city
    }

    outFS.close();     // close the file
}

// function to convert fahrenheit to celsius
void ConvertFahrenheitToCelsius(vector<int>& tempList) {
    for (int i = 0; i < tempList.size(); i++) {     // for each temperature in tempList
        tempList.at(i) = (tempList.at(i) - 32) * 5 / 9;     // calculate degree celsius
    }
}

int main() {
    vector<string> cityList;        // vector for citys
    vector<int> tempList;           // vector for temperatures

    ReadCityAndTemp(cityList, tempList);    // read cities and temps from file
    DisplayCityAndTemp(cityList, tempList); // display cities and temps to ensure they imported correctly
    ConvertFahrenheitToCelsius(tempList);   // convent the temperatures to celsius
    DisplayCityAndTemp(cityList, tempList); // display citites and temps to ensure the conversion is correct
    WriteCityAndTemp(cityList, tempList);   // write the cities to a file

    return 0;
}