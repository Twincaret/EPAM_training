#include "list.h"
#include "stud.h"
#include "node.cpp"

using namespace std;

static vector<Student*> stVec;  

void Vclear()
{
	for (vector<Student*>::iterator pObj = stVec.begin(); pObj != stVec.end(); ++pObj) 
		delete *pObj; // the instance pointed to pObj is deleted 

	stVec.clear(); // clear content
	cout << "\n-> Memory cleared (vector deleted)";
}  

int main()
{
    List<Student> stList;

    stList.push_back(Student("Ivanov", 111));
    stList.push_back(Student("Petrov", 126));
    stList.push_back(Student("Sidorov", 453));
    stList.push_back(Student("Orehov", 341));
    stList.push_back(Student("Tarasov", 232));
    stList.push_back(Student("Smirnov", 514));
        
    //stList.OutputToFile();

    stList.display();
    cout << endl;
    
    stList.insert(0,Student("Fedorov", 633));
    stList.insert(5,Student("Mikhailov", 127));
    stList.insert(stList.size(),Student("Bogdanov", 251));
 
    stList.display();
    cout << endl;
 
    stList.remove(0);
    stList.remove(3);
    stList.remove(stList.size()-1);
 
    stList.display();
    cout << endl;
    
    // find student
    cout << "-> Student Sidorov, group 453: " << stList.find(Student("Sidorov", 453)) << endl;
    
    cout << "\n-> Base size: "<< stList.size() << " elements" << endl;
    cout << endl;
    
    // filling the vector
    Student* ptr = nullptr;
    ptr = new Student("Ivanov", 111);
    stVec.push_back(ptr);
    ptr = new Student("Petrov", 126);
    stVec.push_back(ptr);
    ptr = new Student("Sidorov", 453);
    stVec.push_back(ptr);
    ptr = new Student("Orehov", 341);
    stVec.push_back(ptr);
    ptr = new Student("Tarasov", 232);
    stVec.push_back(ptr);
    ptr = new Student("Smirnov", 514);
    stVec.push_back(ptr);
    
	// sorting by group numbers
    int comparisons{ 0 };
    sort(stVec.begin(), stVec.end(),
        [&comparisons](const auto& a, const auto& b) {
            ++comparisons;
            return (a->GetGroup() < b->GetGroup());
        });
    cout << endl << "\n-> Comparisons: " << comparisons << '\n';
    
    // show vector
    int n = 0; 
    cout << endl;
    for (auto const &element : stVec)
		cout  << "(" << n++ << ") " << *element ;
		
    Vclear(); // Destructor for vector called
    cout << "\n-> Is base empty? (true/false) " << stList.isempty() << endl;
    
    return 0;
}





