#include <iostream>
#include <fstream>

using namespace std;

ifstream in("tarec.in");

void Con();
void Drum();
void Citire();
void Afisare();

int n,m,A[101][101],Viz[101],nrc;

int main()
{
    Citire();
    Drum();
    Con();
    Afisare();
    return 0;
}

void Citire()
{
    cin>>n>>m;
    for(int k=1;k<=m;k++)
    {
        int i,j;
        cin>>i>>j;
        A[i][j]=1;
    }
}

void Drum()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(!A[i][j])
                {
                    A[i][j]=A[i][k]*A[k][j];
                }
            }
        }
    }
}

void Con()
{
    for(int i=1;i<=n;i++)
    {
        if(!Viz[i])
        {
            Viz[i]=++nrc;
            for(int j=1;j<=n;j++)
            {
                if(A[i][j] && A[j][i])
                {
                    Viz[j]=nrc;
                }
            }
        }
    }
}

void Afisare()
{
    cout<<nrc;
}
