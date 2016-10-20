#include <fstream>

using namespace std;
//ifstream in("graf_complet.in");
//ofstream out("graf_complet.out");
ifstream in("lanturi.in");
ofstream out("lanturi.out");

void CitireGrafComplet();
void CitireLanturi();
void GrafComplet();
void Lanturi();

int n,m,p,q,r,nr,A[100][100];

int main()
{
    //CitireGrafComplet();
    CitireLanturi();
    return 0;
}

void CitireGrafComplet()
{
    in>>nr;
    for(int i=1;i<=nr;i++)
    {
        in>>n;
        for(int k=1;k<=n;k++)
        {
            for(int j=1;j<=n;j++)
            {
                in>>A[k][j];
            }
        }
        GrafComplet();
    }
}

void GrafComplet()
{
    int N=n*(n-1),S=0;
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            S+=A[k][j];
        }
    }
    if(S==N)
    {
        out<<"DA"<<'\n';
    }
    if(S!=N)
    {
        out<<"NU"<<'\n';
    }
}

void CitireLanturi()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        int i,j;
        in>>i>>j;
        A[i][j]=A[j][i]=1;
    }
    in>>p>>q>>r;
    Lanturi();
}

void Lanturi()
{

}
