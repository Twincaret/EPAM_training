#pragma once
#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>

class Plane : public Cargo
{
			int value;

		public:
			/*constructor           */
			Plane(std::string, double, int);
			void setData(std::string, double, int);
			double getAmount();
			double getCost();
			void Print()const;
    			~Plane(){} //destructor
};



#endif
