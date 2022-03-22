// Purpose : Write out a menu and execute commands for a nurse
// shift schedule
// Copyright (c) EvansZ March 14 2022

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bitset>
#include <cctype>
#include "functions.h"


int main() {
    bool check = true;
    std::cout << ">> Enter the file name with its extension:" << std::endl;
    std::string filename;
    std::cin >> filename;
    std::ifstream readfile;
    std::vector<std::string> fname;
    std::vector<std::string> days;
    readfile.open(filename);
    if (!readfile.is_open()) {
        std:: cout << "!!! Could not open the input file : "
            << filename << std::endl;
        return 1;
    }
    while (check) {
        int input = menu();
        read(readfile, fname, days);
        if (input == -1) {
            std::cout << "Bye!" << std::endl;
            check = false;
        } else if ( input == 0 || input < -1 || input > 5 ) {
            std::cout << " !! Wrong choice !! Try again!" << std::endl;
        } else {
        switch (input) {
            case 1: checkInd(days, fname);
            break;
            case 2: checkDay(fname, days);
            break;
            case 3: allWork(days);
            break;
            case 4: noWork(days);
            break;
            case 5: names(fname);
            break;
        }
        }
    }
    return 0;
}
