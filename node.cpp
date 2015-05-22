#include "node.h"

template<class T>
node<T>::~node()
{
  if(data != nullptr)
    delete[] data;
}

template<class T>
std::string node<T>::print()
{
  std::string out;
  for(int i = 0; i<maxSize; i++)
    {
      out+="["+std::to_string(data[i])+"]";
    }
  return out;
}

template <class U>
std::ostream& operator<< (std::ostream &out,node<U> &n)
{
  for(int i=0; i<n.maxSize; i++)
    {
      out << " [" << n.data[i] << "]";
    }
  return out;
}

template <class T>
void node<T>::addBack(T value)
{
  data[numElements] = value;
  numElements++;
}

template <class T>
bool node<T>::search(T value)
{
  bool truth = false;
  for(int i=0; i<numElements; i++)
    {
      if(data[i] == value)
	{
	  truth = true;
	}
    }
  return truth;
}
template<class T>
bool node<T>::remove(T value)
{
  int truth = false;
  for(int i=0; i<maxSize; i++)
    {
      if(truth)
	{
	  data[i-1] = data[i];
	  data[i] = 0;
	}
      if (data[i] == value && !truth)
	{
	  data[i] = 0;
	  truth = true;
	  numElements--;
	}
    }
  return truth;
}

template <class T>
T& node<T>::operator[](const int index)
{
  if(index > maxSize-1) return data[maxSize-1];
  else if(index < 0) return data[0];
  else return data[index];
}
