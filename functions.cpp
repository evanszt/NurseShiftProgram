// Copyright (c) EvansZ May 14 2022

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bitset>
#include <cctype>
#include "functions.h"

/**
 * @brief This method will take a name input without case sensitivity
 * and return what days they work
 * 
 * @param days vector of days
 * @param fname vector of first names
 */
void checkInd(const std::vector<std::string> days,
    const std::vector<std::string> fname) {
    std::string input;
    bool stop = false;
    while (stop != true) {
    std::cout << ">> Enter a nurse name:" << std::endl;
    std::cin >> input;
    std::string inputCheck;
    bool nameCheck = false;
    for (int i = 0; i < fname.size()-1; i++) {
        if (fname.at(i).size() == input.length()) {
            inputCheck = fname.at(i);
            char c;
            char d;
            bool check = true;
            for (int j = 0; j < input.length(); j++) {
                c = inputCheck.at(j);
                d = input.at(j);
                if (tolower(c) != tolower(d)) {
                    check = false;
                }
            }
            if (check) {
                nameCheck = true;
                int count = 0;
                std::cout << "---- Shift Days ----" << std::endl;
                std::string sched = days.at(i);
                if (sched[6] == '1') {
                    std::cout << "Sunday"
                    << std::endl; count++;
                    }
                if (sched[5] == '1') {
                    std::cout << "Monday"
                    << std::endl; count++;
                    }
                if (sched[4] == '1') {
                    std::cout << "Tuesday"
                    << std::endl; count++;
                    }
                if (sched[3] == '1') {
                    std::cout << "Wednesday"
                    << std::endl; count++;
                    }
                if (sched[2] == '1') {
                    std::cout << "Thursday"
                    << std::endl; count++;
                    }
                if (sched[1] == '1') {
                    std::cout << "Friday"
                    << std::endl; count++;
                    }
                if (sched[0] == '1') {
                    std::cout << "Saturday"
                    << std::endl; count++;
                    }
                if (count == 0) std::cout << input <<
                    " does not have a shift this week" << std::endl;
                stop = true;
            }
        }
    }
if (nameCheck == false) {
    std::cout << "!!! No record for "
    << input << std::endl;
    }
}
    }



/**
 * @brief This method will assign values to the vectors fname and days based off a file. 
 * Pass in the filestream and vectors as references so that individual values can be assigned.
 * 
 * @param readfile the filestream to read from
 * @param fname vector of first names
 * @param days vector of days 
 */
void read(std::ifstream& readfile, std::vector<std::string>& fname,
    std::vector<std::string>& days) {
    std::string s;
    std::string i;
    while (readfile.good()) {
        readfile >> s;
        fname.push_back(s);
        readfile >> i;
        days.push_back(i);
    }
}

/**
 * @brief This method will print out every name in the fname vector.
 * Pass it in as a constant since its values wont be changed.
 * 
 * @param fname vector of first names
 */
void names(const std::vector<std::string> fname) {
        std::cout << "--- Names of Nurses ---" << std::endl;
        for (int i = 0; i < fname.size()-1; i++) {
            std::cout << fname[i] << std::endl;
        }
}

/**
 * @brief This method simply prints out the menu and takes in the users input
 * 
 * @return int the users input
 */
int menu() {
       std::cout << "--------------------------------\n" <<
        " Nurse Shift Query Application\n" <<
        "--------------------------------" << std::endl;
    std::cout << " 1 List shift days of the nurse" << std::endl;
    std::cout << " 2 List nurses for the day" << std::endl;
    std::cout << " 3 List days that all nurses work" << std::endl;
    std::cout << " 4 List days no nurse works" << std::endl;
    std::cout << " 5 List names of nurses" << std::endl;
    std::cout << "-1 Exit" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << ">> Enter your choice:" << std::endl;
    int input;
    std::cin >> input;
    return input;
    }
/**
 * @brief This method takes in a day of the week without case sensitivity and
 * returns what workers are working that day. Pass in the two vectors as constants
 * since their values wont be changed.
 * 
 * @param fname vector of first names
 * @param days vector of days
 */
