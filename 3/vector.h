#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <climits>
#include <cmath>

class Vector{
	private:
			double *v_num;
			int v_length;
	public:
			Vector(double num[], int size);
			Vector(int size);
			Vector();
			void sort();
			void min();
			void max();
			void avg();
			void output();
			double findSum();
			~Vector()
			{
				delete[] v_num;
			}
};


#endif
