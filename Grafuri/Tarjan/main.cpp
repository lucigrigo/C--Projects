#include <iostream>
#include <fstream>
#define NMAX 101
#define MMAX NMAX(NMAX-1)/2

using namespace std;

ifstream in("tarjan.in");
ofstream out("tarjan.out");

int low[NMAX],dfn[NMAX],A[NMAX][NMAX],ar[NMAX],nrf,start,cnt,n,m;

void Citire();
void DFS(int ,int );

int main()
{
    Citire();
    for(int k=1;k<=n;k++)
    {
        dfn[k]=-1;
    }
    start=1;
    DFS(start,-1);
    if(nrf>1)
        ar[start]=1;
    for(int k=1;k<=n;k++)
    {
        if(ar[k]==1)
        {
            out<<k<<' ';
        }
    }
    return 0;
}

void DFS(int u,int tu)
{
    dfn[u]=low[u]=++cnt;
    for(int i=1;i<=A[u][0];i++)
    {
        int x=A[u][i];
        if(dfn[x]==-1)
        {
            if(u==start)
            {
                nrf++;
            }
                DFS(x,u);
                low[u]=min(low[u],low[x]);
                if(dfn[u]<=low[x] && u!=start)
                {
                    ar[u]=1;
                }
        }
            else
            {
                if(x!=tu)
                {
                    low[u]=min(low[u],dfn[x]);
                }
        }
    }
}

void Citire()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        int a,b;
        in>>a>>b;
        A[a][0]++;
        A[a][A[a][0]]=b;
        A[b][0]++;
        A[b][A[b][0]]=a;
    }
}
