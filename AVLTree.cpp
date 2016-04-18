//
// Created by zoolsher on 16/4/18.
//

#include "AVLTree.h"


template <class K,class V>
void AVLTree<K,V>::insert(Node<K,V> *newNode){
    this->head = this->insert(newNode,this->head);
};

template <class K,class V>
Node<K,V>* AVLTree<K,V>::insert(Node<K, V> *newNode, Node<K, V> *curHead) {
    if(curHead == NULL){
        newNode->height = height(newNode);
        return newNode;
    }else{
        if(curHead->key<newNode->key){
            curHead->rightChild = this->insert(newNode,curHead->rightChild);
            if(height(curHead->leftChild)-height(curHead->rightChild)==-2){
                if(newNode->key>curHead->rightChild->key) {
                    curHead = this->rotateRR(curHead);
                }else {
                    curHead = this->rotateRL(curHead);
                }
            }

        }else{
            curHead->leftChild = this->insert(newNode,curHead->leftChild);
            if(height(curHead->leftChild)-height(curHead->rightChild)==2){
                if(newNode->key<curHead->leftChild->key) {
                    curHead = this->rotateLL(curHead);
                }else {
                    curHead = this->rotateLR(curHead);
                }
            }
        }
        curHead->height = height(curHead);
        return curHead;
    }
};

template <class K,class V>
std::vector<V> AVLTree<K,V>::midList() {
    std::vector<V> t(0);
    midList(t,this->head);
    return t;
}

template <class K,class V>
void AVLTree<K,V>::midList(std::vector<V> &v, Node<K, V> *curHead) {
    if(curHead == NULL){
        return;
    }else{
        this->midList(v,curHead->leftChild);
        v.push_back(curHead->value);
        this->midList(v,curHead->rightChild);
        return;
    }
}


template <class K,class V>
Height AVLTree<K,V>::height(Node<K, V> *curHead) {
    if(NULL == curHead){
        return -1;
    }else{
        return std::max(height(curHead->leftChild),height(curHead->rightChild))+1;
    }
}

template <class K,class V>
Node<K,V> * AVLTree<K,V>::rotateLL(Node<K,V> *node){
    Node<K,V> *newTop = node->leftChild;
    node->leftChild = newTop->rightChild;
    newTop->rightChild = node;

    node->height = height(node);
    newTop->height = height(newTop);
    return newTop;
};

template <class K,class V>
Node<K,V> * AVLTree<K,V>::rotateRR(Node<K,V> *node){
    Node<K,V> *newTop = node->rightChild;
    node->rightChild = newTop->leftChild;
    newTop->leftChild = node;

    node->height = height(node);
    newTop->height = height(newTop);
    return newTop;
};

template <class K,class V>
Node<K,V> * AVLTree<K,V>::rotateLR(Node<K,V> *node){
    node->leftChild = rotateRR(node->leftChild);
    return rotateLL(node);
};

template <class K,class V>
Node<K,V> * AVLTree<K,V>::rotateRL(Node<K,V> *node){
    node->rightChild = rotateLL(node->rightChild);
    return rotateRR(node);
};

