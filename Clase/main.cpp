#include <iostream>

using namespace std;

class test{
public :
    int x,y;
    string nume;
public:
    int operator +(test b)
    {
         return x+b.x;
    }
    void citire();
    void citire(int x,int y,string name);
    test(int a,int b,string c){x=a;y=b;nume=c;}
};
void test :: citire()
{
    cout<<"dati x si y";cin>>x>>y;cout<<endl;
}
void test :: citire(int a,int b,string name)
{
    x=a;y=b;nume=name;
}

int main()
{
    test a( 1 , 2 , "mama");
    cout<<a.nume;
    return 0;
}
