//
// Created by zoolsher on 16/4/13.
//



#include <cstddef>
using namespace std;
template <class T>
class MinHeap {
private:
    T *mHeap;
    int mCapacity;
    int mSize;
public:
    void manualHeap(int start);
public:
    MinHeap();
    MinHeap(int capacity);
    ~MinHeap();
    void setHeap(T arr[],size_t s);
    int getIndex(T data);
    int remove(T data);
    int insert(T data);
    int pop();
    void sort();
    void print();
};


