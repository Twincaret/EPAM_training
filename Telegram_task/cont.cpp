#include "cont.h"

int check(int n) {if(n < 0) std::cerr << "Wrong value, try again."; return 1;}

void Array::resize(int x_len) 
{
	if(x_len == length) return;
	if(x_len <= 0) {clear(); return;}
	/* new array */
	int *x_arr = new int[x_len];
	if(length > 0)
	{
		int x_data = (x_len > length)? length : x_len;
		for(int x = 0; x < x_data; ++x)
			x_arr[x] = data[x];
	}
	delete[] data;		
	data = x_arr;
	length = x_len;
		
}
/* add new value (val) to the array by index (x) */
void Array::addval(int val, int x) 
{
	assert(x >= 0 && x <= length);
	/* new array */
	int *x_arr = new int[length + 1];
	for(int i = 0; i < x; ++i)
		x_arr[i] = data[i];
		
	x_arr[x] = val;
	
	for(int j = x; j < length; ++j)
		x_arr[j + 1] = data[j];
		
	delete[] data;		
	data = x_arr;
	++length;		
}
/* remove some element from the array by index (x) */
void Array::delval(int x) 
{
	assert(x >= 0 && x < length);
	if(length == 1) {clear(); return;}
	/* new array */
	int *x_arr = new int[length - 1];
	for(int i = 0; i < x; ++i)
		x_arr[i] = data[i];
		
	for(int j = x + 1; j < length; ++j)
		x_arr[j - 1] = data[j];
		
	delete[] data;		
	data = x_arr;
	--length;		
}

void print(Array &a)
{
	for(int i = 0; i < a.getLength(); ++i)
		std::cout << a[i] << " ";
}
//====================================================================================
int dice_roll() // PRNG                                                               
{                                                                                     
    static std::random_device rd; // create access to truly random numbers            
    static std::mt19937 gen(rd()); // create pseudo random generator                  
    // initialize its seed to truly random number                                     
    static std::uniform_int_distribution<> dis(10, 99); // define distribution        
    return dis(gen); // auto x = dis(gen); (generate pseudo random number form `gen`) 
    // and transform its result to desired distribution `dis`.                        
}                                                                               

void ini(Array &a) {for(int i = 0; i < a.getLength(); ++i) a[i] = dice_roll();}
//====================================================================================
