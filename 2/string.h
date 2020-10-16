#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class StringClass {
	
public:
	string s;
	char h;
	int c;	
	// first constructor (without params)
	StringClass();
	// second constructor (overloading, one param)
	StringClass(char chr);
	// third constructor (overloading, three param)
	StringClass(string str, char chr, int cnt);
        void SetData();
    	string ReplChar();
    	void GetData();
	// destructor
	~StringClass(){}
};

