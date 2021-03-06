#include "cont.h"
#include "cont.cpp"
#include <algorithm>  // for lib 
#include <vector>        // func

int main()
{
	int n, i;

	std::cout << "Enter desired array length: ";
	std::cin >> n;
	Array a(n);
	ini(a); // array 'a' init
	std::cout << "\nNew generated array: ";
	print(a);
	// clone array to vector to work with lib func   
	std::vector<int> v(n);
    for(int i = 0; i < n; ++i)
	{
		v[i] = a[i];
	}
    /* for( auto i : v ) { std::cout << i << " "; } */
	std::cout << std::endl;
	std::cout << "Array length is: " << a.getLength() << " elements\n" << std::endl;

	std::uint16_t startPoint = clock();
	quickSort(a, 0, n - 1); // custom func
	std::uint16_t finalPoint1 = clock() - startPoint;
	startPoint = clock();
    std::sort(v.begin(), v.end()); // lib func
	std::uint16_t finalPoint2 = clock() - startPoint;
	std::cout << "Sorted array: ";
	// print sorted 
	print(a);

	std::cout << std::endl;
	std::cout << "Sorting time: custom func " << finalPoint1 << " ms. vs lib func "<< finalPoint2 << " ms.\n";
	std::cout << std::endl;

	std::cout << "Enter the value you wish to find in the array: ";
	std::cin >> n;
	std::cout << "Value ";
    /* custom search func */
	startPoint = clock();
	(binsearch(a, n) == -1? std::cout << "not found" << std::endl : std::cout << n << " has index " << binsearch(a, n) << std::endl);
	finalPoint1 = clock() - startPoint;
	//std::cout << "Value ";
	/* lib search algorithm */
	startPoint = clock();
    auto x = std::find(v.begin(), v.end(), n);
	(x == v.end()? std::cout/*<< "not found" */<< std::endl : std::cout/* << n << " has index " << x - v.begin() */<< std::endl);
	finalPoint2 = clock() - startPoint;
	std::cout << "Search time: custom func " << finalPoint1 << " ms. vs lib func "<< finalPoint2 << " ms.\n";

	std::cout << "\nEnter new length for the array: ";
	std::cin >> n;
	try
	{
		if(n < 0){throw 1;}
		a.resize(n);
		std::cout << "Resized array: ";
		print(a);
		std::cout << "\n" << std::endl;
	}
	catch(int thr){std::cerr << "Error n." << thr << ": Value must be >= 0." << std::endl;}

	std::cout << "Enter value and index of new element you wish to add into array: ";
	std::cin >> n >> i;
	a.addval(n, i);
	std::cout << "Array with new added value: ";
	print(a);
	std::cout << "\n" << std::endl;
	std::cout << "Enter the index of the element you wish to delete: ";
	std::cin >> i;
	a.delval(i);
	std::cout << "Array with removed element: ";
	print(a);

	return 0;

}

