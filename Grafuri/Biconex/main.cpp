#include <iostream>
#include <fstream>
#define NMAX 101
#define MMAX NMAX(NMAX-1)/2

using namespace std;

ifstream in("tarjan.in");
ofstream out("tarjan.out");

struct muchie{int k,l;}S[NMAX];

int low[NMAX],dfn[NMAX],A[NMAX][NMAX],ar[NMAX],nrf,start,cnt,n,m,vf,nr;

void Citire();
void DFS(int ,int );
void afisareBiconex(int ,int );

int main()
{
    Citire();
    for(int k=1;k<=n;k++)
    {
        dfn[k]=-1;
    }
    start=1;
    S[0].k=start; S[0].l = -1;
    DFS(start, -1);

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
        if(x!=tu && dfn[x]<dfn[u])
        {
            S[++vf].k=x;
            S[vf].l=u;
        }
        if(dfn[x]==-1)
        {
            if(u==start)
            {
                nrf++;
            }
            DFS(x,u);
            low[u]=min(low[u],low[x]);
            if(dfn[u]<=low[x])
            {
 afisareBiconex(x,u);
                if(u!=start)
                {
                    ar[u]=1;
                }

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

void afisareBiconex(int a,int b)
{

    nr++;
    cout<<"\nComponenta biconexa "<<nr<<" este:\n";

    while (S[vf].k!=a || S[vf].l!=b)
    {
        cout<<'('<<S[vf].k<<','<<S[vf].l<<')'<<"\t";
        vf--;
    }
    cout<<'('<<S[vf].k<<','<<S[vf].l<<')'<<"\t";
    vf--;
}
