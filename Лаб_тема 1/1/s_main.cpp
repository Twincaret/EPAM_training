#include "students.h"
#include "students.cpp"

void getData(student*, int);
void showArray(student*, int);
void setAttribute(student*, int);
void sortArray(student*, int);
void showSorted(student*, int);

int main() 
{
	cout << "Enter number of students: ";
	int n;
	cin >> n;
	cout << endl;
	student *st = new student[n];
    getData(st, n);
	cout << endl;		
    showArray(st, n);	
	cout << endl;
	setAttribute(st, n); // set attribute for sorting depending on the family length:
	sortArray(st, n);   // even ascending, odd descending
	showSorted(st, n); // result
	delete[] st;
	
	return 0;	

}
