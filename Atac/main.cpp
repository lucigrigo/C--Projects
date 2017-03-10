#include <fstream>
#include <iostream>
#define NMAX 10001

using namespace std;

ifstream in("atac.in");
ofstream out("atac.out");

int low[NMAX],dfn[NMAX],A[NMAX][NMAX],ar[NMAX],nrf,start,cnt,n,m,o;

void DFS(int ,int );
void Citire();

int main()
{
    Citire();
    for(int k=1;k<=n;k++)
    {
        dfn[k]=-1;
    }
    DFS(1,-1);
    if(nrf>1) ar[1]=1;
    int NR=0;
    for(int k=1;k<=n;k++)
        {
            if(ar[k]==1)
            {
                NR++;
            }
        }
    out<<NR*100/n;
    return 0;
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

void DFS(int e,int p)
{
    dfn[e]=low[e]=++cnt;
    for(int k=1;k<=A[e][0];k++)
    {
        int x=A[e][k];
        if(dfn[x]==-1)
        {
            if(e==start)
            {
                nrf++;
            }
            DFS(x,e);
            low[e]=min(low[e],low[x]);
            if(dfn[e]<=low[x] && e!=start)
            {
                ar[e]=1;
            }
        }
        else
        {
            if(x!=p)
            {
                low[e]=min(low[e],dfn[x]);
            }
        }
    }
}

