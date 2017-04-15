#include <iostream>
#include <string>
#include "RestaurantChain.h"

RestaurantChain RestaurantChain::addRestaurant(Restaurant &r)
{
    this->RestaurantList_.push_back(r);
    numofrestaurants_++;
    numofemployees_+=r.employees();
    chainincomes_+=r.incomes();
    return *this;
}

void RestaurantChain::moreclients(int people, float dinnerprice)
{
    chainincomes_+=people*dinnerprice;
}

float RestaurantChain::incomesonemployee()
{
    return chainincomes_/numofemployees_;
}

void RestaurantChain::setname(std::string s)
{
    name_=s;
}

/*void RestaurantChain::load()
{
    std::cout<<"Name: "; std::getline(std::cin, name_);
    std::cout<<"Number of restaurants: "; std::cin>>numofrestaurants_;
    std::cout<<"Number of employees: "; std::cin>>numofemployees_;
    std::cout<<"Incomes: "; std::cin>>incomes_;
}

void RestaurantChain::show()
{
    std::cout<<"Name: "<<name_<<std::endl;
    std::cout<<"Number of restaurants: "<<numofrestaurants_<<std::endl;
    std::cout<<"Number of employees: "<<numofemployees_<<std::endl;
    std::cout<<"Incomes: "<<chainincomes_<<"$"<<std::endl;
}*/

RestaurantChain::RestaurantChain(std::string n, unsigned int r, unsigned int e, float i)
{
    name_=n;
    numofrestaurants_=r;
    numofemployees_=e;
    chainincomes_=i;
}

RestaurantChain::~RestaurantChain() {}

std::ostream &operator<<(std::ostream &output, const RestaurantChain &c)
{
   return output<<"Name: "<<c.name_<<std::endl
   <<"Number of restaurants: "<<c.numofrestaurants_<<std::endl<<"Number of employees: "<<c.numofemployees_<<std::endl
   <<"Incomes: "<<c.chainincomes_<<std::endl;
}

std::istream &operator>>(std::istream &input, RestaurantChain &c)
{
    return input>>c.name_>>c.numofemployees_>>c.numofrestaurants_>>c.chainincomes_;
}
