#ifndef LIST_H
#define LIST_H

template <typename T>
class List
{
private:
    typedef T* pT;
 
    struct Node_base 
    {
		T _data;
        Node_base* _next;
    };
    typedef Node_base* pNb;
 
    Node_base* _start;
    int _size;
 
    Node_base* node(int n)
    {
        Node_base* _tmp = _start;
        for (int i = 0; i < n; ++i)
            _tmp = _tmp->_next;
        return _tmp;
    }
 
public:
    List() : _start(nullptr),_size(0)
    {}
    ~List()
    {
        clear();
    }

    void push_back(const T& data);    
    void insert(const int n, const T& data);
    void remove(int n);
    void display() const;      
    void OutputToFile();     // print to file.txt
    void clear();
  
    int find(const T& Object) const;
    int size() const;
  
    bool isempty() const;

};

#endif
