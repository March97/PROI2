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
Container<T>::Container(Container &&source)
{
    size_=source.size();
    numofelements_=source.numofelements();
    data_=std::move(source.data_);
}

template <typename T>
Container<T>::~Container()
{
    delete[] data_;
}

template <typename T>
Container<T> &Container<T>::operator=(Container &&source)
{
    if (this!=&source)
    {
        delete[] data_;
        size_=source.size_;
        numofelements_= source.numofelements_;
        data_=std::move(source.data_);
    }
    return *this;
}

template class Container<int>;
template class Container<float>;
template class Container<char>;
template class Container<std::string>;
template class Container<Restaurant>;
template class Container<RestaurantChain>;
