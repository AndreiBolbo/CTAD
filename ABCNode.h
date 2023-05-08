#ifndef ABC_ABCNODE_H
#define ABC_ABCNODE_H
#include<iostream>
using namespace std;
template<typename T>
class ABC;

template<class T>
class ABCNode{
private:
    T info;
    ABCNode<T>* left;
    ABCNode<T>* right;
public:

    ABCNode(T info) : info(info) {this->left = nullptr, this->right = nullptr;}

    ABCNode(T info, ABCNode<T> *left, ABCNode<T> *right) : info(info), left(left), right(right) {}

    friend class ABC<T>;
};

#endif //ABC_ABCNODE_H
