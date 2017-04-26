#include <iostream>
#include "Container.h"

//Konstruktory
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

//Destruktor
template <typename T>
Container<T>::~Container()
{
    delete[] data_;
}

//Metody
template <typename T>
Container<T> &Container<T>::push(T source)
{
    if (numofelements_+1>=size_)
    {
        unsigned int newsize_;
        newsize_=2*size_;

        T *tmp;
        tmp=new T[newsize_];

        size_=newsize_;

        for(unsigned int i=0; i<numofelements_; ++i)
        {
            tmp[i]=data_[i];
        }

        delete[] data_;
        data_=tmp;
    }

    data_[numofelements_+1]=source;
    numofelements_++;

    return *this;
}

//Operatory
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
