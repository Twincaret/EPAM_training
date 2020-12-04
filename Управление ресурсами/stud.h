#ifndef STUD_H
#define STUD_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ostream>

class Student
{
private:
    std::string name;
    int group;
 
public:
    Student() : name(""), group(0)
    {/*std::cout <<  "\n-> Default Constructor called ";*/}
    Student(const char* s) : name(s), group(0)
    {/*std::cout <<  "\n-> Constructor with one param. called ";*/}
    Student(const char* s, int g) : name(s), group(g)
    {/*std::cout <<  "\n-> Constructor with both param. called ";*/}
    Student(const Student &St)  // copy constructor
    {
        name  = St.name;
        group = St.group;
    }
   
    const char* GetName() const
    {
        return name.c_str();
    }
    void SetName(const char* s)
    {
        name = s;
    }
    int GetGroup() const
    {
        return group;
    }
    void SetGroup(int g)
    {
        group = g;
    }
 
    friend std::istream& operator >> (std::istream &s, Student &St);
    friend std::ostream& operator << (std::ostream &s, const Student &St);
 
    friend bool operator < (const Student&, const Student&);
    friend bool operator > (const Student&, const Student&);
    friend bool operator == (const Student&, const Student&);
    friend bool operator != (const Student&, const Student&);
};

#endif
