#include "vector.h"
#include "vector.cpp"
#include <time.h>

using namespace std;

int main() {
	
	double *num_1 = new double[10];
	double *num_2 = new double[10];

	srand(time(NULL));
	cout << "1st random array: " << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
    {
        num_1[i] = rand() % 100;
        cout << num_1[i] << " ";
    }
	/*
    double n;
	cout << "Input first array: ";
	for(int i = 0; i < 10; ++i)
	{
		cin >> n; 
		num_1[i] = n;
	} 
	*/
    cout << endl;
	Vector arr_1(num_1, 10);
	arr_1.sort();
	cout << "\n" << "Sorted array(even numbers descending, odd ascending): " << "\n" << endl;
	arr_1.output();
	cout << endl;
	arr_1.min();
	arr_1.max();
	arr_1.avg();
	cout << endl;
	cout << "2nd random array: " << endl;
	for (int i = 0; i < 10; i++)
    {
        num_2[i] = rand() % 100;
        //cout << num_2[i] << " ";
    }
	/*
	cout << "Input second array: ";
	for(int i = 0; i < 10; ++i)
	{
		cin >> n; 
		num_2[i] = n;
	} 
	*/
	cout << endl;
	Vector arr_2(num_2, 10);
	//arr_2.sort();
	arr_2.output();
	cout << "\n" << "Sum of elements: " << arr_2.findSum() << endl;
	delete [] num_1;
	delete [] num_2;

	return 0;
}
