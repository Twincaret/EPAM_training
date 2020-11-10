#include "cont.h"
#include "cont.cpp"

int main() 
{
	int n, i;
	std::cout << "Enter desired array length: ";
	std::cin >> n;	
	Array a(n);
	ini(a); // array 'a' init
	std::cout << "New generated array: ";
	print(a);
	std::cout << std::endl;	
	std::cout << "Array length is: " << a.getLength() << " elements\n" << std::endl;
	std::cout << "Enter new length for the array: ";
	std::cin >> n;	
	try 
	{
		if(n < 0){throw 1;}
		a.resize(n);
		std::cout << "Resized array: ";
		print(a);
		std::cout << "\n" << std::endl;
	}
	catch(int thr){std::cout << "Error n." << thr << ": Value must be >= 0." << std::endl;}

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
