#include <iostream>
#include <limits>
#include <string>

class Restaurant
{
private:
    std::string address_;
    std::string manager_;
    unsigned int seats_;
    unsigned int employees_;
    float incomes_;
    static float burgerprice_;

public:
    void load(); // metoda wczytujaca wszystkie parametry
    void show(); // metoda pokazujaca wszystkie parametry
    float averageincomes(float, unsigned int); // liczy srednie przychody na pracownika
    void happytime(unsigned int); //czas promocji zwieksza przychody zaleznie od czasu e godzinach (argument metody), liczby miejsc i pracownikow

    //Konstruktor i Destruktor
    Restaurant(std::string address="", std::string manager="", unsigned int seats=0, unsigned int employees=0, float incomes=0);
    ~Restaurant();

    //operatory porownania
    bool operator==(Restaurant &r);
    bool operator!=(Restaurant &r);
    bool operator<(Restaurant &r);
    bool operator<=(Restaurant &r);
    bool operator>(Restaurant &r);
    bool operator >=(Restaurant &r);

    //operatory pre i post inkrementacji i dekrementacji
    Restaurant &operator++();
    Restaurant &operator--();
    Restaurant &operator++(int);
    Restaurant &operator--(int);


    inline Restaurant &operator+(Restaurant &r) {return together(*this, r);}

    Restaurant &operator=(Restaurant &r);

    //operatory strumienia
    friend std::ostream &operator<<(std::ostream &output, const Restaurant &r);
    friend std::istream &operator>>(std::istream &input, Restaurant &r);


    //wlasciwosci
    inline std::string address() {return address_;}
    inline std::string manager() {return manager_;}
    inline unsigned int seats() {return seats_;}
    inline unsigned int employees() {return employees_;}
    inline float incomes() {return incomes_;}

    //metody
    static Restaurant &together(Restaurant &a, Restaurant &b); //metoda laczaca dwie restauracje

};
