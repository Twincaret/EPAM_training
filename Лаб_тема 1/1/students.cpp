#include "students.h"

void getData(student *st, int n) 
{
	for(int i = 0; i != n; i++) 
	{
		cout << "Family: ";
		cin >> st[i].family;
		st[i].num = st[i].family.size(); // family length 
		cout << "Name: ";
		cin >> st[i].name;
		cout << "Score: ";
		int j = 0;
		do 
		{
			cin >> st[i].score[j];
			j++;
		}while(j != 3);
		cout << endl;
	}	
}

void showArray(student *st, int n) 
{
	for(int i = 0; i != n; i++) 
	{
		cout << st[i].family << endl;
		cout << st[i].name << endl;		
		for(int j = 0; j != 3; j++) 
		{
			cout << st[i].score[j] << " ";
		}
		cout << "\n"  << endl;		
	}	
}

void setAttribute(student *st, int n)
{  
	for(int i = 0; i != n; i++) 
	{
		if(st[i].num % 4 == 0)          // avg
		{
			int sum = 0; 	
			for(int j = 0; j != 3; j++) 
			{
				sum += st[i].score[j]; 
				st[i].num = sum / 3;
			}	
		} else if(st[i].num % 4 == 1)   // max
		{
			int max = st[i].score[0];
			for(int j = 0; j != 3; j++) 
			{
				if(max < st[i].score[j]) max = st[i].score[j];
			}
			st[i].num = max;
		} else if(st[i].num % 4 == 2)   // min
		{
			int min = st[i].score[0];
			for(int j = 0; j != 3; j++) 
			{
				if(min > st[i].score[j]) min = st[i].score[j];
			}
			st[i].num = min;
		} else if(st[i].num % 4 == 3)   // sum
		{
			int sum = 0; 	
			for(int j = 0; j != 3; j++) 
			{
				sum += st[i].score[j]; 
				st[i].num = sum;
			}	
		}
    }
}   

/* even odd sort */
/*
void sortArray(student *st, int n) { 
	int arr[n], tmp;
	for(int i = 0; i != n; i++) 
	{						 	
		arr[i] = st[i].num;
    }
	int j = 0, odd = sizeof(arr) / sizeof(*arr) - 1;
	for(int i = 0; i <= odd; i++) 
	{
		tmp = arr[i];
		if(tmp % 2 == 0)
		{
				for(j = i - 1; j >= 0 && arr[j] > tmp; j--)
				{
					arr[j + 1] = arr[j];
				}
				arr[j + 1] = tmp;
		}
		else
		{
			swap(arr[i], arr[odd]);
			for(j = odd + 1; j < sizeof(arr) / sizeof(*arr) && arr[j] > tmp; j++)
			{
				arr[j - 1] = arr[j];
			}
			arr[j - 1] = tmp;
			odd--;
			i--;
		}		
	}	
} 
*/
void showSorted(student *st, int n)
{
	for(int i = 0; i != n; i++) 
	{
		cout << st[i].family << endl;
		cout << st[i].name << endl;		
		cout << st[i].num << endl; 
		cout << endl;		
	}	
}
