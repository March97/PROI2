#include <iostream>
#include "Container.h"

template <typename T>
Container<T>::Container()
{
    data_=new T[8];
    size_=8;
    numofelements_=0;
}

template <typename T>
Container<T>::~Container()
{
    delete [] data_;
}

template class Container<int>;
template class Container<float>;
template class Container<std::string>;
template class Container<Restaurant>;
template class Container<RestaurantChain>;
