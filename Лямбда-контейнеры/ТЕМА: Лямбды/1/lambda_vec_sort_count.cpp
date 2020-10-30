#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	
	std::vector<int> v = {2, 9, 6, 4, 1, 3, 5, 8, 7};
	//std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	size_t count = 0;
	std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });

	std::sort(v.begin(), v.end(), [&count](int& a, int& b) { 
		if(a < b) count++; 
		return a < b;
	  });

	std::cout << std::endl << std::endl;
	std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
	std::cout << std::endl << std::endl << count;

return 0;

}
