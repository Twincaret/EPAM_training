#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <string>

class Truck : public Cargo
{
			int value;

		public:
			/*constructor           */
			Truck(std::string, double, int);
			void setData(std::string, double, int);
			double getAmount();
			double getCost();
			void Print()const;
    			~Truck(){} //destructor
};



#endif
