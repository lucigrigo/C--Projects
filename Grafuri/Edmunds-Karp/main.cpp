#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <climits>
#define NMAX 100

using namespace std;

ifstream in("ek.in");
ofstream out("ek.out");

int Flw[NMAX][NMAX],C[NMAX][NMAX],n,m,s,T,Viz[NMAX];

void Citire();
int BFS();
void EK();

int main()
{
    Citire();
    EK();
    return 0;
}

void Citire()
{
    in>>n>>m>>s>>T;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        in>>a>>b;
        in>>C[a][b];
    }
    in.close();
}

int BFS()
{
    int Q[NMAX],a,z,t;
    a=z=0;
    Q[a]=s;
    Viz[s]=1;
    while(a<=z && Viz[T]==0)
    {
        t=Q[a++];
        for(int i=1;i<=n;i++)
        {
            if(!Viz[i])
            {
                if(Flw[t][i]<C[t][i]) //arc de inaintare nesaturat
                {
                    Viz[i]=t;
                    Q[++z]=i;
                }
                else
                {
                    if(Flw[t][i] > 0) //arc de intoarcere
                    {
                        Viz[i]=-t;
                        Q[++z]=i;
                    }
                }
            }
        }
    }
    return Viz[T];
}

void EK()
{
    int a,b,t,L[NMAX],dim=0;
    do
    {
        for(int i=1;i<=n;i++) Viz[i]=0;
        if(BFS()==0)return;

        L[0] = T;
        a=b=INT_MAX;
        while(L[dim]!=s)
        {
            L[++dim] = abs(Viz[L[dim-1]]);
            if(Viz[dim-1]>0)
            {
                a=min(C[L[dim]][L[dim-1]]-Flw[L[dim]][L[dim-1]],a);
            }
                else
                {
                    b=min(Flw[L[dim-1]][L[dim]],b);
                }
        }

        t=min(a,b);
        for(int i=dim;i>0;i--)
        {
            if(Viz[L[i-1]] > 0)
            {
                F[L[i]][L[i-1]]=t;
            }
            else
            {
                F[L[i]][L[i-1]]=-t;
            }

        }
    }while(1);
}
