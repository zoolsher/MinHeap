//
// Created by zoolsher on 16/4/14.
//

#ifndef HELLO_NODE_H
#define HELLO_NODE_H

#include <cstddef>

template <class K,class V>
struct Node{
    Node<K,V> *leftChild;
    Node<K,V> *rightChild;
    K key;
    V value;
    Node(K key,V value):leftChild(NULL),rightChild(NULL),key(key),value(value){};
};


#endif //HELLO_NODE_H
