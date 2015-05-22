#include "ulinklist.h"

template<class T>
ulinklist<T>::~ulinklist()
{
  node<T> *prev = new node<T>();
  while(head != nullptr)
    {
      prev = head;
      head = head->getNext();
      delete prev;
    }
  delete prev;
}

template<class T>
void ulinklist<T>::insert(T value)
{
  if (head == nullptr)
    {
      node<T> *tmp = new node<T>(maxSize);
      head = tmp;
      tmp->addBack(value);
    }
  else
    {
      node<T> *itr = head;
      while(itr->getNext() != nullptr)
	{
	  itr = itr->getNext();
	}
      if(itr->getNumElements() < maxSize)
	{
	  itr->addBack(value);
	}
      else
	{
	  node<T> *nn = new node<T>(maxSize);
	  itr->setNext(nn);
	  int half = maxSize/2;
	  int loc = (maxSize - half);
	  for(int x=0; x<half; x++)
	    {
	      T tmp = (*itr)[loc];
	      nn->addBack(tmp);
	      itr->remove(tmp);
	    }
	  nn->addBack(value);
	}
    }
}

template<class T>
bool ulinklist<T>::remove(T value)
{
  bool truth = false;
  if(head == nullptr) return truth;
  node<T> * tmp = head;
  node<T> *prev;
  while(tmp != nullptr)
    {
      if(tmp->remove(value))
	{
          truth = true;
	  if(tmp->getNumElements() == 0)
	    {
	      if(tmp == head)
		{
		  head = tmp->getNext();
		}
	      else
		prev->setNext(tmp->getNext());
	      delete tmp;
	    }
	  break;
	}
      prev = tmp;
      tmp = tmp->getNext();      
    }
  return truth;
}

template<class T>
void ulinklist<T>::sort()
{
  std::vector<T> tmp;
  node<T> *itr = head;
  while(itr != nullptr)
    {
      int val = itr->getNumElements();
      for(int i =0; i <val;i++)
	{
	  tmp.push_back((*itr)[0]);
	  this->remove((*itr)[0]);
	}
      itr = head;
    }
  std::sort(tmp.begin(),tmp.end());
  for(unsigned int i = 0; i<tmp.size(); i++)
    {
      this->insert(tmp[i]);
    }
}

template<class T>
bool ulinklist<T>::search(T input)
{
  node<T> *itr = head;
  bool found = false;
  while (itr != nullptr)
    {
      found = itr->search(input);
      itr = itr->getNext();
    }
  return found;
}

template<class T>
unsigned int ulinklist<T>::size()
{
  int numElements = 0;
  node<T> *tmp = head;
  while(tmp != nullptr)
    {
      for(int i=0; i<tmp->getNumElements(); i++)
	{
	  numElements++;
	}
      tmp = tmp->getNext();
    }
  return numElements;
}

template<class T>
bool ulinklist<T>::empty()
{
  if(head == nullptr)
    return true;
  return false;
}

template<class T>
std::string ulinklist<T>::print()
{
  node<T> *tmp = head;
  std::string out;
  while(tmp != nullptr)
    {
      if(tmp->getNext() != nullptr)
        out+=tmp->print()+"-->";
      else
        out+=tmp->print();
      tmp = tmp->getNext();
    }
  return out;
}

template<class U>
std::ostream& operator<<(std::ostream &out, ulinklist<U> &ull)
{
  node<U> *tmp = ull.head;
  while(tmp != nullptr)
    {
      out << *tmp << std::endl;
      tmp = tmp->getNext();
    }
  return out;
}
