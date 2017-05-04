/**
*\file Container.h
*\author Dominik Marchewka
*\date 04.05.2017r.
*\brief Szablonowa klasa kontenerowa
*
*Klasa przechowuje blok pamieci, powiekszany 2-krotnie w przypadku przepelnienia miejsca.
*Klasa obsluguje dodawanie nowych elementow, usuwanie, zwracanie elementow,
*operatory przypisania, dodawania, dekrementacji, porownania.
*/
#include <iostream>
#include "RestaurantChain.h"

template <typename T>
class Container
{
private:
    //Rozmiar kontenera
    unsigned int size_; /*!< Wielkosc kontenera*/

    //Liczba elementow
    unsigned int numofelements_; /*!< Ilosc elementow w kontenerze*/

    //Dane
    T *data_; /*!< Dane przechowywane w kontenerze*/

public:
    //Konstruktory i destruktory

    //Konstruktor domyslny
    /**
    *\brief Konstruktor domyslny
    *
    *Konstruktor rezerwuje miejsce dla 8 zmiennych,
    *zmienna size_ ustawia na 8,
    *zmienna numofelements_ ustawia na 0.
    */
    Container();

    //Konstruktor kopiujacy
    /**
    *\brief Konstruktor kopujacy
    *\param source Kontener do skopiowania
    *
    *Konstruktor kopiuje kontener podany jako argument funkcji.
    */
    Container(const Container &source);

    //Konstruktor przesuwajacy
    /**
    *\brief Konstruktor przesuwajacy
    *\param Kontener do przesuniecia
    *
    *Konstruktor przesuwa kontener podany jako argument funkcji, za pomoca standardowej funkcji move.
    */
    Container(Container &&source);

    //Destruktor
    /**
    *\brief Destruktor domyslny
    *
    *Destruktor zwalnia wczesniej przydzielona pamiec.
    */
    ~Container();

    //Metody
    //Dodanie nowego elementu
    /**
    *\brief Dodanie nowego elementu
    *\param source Element, ktory zostanie dodany
    *\return Referencja na obiekt
    *
    *Metoda dodaje element na koncu kontenera,
    *w przypadku przeladowania kontenera zwieksza jego
    *pojemnosc 2-krotnie.
    */
    Container &push(T source);

    //Usuniecie elementu
    /**
    *\brief Usuniecie elementu
    *\return Usuniety element
    *
    *Metoda usuwa ostatni element w kontenerze.
    */
    T del();

    //Zwraca dany element
    /**
    *\brief Pobranie wartosci elementu
    *\param index Numer pola, na ktorym znajduje sie element do pobrania, liczony od 0.
    *\return Wartosc elementu
    *
    *Przyklad:
    *int a=b.get(0);
    */
    T get(unsigned int index) const;

    /**
    *\brief Pobranie wartosci elementu
    *\param index Numer pola, na ktorym znajduje sie element do pobrania, liczony od 0.
    *\return Referecja na element
    *
    *Przyklad:
    *b.get(0)=0;
    */
    T &get(unsigned int index);

    //usuwa dany element
    /**
    *\brief Usuniecie danego elementu
    *\param source Wartosc do usuniecia
    *\return Referencja na element
    *
    *Metoda usuwa pierwszy element o poodanej wartosci
    */
    Container &remove(T source);

    //zwraca wielkosc kontenera
    /**
    *\brief Sumuje ilosc elementow
    *\return unsigned int Suma elementow
    *
    *W przypadku standardowej inicjalizacji metoda zwraca ilosc elementow w kontenerze.
    *Dla klasy Restaurant metoda sumuje liczbe pracownikow kazdej restauracji.
    *Dla klasy RestaurantChain metoda sumuje ilosc restauracji.
    */
    unsigned int sum();

    //Operatory
    //operator przypisania
    /**
    *\brief Operator przypisania
    *\param source Kontener do przypisania
    *\return Referencja na obiekt
    */
    Container &operator=(Container &source);

    //Operator przesuwajacy przypisania
    /**
    *\brief Operator przypisania z przesunieciem
    *\param source Kontener do przesuniecia
    *\return Referencja na obiekt
    */
    Container &operator=(Container &&source);

    //zwraca  wartosc elementu
    /**
    *\brief Pobranie wartoœci elementu
    *\param index Numer elementu, liczony od 0
    *
    *Wykorzystuje metode get.
    */
    T operator[](unsigned int index) const;

    //zwraca wskaznik na dany element
    /**
    *\brief Pobranie referencji na element
    *\param index Numer elementu, liczony od 0
    *
    *Wykorzystuje metode get.
    */
    T &operator[](unsigned int index);

    //dodaje element na koniec push(T source)
    /**
    *\brief Dodanie elementu na koniec
    *\param source Wartosc elementu
    *
    *Dodaje element na koniec kontenera, wykorzystuje metode push(T source).
    */
    Container &operator+=(T source);

    //usuwa ostatni element del()
    /**
    *\brief Usuwa ostatni element
    *
    *Usuwa ostatni element kontnera, wykorzystuje metode del().
    */
    T operator--(int);

    //==
    /**
    *\brief Porownanie kontenerow
    *\param source Kontener do porownania
    *\retval true Kontenery sa rowne
    *\retval false Kontenery sa rozne
    *
    *Kontenery sa rowne kiedy liczba ich elementow jest rowna
    i wsystkie elementy kontenerow sa jednakowe.
    */
    bool operator==(Container &source);

    // !=
    /**
    *\brief Porownanie kontenerow
    *\param source Kontener do porownania
    *\retval true Kontenery sa rozne
    *\retval false Kontenery sa rowne
    *
    *Kontenery sa rozne kiedy liczba ich elementow jest rozna
    i nie wsystkie elementy kontenerow sa jednakowe. Wykorzystuje operator '=='.
    */
    bool operator!=(Container &source);

    //Wlasciwosci
    /**
    *\brief Zwracanie wielkosci kontenera
    */
    inline unsigned int size() {return size_;}

    /**
    *\brief Zwracanie liczby elementow kontenera
    */
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

template <typename T>
unsigned int Container<T>::sum()
{
    return numofelements_;
}

//funkcja specjalizowana dla restauracji
template<>
unsigned int Container<Restaurant>::sum()
{
    unsigned int suma=0;

    for (unsigned int i=0; i<numofelements_; ++i)
    {
        suma=data_[i].employees();
    }

    return suma;
}

//funkcja specjalizowana dla restaurnatchain
template<>
unsigned int Container<RestaurantChain>::sum()
{
    unsigned int suma=0;

    for (unsigned int i=0; i<numofelements_; ++i)
    {
        suma=data_[i].numofrestaurants();
    }

    return suma;
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

