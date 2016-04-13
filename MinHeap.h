//
// Created by zoolsher on 16/4/13.
//

#ifndef LIBEVENTSTD_MINHEAP_H
#define LIBEVENTSTD_MINHEAP_H

#include <cstdio>

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
    void sort();
    void print();
};


#endif //LIBEVENTSTD_MINHEAP_H
