#include "database.h"


/* for alphabeticall sorting */
bool compare_for_sort(const Employee* E1, const Employee* E2)
{	
	return E1->name < E2->name;
}
	
/* for sorting by age */
bool compare_by_age(const Employee* E1, const Employee* E2)
{	
	if(E1->date.year == E2->date.year) // year
	{
		if(E1->date.month == E2->date.month) // month
		{
			return E1->date.day < E2->date.day; // day
		}
		return E1->date.month < E2->date.month; // month
	}
	else
	{
		return E1->date.year < E2->date.year ; // year
	}
}
	
/* find by month */
void find_by_month(std::vector<Employee*> vEmp, int x_month, char slash)
{
	int cnt = 0;

	auto it = find_if(vEmp.begin(), vEmp.end(), [x_month](const Employee* E)
	{
		return E->date.month == x_month;
	});
	
	while (it != vEmp.end())
	{
		std::cout << (*it)->name << " " << std::setw(2) << std::setfill('0') << (*it)->date.day << slash << std::setw(2) << std::setfill('0') << (*it)->date.month << slash << (*it)->date.year << " " << (*it)->gender << std::endl; 
		it = find_if (++it, vEmp.end(), [x_month](const Employee* E){return E->date.month == x_month;}); 
		++cnt;
	}
	if(!cnt) std::cout << " -> Didn't match :( \n";
}
	
/* find by first letter */
void find_by_char(std::vector<Employee*> vEmp, char letter)
{
	int cnt = 0;
	char x = tolower(letter);
	char z = toupper(letter);

	auto it = find_if(vEmp.begin(), vEmp.end(), [x,z](const Employee* E)
	{
		return ((*E->name.begin() == x) || (*E->name.begin() == z));
	});
	
	while (it != vEmp.end())
	{
		std::cout << (*it)->name << std::endl;
		it = find_if (++it, vEmp.end(), [x,z](const Employee* E){return ((*E->name.begin() == x) || (*E->name.begin() == z));}); 
		++cnt;
	}
	if(!cnt) std::cout << " -> Didn't match :( \n";
	
	/*  ???
	copy_if(vEmp.begin(), vEmp.end(), ostream_iterator<Employee*>(cout, "\n"), [a](const Employee* E) {return (E->name[0]) == a ? true : false; });
	*/
	
}

/* output data */
void output(std::vector<Employee*> vEmp)
{
    if (!vEmp.empty())
    {
		for(const auto &Emp : vEmp)
		std::cout << Emp->name << " " << std::setw(2) << std::setfill('0') << Emp->date.day<< "/" << std::setw(2) << std::setfill('0') << Emp->date.month << "/" << std::setw(4) << std::setfill('0') << Emp->date.year << " " << Emp->gender << std::endl;
    }	
    else  std::cout << " -> Base is empty\n";
}

/* error handler */
void error()
{
	std::cout << " -> Incorrect input. Try again.\n";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* add data to file */
void add_new_record(std::vector<Employee*> &vEmp, int number, char slash)
{
	Employee* ptr = nullptr;

	while(number)
    {
		ptr = new Employee;

		std::cout << " -> Family, name && second name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(std::cin, ptr->name);
            
		std::cout << " -> Birth date (use a char input delimiter e.g. dd / mm / yyyy): ";
		while(std::cin  >> ptr->date.day >> slash >> ptr->date.month >> slash >> ptr->date.year && !"\n");

		while(true)
		{
			std::cout << " -> Gender (m | w): ";
			char x;
			std::cin  >> x;
			if(x == 'm' || x == 'M' || x == 'w' || x == 'W')
			{
				ptr->gender = x;
				break;
			}
			else error();
		}
		vEmp.push_back(ptr); 
		--number;
    }	
}

/* save data to Emp.txt */
void save_to_file(std::vector<Employee*> vEmp)
{
    std::ofstream fout;
    fout.open("Emp.txt");
 
    if (!vEmp.empty())
    {
		for(const auto &Emp : vEmp)
		fout << Emp->name << " " << std::setw(2) << std::setfill('0') << Emp->date.day<< "/" << std::setw(2) << std::setfill('0') << Emp->date.month << "/" << std::setw(4) << std::setfill('0') << Emp->date.year << " " << Emp->gender << std::endl;
    }	
    else  std::cout << " -> Base is empty\n";
 
    fout.close();
}
	
/* input data */		
void input_menu(std::vector<Employee*> &vEmp, int choice, int number, int x_month, char letter, char slash)
{
	do
    {   
		while(true)
		{
			std::cout << " -> Your choice: ";
			std::cin  >> choice;
			if(choice < 0 || !std::cin || choice > 8) error();
			else break;
		}

		switch (choice)
		{
			case 1:    /* show database */
			{
				output(vEmp);
				break;
			}
			case 2:    /* number of records */
			{
				while(true)
				{
					std::cout << " -> How many records will be entered? ";
					std::cin  >> number;
					if(number< 0 || !std::cin) error();
					else break;
				}	
				add_new_record(vEmp, number, slash);
				break;
			}			
			case 3:    /* save data to Emp.txt */
            {
                save_to_file(vEmp);
                break;
            }
			case 4:	/* sort alphabetically */
            {
				sort(vEmp.begin(), vEmp.end(),compare_for_sort);   
				output(vEmp);
                break;
            }
			case 5:    /* sort by age */
            {
                sort(vEmp.begin(), vEmp.end(),compare_by_age);   
				output(vEmp);
                break;
            }
			case 6:	/* find by month */	
            {
				std::cout << " -> Enter month (number, e.g. 1): ";
				std::cin  >> x_month;
				find_by_month(vEmp, x_month, slash);
                break;
            }
			case 7:	/* oldest man */
            {
				sort(vEmp.begin(), vEmp.end(),compare_by_age);   
				for(const auto &Emp : vEmp)
				{
					if(Emp->gender == 'm' || Emp->gender== 'M')
					{
						std::cout << Emp->name << std::endl;
						break;
					}
					else std::cout << " -> Didn't match :( \n";
				}
				break;
            }          
			case 8:	/* find by first letter */	
            {
				std::cout << " -> Enter letter: ";
				std::cin  >> letter;
				find_by_char(vEmp, letter);
                break;
            }
         }
    } while (choice !=0);
}

/* release memory */
void v_clear(std::vector<Employee* > &vEmp)
{
	for (std::vector<Employee*>::iterator pObj = vEmp.begin(); pObj != vEmp.end(); ++pObj) 
		delete *pObj; // the instance pointed to pObj is deleted 

	vEmp.clear(); // clear content
	std::cout << "\n -> Memory cleared (vector deleted)";
}  
