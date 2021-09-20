#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
void CircularArray<T>::push_front(T data){
    if(is_full()) throw "ERROR: The array is full";
    if(is_empty()) front = back = 0;
    else front = prev(front);
    array[front] = data;
}

template <class T>
void CircularArray<T>::push_back(T data){
    if(is_full()) throw "WARNING: The array is full";
    /*ACL: Se puede implementar resizing*/
    if(is_empty()) front = back = 0;
    else back = next(back);
    array[back] = data;
}

template <class T>
T CircularArray<T>::pop_front()
{
    if(is_empty()) throw "WARNING: The array is empty";
    T temp = array[front];
    if(front == back) front = back = -1;
    else front = next(front);
    return temp;
}

template <class T>
T CircularArray<T>::pop_back()
{
    if(is_empty()) throw "ERROR: The array is empty";
    T temp = array[back];
    if(front == back) front = back = -1;
    else back = prev(back);
    return temp;
}

template <class T>
bool CircularArray<T>::is_empty()
{
    return front == -1;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return  front == next(back) && !is_empty();
}

template <class T>
int CircularArray<T>::size()
{
    if(is_empty()) return 0;    
    return (back>=front)? back - front + 1: capacity - front + back + 1;
}

template <class T>
void CircularArray<T>::clear()
{
    front = back = -1;
}

template <class T>
void insert(T data, int pos){
    int n = CircularArray<T>::size();
    if(pos < 0 || pos > n) throw "ERROR: Index out of range";
    if(n == CircularArray<T>::capacity) throw "WARNING: The array is full";
    if(pos == 0)
        push_front(data);
    else {
        for (int i = n - 1; i >= pos; i--)
            CircularArray<T>::array[i+1] = CircularArray<T>::array[i];
        CircularArray<T>::array[pos] = data;
        CircularArray<T>::back = next(CircularArray<T>::back);
    }
}

template <class T>
T& CircularArray<T>::operator[](int pos)
{
    if(pos >= capacity) throw "ERROR: Index out of range";
    return array[(front + pos) % capacity];
}

template <class T>
bool CircularArray<T>::is_sorted()
{
    if (size() == 0) throw "ERROR: The array is empty";
    int n = size();
    for (int i = 1; i < n; i++)
        if (array[i - 1] > array[i])
            return false;
    return true;
}

template <class T>
void CircularArray<T>::sort()
{
    int tmp, pass = 0;
    if(is_sorted()) throw "WARNING: Was sorted";
    for(int i = 0; i<size(); i++) {
        for(int j = i+1; j<size(); j++)
        {
            if(array[j] < array[i]) { 
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        pass++;
    }
}

template <class T>
void CircularArray<T>::reverse()
{
    int tmp, pass = 0;
    for(int i = 0; i<size(); i++) {
        for(int j = i+1; j<size(); j++)
        {
            if(array[j] > array[i]) { 
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
        pass++;
    }
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
        /*ACL: array[i]*/
    for (int i = 0; i < capacity; i++)
    {
        cout << array[i] << " ";
    }
    cout << " "<< endl;
    return result;
}
