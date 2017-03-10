#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream in("lantminim.in");
ofstream out("lantminim.out");

void Citire();
void LM(int );
void drum(int );
void Afisare();

int *A[100],n,p,q,Viz[100],K[100],k;

int main()
{
    Citire();
    LM(p);
    drum(q);
    Afisare();
    return 0;
}

void Citire()
{
    in>>n>>p>>q;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        A[i]=(int *)realloc(A[i],sizeof(int));
        A[i][0]=0;
    }
    while(in>>a>>b)
    {
        A[a][0]++;
        A[b][0]++;
        A[a]=(int *)realloc(A[a],sizeof(int)*(A[a][0]+1));
        A[a][A[a][0]]=b;
        A[b]=(int *)realloc(A[b],sizeof(int)*(A[b][0]+1));
        A[b][A[b][0]]=a;
    }
}

void drum(int q)
{
    if(Viz[q]!=-1)
    {
        drum(Viz[q]);
    }
    K[k++]=q;
}

void Afisare()
{
    out<<k<<'\n';
    for(int i=0;i<k;i++)
    {
        out<<K[i]<<' ';
    }
}

void LM(int p)
{
    int C[100],alfa=1,zulu=1;
    C[1]=p;
    Viz[p]=-1;
    while(alfa<=zulu && Viz[q]==0)
    {
        int romeo = C[alfa++];
        for(int i=1;i<=A[romeo][0];i++)
        {
            if(Viz[A[romeo][i]]==0)
            {
                C[++zulu]=A[romeo][i];
                Viz[A[romeo][i]]=romeo;
            }
        }
    }
}
