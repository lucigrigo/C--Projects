#include <iostream>

using namespace std;

int n,g[1001],G,nrmax,nr,S;

void Citire();
void Sabin();
void Afisare();

int main()
{
    Citire();
    Sabin();
    Afisare();
    return 0;
}

void Citire()
{
    cin>>n>>G;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
    }
}

void Sabin()
{
    for(int i=1;i<=n;i++)
    {
        if(g[i]>nrmax)
        {
            nrmax=g[i];
        }
    }
    while(S<G)
    {
        if(nrmax==G)
        {
            cout<<1;
        }
        else
        {
            G-=nrmax;

        }
    }
}

void Afisare()
{
    cout<<nr;
}
