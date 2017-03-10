#include <fstream>
#include <iostream>

using namespace std;

ifstream in("retea.in");
ofstream out("retea.out");

void Citire();
void R(int );
void DFS(int );

int A[101][101],n,m,Viz[101],B[101][101];

int main()
{
    Citire();
    for(int i=1;i<=n;i++)
    {
        R(i);
    }
    return 0;
}

void Citire()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        int a,b;
        in>>a>>b;
        A[a][b]=A[b][a]=1;
    }
}

void DFS(int e)
{
    Viz[e]=1;
    for(int k=1;k<=n;k++)
    {
        if(B[e][k]==1 && Viz[k]==0)
        {
            DFS(k);
        }
    }
}

void R(int e)
{
    for(int i=1;i<=n;i++)
    {
        Viz[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            B[i][j]=A[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==e && B[i][j]==1)
            {
                B[i][j]=0;
            }
            if(i==e && B[i][j]==1)
            {
                B[i][j]=0;
            }
        }
    }
    Viz[e]=1;
    if(1==e)
    {
        DFS(2);
    }
    else DFS(1);
    int OK=0;
    for(int k=1;k<=n;k++)
    {
        if(Viz[k]==0)
        {
            OK=1;
        }
    }
    out<<OK<<' ';
}
