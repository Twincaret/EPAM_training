#pragma once
#ifndef STUDENTS_H
#define STUDENTS_H
#include <iostream>
#include <string>

using namespace std;

struct student 
{
	string family;
	string name;
	int score[3];
	int num; // var for family length number && setAttribute func
};

#endif
