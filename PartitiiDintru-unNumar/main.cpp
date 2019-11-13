#include <fstream>

using namespace std;

ifstream x("valori.in");
ofstream y("valori.out");

int n,A[100];

void citire();
void scriere();
int test(int );
void PartitiaNumarului();

int main()
{
    citire();
    PartitiaNumarului();
    return 0;
}

void citire()
{
    x>>n;
}

void scriere()
{
    y<<n<<'=';
    for(int k=0;k<n;k++)
    {
        y<<A[k]<<'+';
    }
    y<<'\n';
}

int valoaremax=1;

int test(int u)
{
    int OK=0,S=0;
    for(int k=0;k<u;k++)
    {
        S=S+A[k];
        if(S==n)OK=1;
        if(A[k]==valoaremax)OK=1;
    }
    return OK;
}

void PartitiaNumarului()
{
    int i;
    i=0;
    A[i]=0;
    do
    {
        while(A[i]<valoaremax)
        {
            A[i]++;y<<valoaremax;
            if(test(i))
            {
                if(A[i]==valoaremax)
                {
                    i++;
                    A[i]=0;
                }
                else
                {
                    if(i==n)
                    {
                        scriere();
                        valoaremax++;
                    }
                }
            }
        }i--;
    }while(i>=0);
}
