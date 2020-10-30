#pragma once
#ifndef ARR2D_H
#define ARR2D_H
#include <iostream>

class D_range
{
	private:
    		int n, m, s; // s for sum
    		int** arr;
	public:
		/* constructor && init */
    		D_range() { n = m = s = 0; arr = new int*[n]; arr[0] = new int[m]; }
    		D_range(const int, const int);
    		// friend func
    		friend void res(D_range &f);  
        	// PRNG
  		int dice_roll(); 
    		void ini();
    		// destructor
    		~D_range() { for(int i = 0; i < n; i++) delete[]arr[i]; delete[]arr; }
};


#endif
