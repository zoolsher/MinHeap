//
// Created by zoolsher on 16/4/15.
//

#include "BinarySearchTree.h"
template <class K, class V>
int BinarySearchTree<K,V>::getLength() {
    return this->getLength(this->head);
}

template <class K,class V>
int BinarySearchTree<K,V>::getLength(Node<K, V> *cur) {
    if(cur!=NULL){
        return getLength(cur->leftChild) + getLength(cur->rightChild) + 1;
    }else{
        return 0;
    }
}

template <class K,class V>
void BinarySearchTree<K,V>::insert(Node<K, V> *node,Node<K,V> *curHead) {
    if(curHead->key>=node->key){
        if(curHead->leftChild == NULL){
            curHead->leftChild = node;
        }else{
            this->insert(node,curHead->leftChild);
        }
    }else{
        if(curHead->rightChild == NULL){
            curHead->rightChild = node;
        }else{
            this->insert(node,curHead->rightChild);
        }
    }

}

template <class K,class V>
void BinarySearchTree<K,V>::insert(Node<K, V> *node) {

    if(this->head == NULL){
        this->head = node;
    }else{
        this->insert(node,head);
    }
}

template <class K, class V>
void BinarySearchTree<K,V>::print(){
    vector<Node<K,V>*> res;
    this->print(this->head, &res);

    for(typename vector<Node<K,V>*>::size_type i=0;i<res.size();i++){
        Node<K,V>* re = res[i];
        cout<<re->key<<endl;
    }
};

template <class K, class V>
void BinarySearchTree<K,V>::print(Node<K, V> *cur, vector<Node<K,V>*> *v) {

    if(cur==NULL){
        return;
    }

    print(cur->leftChild,v);
    v->push_back(cur);
    print(cur->rightChild,v);
}

template <class K,class V>
vector<V> BinarySearchTree<K,V>::search(K min, K max) {
    vector<V> v(0);

    if(this->head == NULL){
        return v;
    }

    this->search(min,max,&v,this->head);
    return v;
}

template <class K,class V>
void BinarySearchTree<K,V>::remove(K key,V value) {
    this->head = this->remove(key, value,this->head);
}

template <class K,class V>
inline Node<K,V>* BinarySearchTree<K,V>::findMin(Node<K,V> *curHead){
    Node<K,V> *temp = curHead;
    while(temp->leftChild!=NULL){
        temp = temp->leftChild;
    }
    return temp;
};


template <class K,class V>
Node<K,V>* BinarySearchTree<K,V>::remove(K key,V value,Node<K,V> *curHead){
    if(curHead == NULL){
        return curHead;
    }
    if(curHead->key==key){
        if(curHead->leftChild==NULL && curHead->rightChild==NULL){
            return NULL;
        }else{
            if(curHead->leftChild!=NULL && curHead->rightChild!=NULL){
                Node<K,V> *min = this->findMin(curHead->rightChild);
                min->rightChild = this->remove(min->key,min->value,curHead->rightChild);
                min->leftChild = curHead->leftChild;
                return min;
            }else{
                return curHead->rightChild==NULL?curHead->leftChild:curHead->rightChild;
            }
        }
    }else{
        if(curHead->key>key){
            curHead->leftChild = this->remove(key,value,curHead->leftChild);
        }else{
            curHead->rightChild = this->remove(key,value,curHead->rightChild);
        }
        return curHead;
    }
};


template <class K,class V>
void BinarySearchTree<K,V>::search(K min,K max,vector<V> *v,Node<K,V> *curHead) {
    if(curHead == NULL){
        return;
    }
    if(curHead->key>=min&&curHead->key<=max){
        v->push_back(curHead->value);
    }
    if(curHead->key>=min){
        this->search(min,max,v,curHead->leftChild);
    }
    if(curHead->key<=max){
        this->search(min,max,v,curHead->rightChild);
    }
}




