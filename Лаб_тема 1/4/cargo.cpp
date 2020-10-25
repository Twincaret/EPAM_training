#include "cargo.h"
#include "plane.h"
#include "train.h"
#include "truck.h"

/* base class constructor                        list init */
Cargo::Cargo(std::string n = "...", double a = 0.0) : name(n), amount(a) {}

/* derived class constructor */
Plane::Plane(std::string n = "...", double a = 0.0, int v = 0) {}

void Plane::setData(std::string n = "...", double a = 0.0, int v = 0)
	{
			name = n;
			amount = a;
		    value = v;
	}
	
double Plane::getAmount()
	{
			return amount;
	}
	
double Plane::getCost()
	{
		return value * amount;
	}
	
void Plane::Print()const
		{
			std::cout << "Company:\t" << name  << "\n" << "Amount:\t\t" << amount << " tn\n" << "Value:\t\t\u20AC " << value << " per tn \n" << "Cost:\t\t\u20AC " <<  value * amount << std::endl << std::endl;
		}

/* derived class constructor */
Train::Train(std::string n = "...", double a = 0.0, int v = 0) {}

void Train::setData(std::string n = "...", double a = 0.0, int v = 0)
	{
			name = n;
			amount = a;
		    value = v;
	}
	
double Train::getAmount()
	{
			return amount;
	}
	
double Train::getCost()
	{
		return value * amount;
	}
	
void Train::Print()const
		{
			std::cout << "Company:\t" << name  << "\n" << "Amount:\t\t" << amount << " tn\n" << "Value:\t\t\u20AC " << value << " per tn \n" << "Cost:\t\t\u20AC " <<  value * amount << std::endl << std::endl;
		}

/* derived class constructor */
Truck::Truck(std::string n = "...", double a = 0.0, int v = 0) {}

void Truck::setData(std::string n = "...", double a = 0.0, int v = 0)
	{
			name = n;
			amount = a;
		    value = v;
	}
	
double Truck::getAmount()
	{
			return amount;
	}
	
double Truck::getCost()
	{
		return value * amount;
	}
	
void Truck::Print()const
		{
			std::cout << "Company:\t" << name  << "\n" << "Amount:\t\t" << amount << " tn\n" << "Value:\t\t\u20AC " << value << " per tn \n" << "Cost:\t\t\u20AC " <<  value * amount << std::endl << std::endl;
		}
