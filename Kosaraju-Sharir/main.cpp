#include <iostream>
#include <fstream>

using namespace std;

ifstream in("kosa.in");
ofstream out("kosa.out");

int n,m,A[101][101],Viz[101],L[101],o,nr;

void DF(int );
void DFT(int );
void Citire();

int main()
{
    Citire();
    for(int i=1;i<=n;i++)
    {
        if(Viz[i]==0)
        {
            DF(i);
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(Viz[L[i]]==1)
        {
            DFT(L[i]);
            nr++;
        }
    }
    out<<nr;
    return 0;
}

void Citire()
{
    in>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        in>>a>>b;
        A[a][b]=1;
    }
}

void DF(int e)
{
    Viz[e]=1;
    for(int i=1;i<=n;i++)
    {
        if(A[e][i]==1 && Viz[i]==0)
        {
            DF(i);
        }
    }
    L[o++]=e;
}

void DFT(int e)
{
    Viz[e]=0;
    for(int i=1;i<=n;i++)
    {
        if(A[i][e]==1 && Viz[i]==1)
        {
            DFT(i);
        }
    }
}
