#include <fstream>
#include <fstream>

using namespace std;

ifstream in("gears.in");
ofstream out("gears.out");

void Citire();
void G(int );
void Afisare();

int n,x,A[101][101],Viz[101];

int main()
{
    Citire();
    G(x);
    Afisare();
    return 0;
}

void Citire()
{
    in>>n>>x;
    for(int k=1;k<n;k++)
    {
        int a,b;
        in>>a>>b;
        A[a][b]=A[b][a]=1;
    }
}

void G(int e)
{
    int a=1,z=1,C[101];
    C[a]=e;
    Viz[e]=1;
    // 1 = dreapta / -1 = stanga
    while(a<=z)
    {
        int t=C[a++];
        for(int k=1;k<=n;k++)
        {
            if(A[t][k]==1 && Viz[k]==0)
            {
                Viz[k]=(-1)*Viz[t];
                C[++z]=k;
            }
        }
    }
}

void Afisare()
{
    for(int i=1;i<=n;i++)
    {
        if(Viz[i]==1) out<<'D';
        if(Viz[i]==-1) out<<'S';
    }
}
