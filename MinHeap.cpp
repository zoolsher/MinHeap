//
// Created by zoolsher on 16/4/13.
//
#include "MinHeap.h"
#include <iostream>

template <class T>
inline void swap(T *a,T *b){
    T t = *a;
    *a = *b;
    *b = t;
}

template <class T>
MinHeap<T>::MinHeap(){
    new (this)MinHeap(30);
}

template <class T>
MinHeap<T>::MinHeap(int capacity){
    this->mSize = 0;
    this->mCapacity = capacity;
    this->mHeap = new T[mCapacity];
}

template <class T>
MinHeap<T>::~MinHeap(){
    this->mHeap = 0;
    this->mCapacity = 0;
    delete[] this->mHeap;
}


//TODO this can be better profm
template <class T>
int MinHeap<T>::getIndex(T data) {
    for(int i = 0; i<this->mSize;i++){
        if(data == this->mHeap[i]){
            return i;
        }
    }
    return -1;
}

template <class T>
void MinHeap<T>::manualHeap(int start) {
    if(start*2+1>=this->mSize){
        return;
    }
    int *cur = &this->mHeap[start];
    if(start*2+2>=this->mSize){
        // got left no right
        int *left = &this->mHeap[start*2+1];
        if(*left<*cur){
            swap(cur,left);
            return;
        }else{
            return;
        }
    }
    int *left =  &this->mHeap[start * 2 + 1] ;
    int *right =  &this->mHeap[start * 2 + 2] ;
    if(*left>*cur){
        if(*cur>*right){
            swap(right,cur);
            manualHeap(start*2+2);
        }
    }else{
        if(*left >*right){
            swap(right,cur);
            manualHeap(start*2+2);
        }else{
            swap(left,cur);
            manualHeap(start*2+1);
        }
    }

}


template <class T>
void MinHeap<T>::print() {
    for(int i = 0;i<this->mSize;i++){
        cout<<this->mHeap[i]<<" ";
    }
}

template <class T>
void MinHeap<T>::setHeap(T *arr, size_t s) {
    int len = (int)s/sizeof(T);
    this->mSize = len;
    this->mHeap = arr;
}

template <class T>
void MinHeap<T>::sort() {
    int start = this->mSize/2;
    do{
        this->manualHeap(start);
    }while(start--);
}

template <class T>
int MinHeap<T>::remove(T data) {
    return 0;
}

template <class T>
int MinHeap<T>::pop(){
    if(this->mSize == 1){
        this->mSize = 0;
        int val = *this->mHeap;
        return val;
    }
    int *last = &this->mHeap[this->mSize -1];
    int *head = &this->mHeap[0];
    int val = *head;
    swap(last,head);
    this->mSize--;
    this->manualHeap(0);
    return val;
}






