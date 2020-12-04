#include "list.h"
#include "stud.h"

std::istream& operator >> (std::istream &s, Student &St)
{
    std::cout << "Enter the name: "; s >> St.name;
    std::cout << "Enter group: "; s >> St.group;
 
    return s;
}
 
std::ostream& operator << (std::ostream &s, const Student &St)
{
    s << "Name: " << St.name;
    s << ", group: " << St.group << std::endl;
 
    return s;
}
 
bool operator == (const Student& St1, const Student& St2)
{
    return (St1.name == St2.name && 
            St1.group == St2.group) ? true : false;
}
 
bool operator != (const Student& St1, const Student& St2)
{
    return !(St1 == St2);
}
 
bool operator < (const Student& St1, const Student& St2)
{
    if (St1.name == St2.name)
        return (St1.group < St2.group) ? true : false;
    return (St1.name < St2.name) ? true : false;
}
 
bool operator > (const Student& St1, const Student& St2)
{
    return !(St1 < St2);
}

//===========================================

template <typename T>
void List<T>::push_back(const T& data)
{
	Node_base* _new = new Node_base;
	_new->_data = data;
    _new->_next = nullptr;
    if (_start == nullptr)
   {
		_start = _new;
	} 
    else
   {
		Node_base* _end = node(_size - 1);
		_end->_next = _new;
    }
    ++_size;
}

template <typename T>
void List<T>::insert(const int n, const T& data)
{	
	try
	{
		if (n > _size)
		throw std::runtime_error("\n-> List index out of bound. ");
	} 
	catch (const std::runtime_error &e) 
	{
		std::cerr << e.what();
	}	
    if (n == _size)
        push_back(data);
	else
	{
		Node_base* _new = new Node_base;
        _new->_data = data;
        _new->_next = nullptr;
        if (n == 0)
       {
			_new->_next = _start;
            _start = _new;
        } 
        else
        {
			Node_base* _tmp = node(n - 1);
             _new->_next = _tmp->_next;
             _tmp->_next = _new;
		}
        ++_size;
	}
}

template <typename T>
void List<T>::remove(int n)
{	
	try
	{
		if (n >= _size)
		throw std::runtime_error("\n-> List index out of bound. ");
	} 
	catch (const std::runtime_error &e) 
	{
		std::cerr << e.what();
	}	
    Node_base* _this_node;
    if (n == 0)
   {
		_this_node = _start;
        _start = _this_node->_next;
	} 
    else
   {
		Node_base* _prev_node = node(n - 1);
        _this_node = _prev_node->_next;
        _prev_node->_next = _this_node->_next;
    }
    delete _this_node;
     --_size;
}

template <typename T>
void List<T>::display() const
{
	Node_base* _tmp = _start;
    int num = 0;
    std::cout << "\n" << std::endl;
    while (_tmp != nullptr)
    {
		std::cout << "(" << num << ") ";
        std::cout << _tmp->_data;
         //std::cout << endl;
		_tmp = _tmp->_next;
		++num;
     }
}

// print to file.txt
template <typename T>
void List<T>::OutputToFile()
{
	std::ofstream fout("file.txt");
	if (fout)
	{  
		Node_base* _tmp = _start;
		int num = 0;
		while (_tmp != nullptr)
		{
			fout << "(" << num << ") ";
			fout << _tmp->_data;
			fout << std::endl;
			_tmp = _tmp->_next;
			++num;
		}
		fout.close();
	}
	else
		std::cout <<  "\n-> Error creating file!" << std::endl; 
}

template <typename T>  
void List<T>::clear()
{
	Node_base* _tmp;
    while (_start != nullptr)
    {
		_tmp = _start->_next;
        delete _start;
        _start = _tmp;
	}
    _size = 0; 
	std::cout << "\n-> Memory cleared (list deleted)";
    std::cout << "\n-> Is base empty? (true/false) " << isempty() << std::endl;
} 

template <typename T>
int List<T>::find(const T& Object) const
{
	Node_base* _tmp = _start;
    int num = 0;
    while (_tmp != nullptr)
    {
		if (_tmp->_data == Object)
			return num;
        _tmp = _tmp->_next;
        ++num;
    }
        return 0;
}
 
template <typename T>   
int List<T>::size() const
{
	return _size;
}

template <typename T> 
bool List<T>::isempty() const
{
	return !_size;
}
