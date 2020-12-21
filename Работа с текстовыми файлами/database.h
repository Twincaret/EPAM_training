#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cctype>  // tolower(char)
 //#include <iterator>

struct Date                                              
{
    int day;
    int month;
    int year;
};
 
struct Employee                                 
{
    std::string name;
    Date date;
    char gender;
};

#endif
