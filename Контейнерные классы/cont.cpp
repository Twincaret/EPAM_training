#include "cont.h"

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

void quickSort(Array &a, int left, int right)
{
	int point; // permitting element point
	int l_hold = left; // left border
	int r_hold = right; // right border
	point = a[left];
	while (left < right) // while the borders aren't close
	{
		while ((a[right] >= point) && (left < right)) --right; // slide right border while [right] more than [point]
		if (left != right) // if borders aren't close
		{
			a[left] = a[right]; // move the [right] element to the place of the permitting element
			++left; // slide left border to the right
		}
		while ((a[left] <= point) && (left < right)) ++left; // slide left border while [left] less than [point]
		if (left != right) // if the borders aren't close
		{
			a[right] = a[left]; // moving the [left] element to the place of the [right] element
			--right; // slide right border to the right
		}
	}
	a[left] = point; // moving permitting element on its place
	point = left;
	left = l_hold;
	right = r_hold;
	if (left < point) // recursion calling of the quickSort func for left && right parts of the array
		quickSort(a, left, point - 1);
	if (right > point)
		quickSort(a, point + 1, right);
}

int binsearch(Array &a, int x) 
{
    int l = 0, r = a.getLength() - 1;

	while(r > l)
    {
        int m = (l + r) / 2;    // integer division

        if(a[m] < x) 
        {
            l = m + 1;
        } else if(a[m] > x) 
        {
			r = m - 1;
		} else 
		{
			return m;
		}
    }

    // l == r == sought index

    // if sought element wasn't found, binary search will find next element after it
    // additional comparison to recognize it
    if(a[l] == x) {return l;} else {return -1;}
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
