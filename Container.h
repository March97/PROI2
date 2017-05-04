#include <iostream>
#include "RestaurantChain.h"

template <typename T>
class Container
{
private:
    //Rozmiar kontenera
    unsigned int size_;

    //Liczba elementow
    unsigned int numofelements_;

    //Dane
    T *data_;

public:
    //Konstruktory i destruktory

    //Konstruktor domyslny
    Container();
    //Konstruktor kopiujacy
    Container(const Container &source);
    //Konstruktor przesuwajacy
    Container(Container &&source);
    //Konstruktor kupiujacy dla dowolnego ttypu
    Container(const T &source);

    //Destruktor
    ~Container();

    //Metody
    //Dodanie nowego elementu
    Container &push(T source);
    //Usuniecie elementu
    T del();
    //Zwraca dany element
    T get(unsigned int index) const;
    //Zwraca wskaznik do danego elementu
    T &get(unsigned int index);
    //usuwa dane element
    Container &remove(T source);

    //Operatory
    //operator przypisania
    Container &operator=(Container &source);
    //Operator przesuwajacy przypisania
    Container &operator=(Container &&source);
    //zwraca  wartosc elementu
    T operator[](unsigned int index) const;
    //zwraca wskaznik na dany element
    T &operator[](unsigned int index);
    //dodaje element na koniec push(T source)
    Container &operator+=(T source);
    //usuwa ostatni element del()
    T operator--(int);
    //==
    bool operator==(Container &source);
    // !=
    bool operator!=(Container &source);


    //Wlasciwosci
    inline unsigned int size() {return size_;}
    inline unsigned int numofelements() {return numofelements_;}
    //inline T data() {return *data_;}
};


//Konstruktory
template <typename T>
Container<T>::Container()
{
    data_=new T[8];
    size_=8;
    numofelements_=0;
}

template <typename T>
Container<T>::Container(const Container &source)
{
    size_=source.size_;
    numofelements_=source.numofelements_;
    data_=new T[source.size_];

    for (unsigned int i=0; i<numofelements_; ++i)
    {
        data_[i]=source.data_[i];
    }
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

    data_[numofelements_++]=source;

    return *this;
}

template <typename T>
T Container<T>::del()
{
    if(numofelements_==0)
    {
        std::string error="No item to remove";
        throw error;
    }
    return data_[--numofelements_];
}

template <typename T>
T Container<T>::get(unsigned int index) const
{
    if (index >= numofelements_)
    {
        std::string error="Too high index";
        throw error;
    }
    return data_[index];
}

template <typename T>
Container<T> &Container<T>::remove(T source)
{
    unsigned int index;
    bool found=false;

    for (index=0; index<numofelements_; index++)
    {
        if (this->data_[index]==source)
        {
            found = true;
            break;
        }
    }

    if (found==false)
    {
        std::string error="Element doesn't exist";
        throw error;
    }

    for (unsigned int j=index; j<numofelements_-1; j++)
        data_[j]=data_[j+1];

    --numofelements_;

    return *this;
}

// Zwraca wskaznik na dany element
template <typename T>
T &Container<T>::get(unsigned int index)
{
    if (index >= numofelements_)
    {
        std::string error="Too high index";
        throw error;
    }
    return data_[index];
}

//Operatory
template <typename T>
Container<T> &Container<T>::operator=(Container &source)
{
    if (*this!=source)
    {
        size_=source.size_;
        numofelements_=source.numofelements_;
        data_=new T[source.size_];

        for (unsigned int i=0; i<source.numofelements_; i++)
            data_[i]=source.data_[i];
    }
    return *this;
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

template <typename T>
T Container<T>::operator[](unsigned int index) const
{
    return this->get(index);
}

template <typename T>
T &Container<T>::operator[](unsigned int index)
{
    return this->get(index);
}

template <typename T>
Container<T> &Container<T>::operator+=(T source)
{
    this->push(source);
    return *this;
}

template <typename T>
T Container<T>::operator--(int)
{
    return this->del();
}
template <typename T>
bool Container<T>::operator==(Container<T> &source)
{
    if(numofelements_!=source.numofelements()) return false;

    for (unsigned int i=0; i<source.numofelements(); i++)
            if (data_[i]!=source[i]) return false;

    return true;
}

template <typename T>
bool Container<T>::operator!=(Container<T> &source)
{
    return !(*this==source);
}


template class Container<int>;
template class Container<float>;
template class Container<char>;
template class Container<std::string>;
template class Container<Restaurant>;
template class Container<RestaurantChain>;

