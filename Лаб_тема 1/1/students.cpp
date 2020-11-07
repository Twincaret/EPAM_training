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

void sortArray(student *st, int n) 
{	
	// sort students by num field
    for(int i = 0; i < n - 1; i++)
    { 
		for(int j = i + 1; j < n; j++)
		{   
			// even numbers ascending, odd descending
			if((st[i].num % 2 == 0 && st[j].num % 2 == 0 && st[i].num > st[j].num) || (st[i].num % 2 && st[j].num % 2 && st[i].num > st[j].num))
			swap(st[i],st[j]);
		}
	}
	// even, odd (separately)	
	for(int i = n - 1; i >= 0; i--) 
	{
		for(int j = 0; j < i; j++) 
		{
			if(st[j].num % 2 != 0) 
			{				
				student tmp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = tmp;
		    } 
		}
	}				
}

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
