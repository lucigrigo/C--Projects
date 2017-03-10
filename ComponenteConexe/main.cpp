#include <fstream>

using namespace std;

ifstream in("componenteconexe.in");
ofstream out("componenteconexe.out");

void Citire();
void CC(int );
void Afisare();

int n,nrc,A[100][100],V[100],Val[100]=1,k=1;

int main()
{
    Citire();
    for(int i=1;i<=n;i++)
    {
        int OK=1;
        for(int j=0;j<k;j++)
        {
            if(Val[j]==V[i])
            {
                OK=0;
            }
        }
        if(OK)
        {
            Val[k++]=i;
            CC(i);
            nrc++;
        }
    }
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
    for(int i=1;i<=n;i++)
    {
        V[i]=i;
    }
}

void CC(int x)
{
    int alfa=1 , zulu=1 , C[100];
    C[alfa]=x;
    V[x]=1;
    while(alfa<=zulu)
    {
        int romeo=C[alfa++];
        for(int i=1;i<=n;i++)
        {
            if(A[romeo][i]==1 && V[i]==0)
            {
                C[++zulu]=i;
                V[i]=1;
            }
        }
    }
}

void Afisare()
{
    out<<nrc;
    for(int i=1;i<=k;i++)
    {

    }
}
