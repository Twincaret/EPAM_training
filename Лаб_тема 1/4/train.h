#pragma once
#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>
#include <string>

class Train : public Cargo
{
			int value;

		public:
			/*constructor           */
			Train(std::string, double, int);
			void setData(std::string, double, int);
			double getAmount();
			double getCost();
			void Print()const;
    			~Train(){} //destructor
};



#endif
