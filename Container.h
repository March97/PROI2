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

    //Destruktor
    ~Container();

    //Wlasciwosci
    inline unsigned int size() {return size_;}
    inline unsigned int numofelements() {return numofelements_;}
};

