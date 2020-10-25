#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct student 
{
	string family;
	string name;
	int score[3];
	int num; // var for family length number && setAttribute func
};

void showArray(student*, int);
void setAttribute(student*, int);
void sortArray(student*, int);
void showSorted(student*, int);

int main() 
{
	cout << "Enter number of students: " << endl;
	int n;
	cin >> n;
	student *st = new student[n];
	for(int i = 0; i != n; i++) 
	{
		cout << "Family: " << endl;
		cin >> st[i].family;
		st[i].num = st[i].family.size(); // family length 
		cout << "Name: " << endl;
		cin >> st[i].name;
		cout << "Score: " << endl;
		int j = 0;
		do 
		{
			cin >> st[i].score[j];
			j++;
		}while(j != 3);
		cout << endl;
	}
	cout << endl;
		
    showArray(st, n);	
	cout << endl;
	setAttribute(st, n); // set attribute for sorting depending on the family length:
	sortArray(st, n);   // even ascending, odd descending
	showSorted(st, n); // result

	delete[] st;
	
	return 0;	

}

void showArray(student *st, int n) 
{
	for(int i = 0; i != n; i++) 
	{
		cout << st[i].family << endl;
		cout << st[i].name << endl;		
		for(int j = 0; j != 3; j++) 
		{
			cout << st[i].score[j] << " " << endl;
		}
		cout << endl;		
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
				if(max < st[i].score[j]) st[i].num = st[i].score[j];
			}
		} else if(st[i].num % 4 == 2)   // min
		{
			int min = st[i].score[0];
			for(int j = 0; j != 3; j++) 
			{
				if(min > st[i].score[j]) st[i].num = st[i].score[j];
			}
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
void sortArray(student *st, int n) { 
	int arr[n], tmp;
	for(int i = 0; i != n; i++) {				
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
	for(int i = 0; i != n; i++) {				
		st[i].num = arr[i]; 	
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