void checkDay(const std::vector<std::string> fname,
    const std::vector<std::string> days) {
    bool check = true;
    bool isValid = false;
    int count = 0;
    char c;
    while (check) {
        std::cout << ">> Enter a day of the week:" << std::endl;
        std::string input;
        std::cin >> input;
        std::string inputUpper;
        for (int i = 0; i < input.length(); i++) {
            c = toupper(input[i]);
            inputUpper += c;
        }
        if (inputUpper == "SUNDAY" || inputUpper == "MONDAY"
            || inputUpper == "TUESDAY"
            || inputUpper == "WEDNESDAY" ||
                inputUpper == "THURSDAY" ||
                inputUpper == "FRIDAY" ||
                inputUpper == "SATURDAY") {
        std::cout << "---- Nurses ----" << std::endl;
                }
        if (inputUpper == "SUNDAY") {
            for (int i = 0; i < days.size()-1; i++) {
                if (days.at(i).at(6) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
                if (inputUpper == "MONDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(5) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
                if (inputUpper == "TUESDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(4) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
                if (inputUpper == "WEDNESDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(3) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
            if (inputUpper == "THURSDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(2) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
            if (inputUpper == "FRIDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(1) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
            if (inputUpper == "SATURDAY") {
            for (int i = 0; i < fname.size()-1; i++) {
                if (days.at(i).at(0) == '1') {
                    std::cout << fname.at(i) << std::endl;
                    count++;
                }
            }
            isValid = true;
        }
        if (isValid) {
        std::cout << count << " nurse(s) work(s) on "
            << inputUpper << std::endl;
        check = false;
        }
    }
    return;
}

/**
 * @brief This method prints the names of the days where all nurses are working.
 * Pass in days as a constant since its values wont be changed.
 * 
 * @param days  vector of days
 */
void allWork(const std::vector<std::string> days) {
    std::cout << "--- Days that all nurses work ---" << std::endl;
    int count = 0;
    for (int k = 6; k > 0; k--) {
        bool check = true;
        for (int i = 0; i < days.size()-1; i++) {
            if (days.at(i).at(k) != '1') check = false;
        }
        if (check) {
            switch (k) {
                case 6 : std::cout << "Sunday" << std::endl;
                count++;
                break;
                case 5 : std::cout << "Monday" << std::endl;
                count++;
                break;
                case 4 : std::cout << "Tuesday" << std::endl;
                count++;
                break;
                case 3 : std::cout << "Wednesday" << std::endl;
                count++;
                break;
                case 2 : std::cout << "Thursday" << std::endl;
                count++;
                break;
                case 1 : std::cout << "Friday" << std::endl;
                count++;
                break;
                case 0 : std::cout << "Saturday" << std::endl;
                count++;
                break;
            }
        }
    }
    if (count == 0) std::cout <<
    "There is no day that all nurses work!" << std::endl;
    return;
}
/**
 * @brief This method will print out the names of the days where there are no nurses
 * working. Pass the vector in as a const since its values wont be changed.
 * 
 * @param days 
 */
void noWork(const std::vector<std::string> days) {
    std::cout << "--- Days no nurse works ---" << std::endl;
    int count = 0;
    for (int k = 6; k > 0; k--) {
        bool check = true;
        for (int i = days.size()-1; i > 0; i--) {
            if (days.at(i).at(k) != '0') check = false;
        }
        if (check) {
            switch (k) {
                case 6 : std::cout << "Sunday" << std::endl;
                count++;
                break;
                case 5 : std::cout << "Monday" << std::endl;
                count++;
                break;
                case 4 : std::cout << "Tuesday" << std::endl;
                count++;
                break;
                case 3 : std::cout << "Wednesday" << std::endl;
                count++;
                break;
                case 2 : std::cout << "Thursday" << std::endl;
                count++;
                break;
                case 1 : std::cout << "Friday" << std::endl;
                count++;
                break;
                case 0 : std::cout << "Saturday" << std::endl;
                count++;
                break;
            }
        }
    }
    if (count == 0) std::cout <<
        "Each day at least one nurse has a shift!" << std::endl;
    return;
}
