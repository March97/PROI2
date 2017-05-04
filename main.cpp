#include <cassert>
#include <iostream>

//#include "RestaurantChain.h"
#include "Container.h"

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

    //Container

    //konstruktor domyslny
    Container<Restaurant> contr;
    assert(contr.size()==8);
    assert(contr.numofelements()==0);

    Container<RestaurantChain> contc;
    assert(contc.size()==8);
    assert(contc.numofelements()==0);

    Container<int> contint;
    assert(contint.size()==8);
    assert(contint.numofelements()==0);

    Container<float> contfloat;
    assert(contfloat.size()==8);
    assert(contfloat.numofelements()==0);

    Container<char> contchar;
    assert(contchar.size()==8);
    assert(contchar.numofelements()==0);

    Container<std::string> conts;
    assert(conts.size()==8);
    assert(conts.numofelements()==0);

    //push
    int inta=5;
    Container<int> contp;
    for(int i=0; i<2000000; ++i)
    {
        contp.push(inta);
    }
    assert(contp.numofelements()==2000000);
    assert(contp.size()==2097152);

    //konstruktor kopiujacy
    Container<int> copyint(contp);
    assert(copyint.numofelements()==contp.numofelements());
    assert(copyint.size()==contp.size());

    //del
    for(int i=0; i<2000000; ++i)
    {
        contp.del();
    }
    assert(contp.numofelements()==0);
    assert(contp.size()==2097152);

    //get
    //Container<int> contintget={1, 2, 3, 4};
    Container<int> contintget;
    contintget.push(0);
    contintget.push(0);
    contintget.push(0);
    contintget.push(0);

    contintget.get(0)=4;
    contintget.get(1)=5;
    contintget.get(2)=6;
    contintget.get(3)=7;

    assert(contintget.get(0)==4);
    assert(contintget.get(1)==5);
    assert(contintget.get(2)==6);
    assert(contintget.get(3)==7);

    //+=
    contintget+=8;
    assert(contintget.get(0)==4);
    assert(contintget.get(1)==5);
    assert(contintget.get(2)==6);
    assert(contintget.get(3)==7);
    assert(contintget.get(4)==8);
    //[]
    assert(contintget[4]==8);
    //--
    contintget--;
    assert(contintget[0]==4);
    assert(contintget[1]==5);
    assert(contintget[2]==6);
    assert(contintget[3]==7);

    //== !=
    Container<int> z1, z2;
    z1.push(0);
    z1.push(1);
    z1.push(2);
    z2.push(0);
    z2.push(1);
    z2.push(2);
    assert(z1==z2);
    assert(!(z1!=z2));

    z1.remove(1);
    assert(z1[0]==0);
    assert(z1[1]==2);

    //=
    z1=z2;
    assert(z1==z2);

    std::cout<<"Tests are finished!"<<std::endl;

    return 0;
//#endif // DEBUG
}
