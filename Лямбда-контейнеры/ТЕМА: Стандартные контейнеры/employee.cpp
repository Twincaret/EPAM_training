#include <iostream>     
#include <string>
 
using namespace std;
 
class Employee 
{
    string name;
    long numb;
    
public:
    void getdata()
    {
        cout << "\nName ";  getline (cin, name);
        cout << "Number ";  (cin >> numb).get();
        cout << endl;
    }
    void putdata()const
    {
        cout << "\nName " << name << "\nNumber " << numb << endl;
    }
};
    
int main()
{
    Employee e [100];
    char x;
    int n = 0;
    do
    {
        cout << "Employee data: ";
        e [n++].getdata();
        cout << "Continue ? (y/n): "; (cin >> x).get();
        cout << endl;
    }
    while( x != 'n' && x != 'N');
 
    for( int i = 0; i < n; ++i )
    {
        cout << "Employee " << i + 1;  e[i].putdata();
        cout << endl;
    }
 
    return 0;
}
