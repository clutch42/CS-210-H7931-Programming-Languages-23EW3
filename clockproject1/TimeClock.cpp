




TimeClock::string formatDigits(int timeInt) {
    string tempTimeString;
    if (timeInt < 10) {
        tempTimeString += "0" + to_string(timeInt);
    }
    else {
        tempTimeString += to_string(timeInt);
    }
    return tempTimeString;
}