#include <iostream>
#include "Container.h"

template <class T>
Container<T>::Container()
{
    data_=new T[8];
    size_=8;
    numofelements_=0;
}

template <class T>
Container<T>::~Container()
{
    delete [] data_;
}

