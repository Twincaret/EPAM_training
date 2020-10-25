#include "arr2d.h"
#include <cstdlib>
#include <random>

D_range::D_range(int n_size, int m_size) { n = n_size; m = m_size; arr = new int*[n]; for(int i = 0; i < n; i++) {arr[i] = new int[m];}; }
/* ======================================================================================== */
int D_range::dice_roll() // PRNG
{
    static std::random_device rd; // create access to truly random numbers
    static std::mt19937 gen(rd()); // create pseudo random generator
    // initialize its seed to truly random number
    static std::uniform_int_distribution<> dis(10, 99); // define distribution 
    return dis(gen); // auto x = dis(gen); (generate pseudo random number form `gen`)
    // and transform its result to desired distribution `dis`.
}
/* ======================================================================================== */
void D_range::ini() { for(int i = 0; i < n; i++) for(int j = 0; j < m - 1; j++) arr[i][j] = dice_roll(); }

void res(D_range &f) // friend func
{
	for(int i =0; i < f.n; i++)
    {
		for(int j = 0; j < f.m; j++)
        {
			if(j < (f.m - 1))
			{
				std::cout << f.arr[i][j] << " ";
				f.s += f.arr[i][j];
			}
            if(j >= (f.m - 1))
            {
				std::cout << "\tsum: " << f.s;	
				f.s = 0;
			}
                
        }
        std::cout << std::endl;
    }
}
