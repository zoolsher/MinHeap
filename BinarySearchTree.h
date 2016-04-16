//
// Created by zoolsher on 16/4/15.
//

#ifndef HELLO_BINARYSEARCHTREE_H
#define HELLO_BINARYSEARCHTREE_H
#include <vector>
#include <cstddef>
#include <iostream>
#include "Node.h"
using namespace std;
template <class K,class V>
class BinarySearchTree {
public:
    Node<K,V>* head;
public:
    BinarySearchTree():head(NULL){};
    int getLength();
    void insert(Node<K,V> *node);
    vector<V> search(K min,K max);
    void print();
    void remove(K key,V value);
private:
    int getLength(Node<K,V> *cur);
    void insert(Node<K,V> *node,Node<K,V> *curHead);
    void print(Node<K,V> *cur, vector<Node<K,V>*> *v);
    void search(K min,K max,vector<V> *v,Node<K,V> *curHead);
    Node<K,V>* remove(K key,V value,Node<K,V> *curHead);
    inline Node<K,V>* findMin(Node<K,V> *curHead);
};



#endif //HELLO_BINARYSEARCHTREE_H
