#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cstring>
#include <string>

template <class T>
class node
{
 public:
 node():next(nullptr),maxSize(5),numElements(0),data(new T[maxSize]){memset(data,0,maxSize*sizeof(T));}
 node(int value):next(nullptr),maxSize(value),numElements(0),data(new T[maxSize]){memset(data,0,maxSize*sizeof(T));}
  ~node();
  void setNext(node *nextNode){next = nextNode;}
  node* getNext(){return next;}
  void addBack(T value);
  bool search(T value);
  bool remove(T value);
  int getNumElements(){return numElements;}
  T& operator[](int index);
  std::string print();
  template <class U>
    friend std::ostream& operator<< (std::ostream &out,node<U> &n);
 private:
  node* next;
  int maxSize;
  int numElements;
  T *data;
};

#include "node.cpp"

#endif
