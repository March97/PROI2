#include <cassert>
#include <iostream>

#include "RestaurantChain.h"

int main()
{
    std::cout << "Hello world!" << std::endl;

//#ifdef DEBUG
    Restaurant a("Programistyczna 13", "Dominik Marchewka");
    assert(a.address()=="Programistyczna 13");
    assert(a.manager()=="Dominik Marchewka");
    assert(a.seats()==0);
    assert(a.employees()==0);
    assert(a.incomes()==0);

    Restaurant b("Pesymistyczna 24", "Jan Kowalski", 30, 10, 30000);
    Restaurant c("Pesymistyczna 24", "Jan Kowalski", 30, 10, 30000);

    assert(a!=b);
    assert(b==c);

    assert(b>=c);
    assert(b<=c);

    assert(!(b>c));
    assert(!(b<c));

    //operatory pre i post inkrementacji i dekrementacji
    ++a;
    assert(a.employees()==1);
    --a;
    assert(a.employees()==0);
    a++;
    assert(a.seats()==1);
    a--;
    assert(a.seats()==0);

    Restaurant d=Restaurant::together(b,c);
    assert(d==(b+c));

    assert((d=d)==d);
    assert((a=d)==d);

    //metody

    assert(b.averageincomes(b.incomes(), b.employees())==3000);


    //RestaurantChain
    RestaurantChain chain ("Testowa Siec");

    chain.addRestaurant(a);
    assert(chain.numofrestaurants()==1);
    assert(chain.chainincomes()==60000);
    assert(chain.numofemployees()==20);

    chain.addRestaurant(b);
    assert(chain.numofrestaurants()==2);
    assert(chain.chainincomes()==90000);
    assert(chain.numofemployees()==30);

    chain.addRestaurant(c);
    assert(chain.numofrestaurants()==3);
    assert(chain.chainincomes()==120000);
    assert(chain.numofemployees()==40);

    chain.addRestaurant(d);
    assert(chain.numofrestaurants()==4);
    assert(chain.chainincomes()==180000);
    assert(chain.numofemployees()==60);

    std::cout<<"Tests are finished!"<<std::endl;

    return 0;
//#endif // DEBUG
}
