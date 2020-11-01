#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void print(std::vector<int> x) 
{ 
	for (size_t j = 0; j < x.size(); j++)
	std::cout << x[j] << " ";
};

int main()
{
	std::vector<int> v, _v;
	int n, k;
	
	std::cout << "Enter number of elements of the vector: ";
	std::cin >> n;
	assert(n >= 0 && "Must be greater than or equal to 0");
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
		v.push_back(i);		
	print(v);
	std::cout << "\n\nEnter number of elements to replace from begin to end: ";
	std::cin >> k;
	assert(k >= 0 && "Must be greater than or equal to 0");
	std::cout << std::endl;
	for (size_t i = k; i < v.size() + k; i++)
		_v.push_back(i);
	print(_v);		

	return 0;
}
