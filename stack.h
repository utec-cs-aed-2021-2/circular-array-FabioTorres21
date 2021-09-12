#include "circulararray.h"

template <typename T>
class StackArray : public CircularArray<T> { 
    private:
        int* array;
        int capacity;
        int size;
    public:
        StackArray();
        void push(T data);
        int pop();
        void display();
};

template <class T>
StackArray<T>::StackArray()
{
    StackArray(0);
}

template <class T>
StackArray<T>::StackArray(int _capacity)
{
    this->capacity = _capacity;
    this->size = -1;
    this->array = new T[_capacity];
}

template <class T>
void StackArray<T>::push(T data)
{
    push_back(data);
}

template <class T>
int StackArray<T>::pop(){
    return pop_back();
}

template <class T>
void StackArray<T>::display()
{    
    for (int i = 0; i < size(); i++)
        cout<<(*this)[i]<<",";        
    cout<<endl;
}