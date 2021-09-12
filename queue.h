#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    private:
        int* array;
        int capacity;
        int front, back;
    public:
    QueueArray();
    void enqueue(int data);
    int dequeue();
    void display();
};

template <class T>
QueueArray<T>::QueueArray()
{
    QueueArray(0);
}

template <class T>
QueueArray<T>::QueueArray(int _capacity)
{
    this->capacity = _capacity;
    this->front = this->back = -1;
    this->array = new T[_capacity];
}

template <class T>
void QueueArray<T>::enqueue(int data)
{
    if(is_full()) resize();
    reat = next(rear);
    array[rear] = data;
}

template <class T>
void QueueArray<T>::dequeue(int data)
{
    if(is_empty()) throw("is empty");
    front = next(front);
}

template <class T>
void QueueArray<T>::display()
{    
    for (int i = 0; i < size(); i++)
        cout<<(*this)[i]<<",";        
    cout<<endl;
}

