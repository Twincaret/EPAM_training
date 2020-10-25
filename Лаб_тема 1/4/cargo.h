#pragma once
#ifndef CARGO_H
#define CARGO_H
#include <iostream>
#include <string>

class Cargo
{
	protected:
    			std::string name;
    			double amount;
	public:
			/*constructor       */
   		 	Cargo(std::string, double);
 
        /* virtual func prototype */
	virtual void Print()const = 0;
        /* destructor */
    	~Cargo(){}
};



#endif
