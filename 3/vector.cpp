#include "vector.h"

Vector::Vector(double num[], int size)
{
	v_length = size;
	v_num = new double[v_length];
	for(int i = 0; i < v_length; i++)
	{
		v_num[i] = num[i];
	}
}

Vector::Vector(int size)
{
	v_length = size;
	v_num = new double[v_length];
}

Vector::Vector()
{
	v_length = 0;
}

double Vector::findSum()
{
	double sum = 0;
	for(int i = 0; i < v_length; i++)
	{
				sum += v_num[i];
	}
	return sum;
}

void Vector::sort()
{
	double *arr_o = new double[10];
	double *arr_e = new double[10];
	int odd = 0, even = 0;
	
	for(int i = 0; i < v_length; i++)
	{
		int x = static_cast<int>(v_num[i]);
		if (x % 2 == 0)
			arr_o[odd++] = v_num[i];
		else
			arr_e[even++] = v_num[i];
	}
	 
    for(int j = 0; j < odd; j++)
    {
		for(int i = 0; i < odd - 1; i++)
		{
			if(arr_o[i] < arr_o[i + 1])
			{
				int buf = arr_o[i];
				arr_o[i] = arr_o[i + 1];
				arr_o[i + 1] = buf;
			}
		}
}
    for(int j = 0; j < even; j++)
    {
		for(int i = 0; i < even - 1; i++)	
		{
			if(arr_e[i] > arr_e[i + 1])
			{
				int buf = arr_e[i];
				arr_e[i] = arr_e[i + 1];
				arr_e[i + 1] = buf;
	        }
	    }
	}
    for(int i = 0; i <= odd - 1; i++)
        v_num[i] = arr_o[i];
    for(int i = odd, j = 0; i <= v_length; i++, j++)
        v_num[i] = arr_e[j];
    delete arr_o;
    delete arr_e;
}

void Vector::output()
{
	for(int i = 0; i < v_length; i++)
	{
		std::cout << v_num[i] << "   ";
	}
	std::cout << std::endl;
}

void Vector::min()
{
	double min = v_num[0];
	for(int i = 1; i < v_length; i++)
	{
		if(min > v_num[i])
		{
			min = v_num[i];
		}
	}
	std::cout << "Min number: " << min << std::endl;
}

void Vector::max()
{
	double max = v_num[0];
	for(int i = 1; i < v_length; i++)
	{
		if(max < v_num[i])
		{
			max = v_num[i];
		}
	}
	std::cout << "Max number: " << max << std::endl;
}

void Vector::avg()
{
	std::cout << "The average: " << floor(findSum() / v_length) << std::endl;
}
