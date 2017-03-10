#include <fstream>

using namespace std;

ifstream in("componenteconexe1.in");
ofstream out("componenteconexe1.out");

int A[101][101],Viz[101],n,con;

void Citire();
void CE1();
void CE1con();
void Con(int );
void Afisare();

int main()
{
    Citire();
    CE1();
    Afisare();
    return 0;
}

void Citire()
{
    in>>n;
    int a,b;
    while(in>>a>>b)
    {
        A[a][b]=A[b][a]=1;
    }
}

void CE1()
{
    CE1con();
    out<<con-1<<'\n';
    while(con>1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(Viz[i]!=Viz[j])
                {
                    A[i][j]=A[j][i]=2;
                    CE1con();
                }
            }
        }
    }
}

void CE1con()
{
    for(int i=1;i<=n;i++)
    {
        Viz[i]=0;
    }
    con=0;
    for(int i=1;i<=n;i++)
    {
        if(Viz[i]==0)
        {
            con++;
            Con(i);
        }
    }
}

void Con(int e)
{
    int a=1,z=1,C[101];
    C[a]=e;
    Viz[e]=con;
    while(a<=z)
    {
        int t=C[a++];
        for(int i=1;i<=n;i++)
        {
            if(Viz[i]==0 &&(A[t][i]==1 || A[t][i]==2))
            {
                Viz[i]=con;
                C[++z]=i;
            }
        }
    }
}

void Afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i][j]==2)
            {
                A[j][i] = 1;
                out<<i<<' '<<j<<'\n';
            }
        }
    }
}
