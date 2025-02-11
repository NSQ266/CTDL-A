#include<bits/stdc++.h>
#include "Node.cpp" 
using namespace std;

template <class T>
class SListIterator {
    Node<T> *curr;
public:
    SListIterator() {
        curr = nullptr;
    }
    SListIterator(Node<T> *curr) {
        this->curr = curr;
    }
    Node<T> *getCurr() {
        return curr;
    }
    SListIterator<T> &operator=(SListIterator<T> p) {
        this->curr = p.getCurr();
        return *this;
    }
    bool operator!=(SListIterator<T> p) {
        return curr != p.getCurr();
    }
    SListIterator<T> operator++() {
        curr = curr->getNext();
        return *this;
    }
    SListIterator<T> operator++(int) {
        Node<T> *temp = curr;
        curr = curr->getNext();
        return temp;
    }
    T &operator*() {
        return curr->getElement();
    }
};


