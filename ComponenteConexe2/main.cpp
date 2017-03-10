#include <fstream>
#include <iostream>

using namespace std;

ifstream in("componenteconexe2.in");
ofstream out("componenteconexe2.out");

void Citire();
void CE2con(int );
void Afisare();

int n,A[101][101],m,Viz[101],con,NR;

int main()
{
    Citire();
    for(int i=1;i<=n;i++)
    {
        if(Viz[i]==0)
        {
            con++;
            CE2con(i);
        }
    }
    Afisare();
    return 0;
}

void Citire()
{
    in>>n;
    int a,b;
    while(in>>a>>b)
    {
        if(A[a][b]==0)
        {
            m++;
        }
        A[a][b]=A[b][a]=1;
    }
}

void CE2con(int e)
{
    int a=1,z=1,C[101];
    C[a]=e;
    Viz[e]=con;
    while(a<=z)
    {
        int t=C[a++];
        for(int i=1;i<=n;i++)
        {
            if(A[t][i]==1 && Viz[i]==0)
            {
                C[++z]=i;
                Viz[i]=con;
            }
        }
    }
    NR=NR+z-1;
}

void Afisare()
{
    out<<m-NR;
}
