#include <fstream>
#include <iostream>

using namespace std;

ifstream in("epidemie.in");
ofstream out("epidemie.out");

void Citire();
void E(int );
void Afisare();

int A[1001][1001],n,Viz[1001],m,k,I[1001];

int main()
{
    Citire();
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==I[i])
            {
                E(j);
            }
        }
    }
    Afisare();
    return 0;
}

void Citire()
{
    in>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        in>>a>>b;
        A[a][b]=A[b][a]=1;
    }
    in>>k;
    for(int i=1;i<=k;i++)
    {
        in>>I[i];
    }
}

void E(int e)
{
    int a=1,z=1,C[1001];
    C[a]=e;
    Viz[e]=1;
    while(a<=z)
    {
        int t=C[a++];
        for(int i=1;i<=n;i++)
        {
            if(A[t][i]==1  &&  (Viz[i]==0  || Viz[i]>Viz[t]+1))
            {
                C[++z]=i;
                Viz[i]=Viz[t]+1;
            }
        }
    }
}

void Afisare()
{
    int nmax=0;
    for(int i=1;i<=n;i++)
    {
        if(nmax<Viz[i])
        {
            nmax=Viz[i];
        }
    }
    out<<nmax;
}
