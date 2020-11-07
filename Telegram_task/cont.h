#pragma once
#ifndef CONT_H
#define CONT_H
#include <iostream>
#include <cassert>
#include <random>

class Array 
{
private:
	int length;
	int *data;
public:
	/* constructor for empty array */
	Array() : length(0), data(nullptr) {} 

        /* constructor for array with defined size */
	Array(int len) : length(len)
	{
		assert(len >= 0); 
		if(len > 0) data = new int[len];
		else data = nullptr;
	} 
	/* clear the array */
	void clear()
	{
		delete[] data;
		data = nullptr;
		length = 0;
	}
	/* destructor */
	~Array()
	{
		delete[] data;
	}
	/* [] operator overloading with index (x)
              for access to the array elements */
	int &operator[](int x)
	{
		assert(x >= 0 && x < length);
		return data[x];
	}
	/* access to the array length */
	int getLength() {return length;}
	/* other func */
	void resize(int x_len);
	void addval(int val, int x);
	void delval(int x);
	void print(Array &a);
	/* generate new array */
	int dice_roll();
	void ini(Array &a);	
	/* check array length */
	int check(int n);	
};

#endif
