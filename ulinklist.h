#ifndef ULINKLIST_H_
#define ULINKLIST_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "node.h"

template <class T>
class ulinklist
{
 public:
 ulinklist():head(nullptr),maxSize(5){}
 ulinklist(int value):head(nullptr),maxSize(value){}
  ~ulinklist();  
  void insert(T value);
  bool remove(T value);
  void sort();
  bool search(T input);
  unsigned int size();
  bool empty();
  int getMaxSize(){return maxSize;}
  node<T>* front(){return head;}
  std::string print();
  template <class U>
    friend std::ostream& operator<< (std::ostream &out, ulinklist<U> &ull);
 private:
  node<T> *head;
  int maxSize;
};

#include "ulinklist.cpp"

#endif
