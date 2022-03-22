#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bitset>
#include <cctype>
 
 void names(const std::vector<std::string> fname);
 int menu();
void read(std::ifstream& readfile, std::vector<std::string>& fname, std::vector<std::string>& days);
void checkInd(const std::vector<std::string> days,const std::vector<std::string> fname);
void checkDay(const std::vector<std::string> fname,const std::vector<std::string> days);
void allWork(const std::vector<std::string> days);
void noWork(const std::vector<std::string> days);
   
#endif 