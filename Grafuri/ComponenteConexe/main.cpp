#include <fstream>
#include <iostream>

using namespace std;

ifstream in("componenteconexe.in");
ofstream out("componenteconexe.out");

void Citire();
void Conex(int );
void Afisare();

int n,A[101][101],Viz[101],nrc;

int main()
{
    Citire();
    for(int k=1;k<=n;k++)
    {
        if(Viz[k]==0)
        {
            nrc++;
            Conex(k);
        }
    }
    Afisare();
    return 0;
}

void Citire()
{
    in>>n;
    int i,j;
    while(in>>i>>j)
    {
        A[i][j]=A[j][i]=1;
    }
}

void Conex(int i)
{
    int a=1,z=1,L[101];
    Viz[i]=nrc;
    L[a]=i;
    while(a<=z)
    {
        int t=L[a++];
        for(int k=1;k<=n;k++)
        {
            if(A[t][k]==1 && Viz[k]==0)
            {
                L[++z]=k;
                Viz[k]=nrc;
            }
        }
    }
}

void Afisare()
{
    for(int i=1;i<=n;i++)
    {
        cout<<Viz[i]<<' ';
    }
    out<<nrc<<'\n';
    for(int k=1;k<=nrc;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(Viz[i]==k)
            {
                out<<i<<' ';
            }
        }
        out<<'\n';
    }
}
