#include <iostream>
#include <fstream>
#define INF 10001

using namespace std;

ifstream in("dijkstra.in");
ofstream out("dijkstra.out");

unsigned long int n,p,C[101][101],D[101],Viz[101],T[101];

void Citire();
void Dijkstra();

int main()
{
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=100;j++)
        {
            C[i][j]=INF;
        }
    }
    Citire();
    for(int i=1;i<=n;i++)
    {
        D[i]=C[p][i];
        T[i]=p;
    }
    Viz[p]=1;
    T[p]=0;
    Dijkstra();
    for(int i=1;i<=n;i++)
    {
        if(D[i]==INF)
        {
            out<<-1<<' ';
        }
        else
        {
            out<<D[i]<<' ';
        }
    }
    return 0;
}

void Citire()
{
    in>>n>>p;
    int a,b,c;
    while(in>>a>>b>>c)
    {
        C[a][b]=c;
    }
    for(int i=1;i<=n;i++)
    {
        C[i][i]=0;
    }
}

void Dijkstra()
{
    int OK=1,k,min;
    while(OK)
    {
        min=INF;
        k=-1;
        for(int i=1;i<=n;i++)
        {
            if(Viz[i]==0 && min>D[i])
            {
                min=D[i];
                k=i;
            }
        }
        if(min==INF)
        {
            OK=0;
        }
        else
        {
            Viz[k]=1;
            for(int i=1;i<=n;i++)
            {
                if(Viz[i]==0 && D[i]>D[k]+C[k][i])
                {
                    D[i]=D[k]+C[k][i];
                    T[i]=k;
                }
            }
        }
    }
}
