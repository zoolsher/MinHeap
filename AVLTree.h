//
// Created by zoolsher on 16/4/18.
//

#ifndef HELLO_AVLTREE_H
#define HELLO_AVLTREE_H

#include "Node.h"
#include <vector>

template <class K,class V>
class AVLTree {
public:
    void insert(Node<K,V> *newNode);
    void remove();
    AVLTree():head(NULL){};
    Node<K,V> *head;
    std::vector<V> midList();
private:
    void midList(std::vector<V> &v,Node<K,V> *curHead);
    Node<K,V>* insert(Node<K,V> *newNode, Node<K,V>*curHead);
    Height height(Node<K,V> *curHead);
    Node<K,V>* rotateLL(Node<K,V> *node);
    Node<K,V>* rotateRR(Node<K,V> *node);
    Node<K,V>* rotateLR(Node<K,V> *node);
    Node<K,V>* rotateRL(Node<K,V> *node);
};




#endif //HELLO_AVLTREE_H
