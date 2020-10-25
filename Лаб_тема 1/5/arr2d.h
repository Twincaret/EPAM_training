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
    		D_range() { n = m = 1; s = 0; arr = new int*[n]; for(int i = 0; i < 1; i++) {arr[i] = new int[m];}; }
    		D_range(int, int);
    		// friend func
    		friend void res(D_range &f);  
        	// PRNG
  		int dice_roll(); 
    		void ini();
    		// destructor
    		~D_range() { for(int i = 0; i < n; i++) delete arr[i]; delete[]arr; }
};


#endif
