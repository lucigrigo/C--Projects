#include <fstream>
#include <iostream>
#include <string.h>
#define NMAX 1001

using namespace std;

int L[NMAX],Urm[NMAX],n;
char S[256];

void Citire()
{
    ifstream in("cuvant.in");
    char x;
    int i=0;
    while(in>>x)
    {
        S[i++]=x;
    }
    in.close();
}

void ValoareMaxima()
{
    n=strlen(S);
    L[n-1]=1;
    Urm[n-1]=0;
    int i;
    for(i=n-2;i>=0;i--)
    {
        int maxim=0,pozmax=0;
        for(int j=i+1;j<=n;j++)
        {
            if(S[i]<S[j] && maxim<L[j])
            {
                maxim = L[j];
                pozmax = j;
            }
        }
        if(maxim!=0)
        {
            L[i]=maxim + 1;
            Urm[i]=pozmax;
        }
    }
}

void Afisare(int maxim,int pozmax)
{
    ofstream out("cuvant.out");
    out<<maxim<<'\n'<<S[pozmax];
    int i=Urm[pozmax];
    while(i!=0)
    {
        out<<S[i];
        i=Urm[i];
    }
}

void Cautare()
{
    int maxim=0,pozmax=0;
    for(int i=0;i<n;i++)
    {
        if(maxim<L[i])
        {
            maxim=L[i];
            pozmax=i;
        }
    }
    Afisare(maxim,pozmax);
}

int main()
{
    Citire();
    ValoareMaxima();
    Cautare();
    return 0;
}
