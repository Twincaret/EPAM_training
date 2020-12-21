#include "database.h"
#include "database.cpp"

int main()
{
	
	std::vector<Employee* > vEmp;
	
	int x_month = 0;
	int choice = 0;
	int number = 0;
	char letter = 'a';
	char slash = '/';

	std::cout << "Choose action:\n";
	std::cout << "1-> Load data from file\n";
	std::cout << "2-> Enter data\n";
	std::cout << "3-> Save data to file\n";
	std::cout << "4-> Sort database alphabetically (by last name)\n";
	std::cout << "5-> Sort database by age\n";
	std::cout << "6-> Output: list of people born in a given month\n";
	std::cout << "7-> Output: surname of the oldest man\n";
	std::cout << "8-> Output: all surnames starting with a given letter\n";
	std::cout << "0-> Exit\n";
        
    // Default initialization uncomment to test:
        
/* 
    Employee* ptr = nullptr;
    ptr = new Employee{"Ivanov R. A.", {{1},{2},{2000}}, 'm'};
    vEmp.push_back(ptr);
    ptr = new Employee{"Petrov N. D.", {{4},{8},{2004}}, 'm'};
    vEmp.push_back(ptr);
    ptr = new Employee{"Sidorov M. V.", {{6},{10},{2006}}, 'm'};
    vEmp.push_back(ptr);   
    ptr = new Employee{"Samoilova E. N.", {{10},{5},{2001}}, 'w'};
    vEmp.push_back(ptr);  
    ptr = new Employee{"Orehov S. G.", {{18},{11},{1998}}, 'm'};
    vEmp.push_back(ptr);
    ptr = new Employee{"Chizhova N. N.", {{22},{5},{1997}}, 'w'};
    vEmp.push_back(ptr);
    ptr = new Employee{"Smirnov N. V.", {{15},{3},{2001}}, 'm'};
    vEmp.push_back(ptr);
    ptr = new Employee{"Filatova P. M.", {{11},{4},{2002}}, 'w'};
    vEmp.push_back(ptr);   
    ptr = new Employee{"Bogdanov D. A.", {{19},{12},{1998}}, 'm'};
    vEmp.push_back(ptr);  
*/   
 
    input_menu(vEmp, choice, number, x_month, letter, slash);
    
    v_clear(vEmp);  // release memory

	return 0;

}

