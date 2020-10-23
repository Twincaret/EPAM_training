#include "cargo.cpp"
#include "cargo.h"
#include "plane.h"
#include "train.h"
#include "truck.h"

using namespace std;

int main() 
{
    Plane a;
    Train b;
    Truck c;
    Cargo *pa = &a; //access through pointer
    Cargo *pb = &b;
    Cargo *pc = &c;
    a.setData("DHL", 90, 500);
    b.setData("DB Schenker", 55.5, 320);
    c.setData("DSV", 18.6, 180);
    
    pa->Print();
    pb->Print();
    pc->Print();
    
    cout << endl << "Total cost:\t\u20AC " << a.getCost() + b.getCost() + c.getCost() << endl;

	return 0;
}
