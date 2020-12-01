//#include <algorithm>
#include <iostream> 
 
using namespace std;

template<typename T>
T *search_max(T *arr, int cnt)
{
  T max = *arr;
  T *ptr = arr;
  while (--cnt)
  {
    if (*arr > max) ptr = arr, max = *arr;
    ++arr;
  }   
  return ptr;
}

int main() 
{
	cout << "Enter array length: ";
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; ++i)
	{
		cout << "[" << i + 1 << "]" << ": ";
		cin >> arr[i];
	}
	cout << "\nFilled array: "; 
	for(int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
    /* find max element && it's index	
	   short path (using <algorithm>): */
	//cout << "\nMax element in the array: " << *std::max_element(arr, arr + n) << " has index: " << std::max_element(arr, arr + n) - arr << endl;
	
	cout << "\nMax element in the array: " << *(search_max(arr, n)) << " has index: " << search_max(arr, n) - arr << endl;

    return 0;
}



