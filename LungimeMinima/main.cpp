#include <fstream>

using namespace std;

ifstream in("lungimeminima.in");
ofstream out("lungimeminima.out");

void Citire();
void LM(int );
void Afisare(int );

int A[101][101],n,p,L,Viz[101];

int main()
{
    Citire();
    LM(p);
    Afisare(L);
    return 0;
}

void Citire()
{
    in>>n>>p>>L;
    int a,b;
    while(in>>a>>b)
    {
        A[a][b]=A[b][a]=1;
    }
}

void LM(int e)
{
    int a=1,z=1,C[101];
    C[a]=e;
    Viz[e]=1;
    while(a<=z)
    {
        int t=C[a++];
        for(int k=1;k<=n;k++)
        {
            if(A[t][k]==1 && Viz[k]==0)
            {
                Viz[k]=Viz[t]+1;
                C[++z]=k;
            }
        }
    }
}

void Afisare(int l)
{
    int nr=0;
    for(int k=1;k<=n;k++)
    {
        if(Viz[k]==l+1)
        {
            nr++;
        }
    }
    out<<nr<<'\n';
    for(int k=1;k<=n;k++)
    {
        if(Viz[k]==l+1)
        {
            out<<k<<' ';
        }
    }
}
