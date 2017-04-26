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

    //Konstruktor przesuwajacy
    Container(Container &&source);

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

    //Operatory
    //Operator przesuwajacy przypisania
    Container &operator=(Container &&source);

    //Wlasciwosci
    inline unsigned int size() {return size_;}
    inline unsigned int numofelements() {return numofelements_;}
    //inline T data() {return *data_;}
};

