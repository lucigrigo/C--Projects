#include <iostream>
#include <fstream>

using namespace std;

int N,K,C[101],treapta,S;

void Citire();
void Zen1();
void Zen2();

int main()
{
    Citire();
    while((treapta+K)<N)
    {
        Zen1();
    }
    Zen2();

    ofstream out("zen.out");
    out<<S;
    out.close();
    return 0;
}

void Citire()
{
    ifstream in("zen.in");
    in>>N>>K;
    for(int i=0;i<N;i++)
    {
        in>>C[i];
    }
    in.close();
}

void Zen1()
{
    int cost=10000,h;
    for(int i=treapta;i<treapta+K-1;i++)
    {
        if(C[i]<cost)
        {
            cost=C[i];
            h=i;
        }
    }
    treapta+=h;
    S+=C[h];
}

void Zen2()
{
    int cost=10000000,h;
    for(int i=treapta;i<N;i++)
    {
        if(C[i]<cost)
        {
            h=i;
            cost=C[i];
        }
    }
    S+=C[h];
}
