#include <fstream>

using namespace std;

//ifstream in("subgraf1.in");
//ofstream out("subgraf1.out");
ifstream in("graf_partial_1.in");
ofstream out("graf_partial_1.out");

void CitireSubgraf1();
void CitireGrafPartial1();
void Subgraf1();
void GrafPartial1();

int n,A[100][100];

int main()
{
    //CitireSubgraf1();
    //Subgraf1();
    CitireGrafPartial1();
    GrafPartial1();
    return 0;
}

void CitireSubgraf1()
{
    in>>n;
    int i,j;
    while(in>>i>>j)
    {
        A[i][j]=A[j][i]=1;
    }
}

void Subgraf1()
{
    int min=1000,S,V[100],i=1;

    for(int k=1;k<=n;k++)
    {
        S=0;
        for(int j=1;j<=n;j++)
        {
            if(A[k][j]==1)
            {
                S++;
            }
        }
        if(S<=min)
        {
            min=S;
            V[i++]=k;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=i;j++)
        {
            if(k==V[j])
            {
                for(int l=1;l<=n;l++)
                {
                    A[k][l]=A[l][k]=0;
                }
            }
        }
    }

    S=0;
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            S+=A[k][j];
        }
    }
    out<<S/2;;
}

void CitireGrafPartial1()
{
    in>>n;
    int i,j;
    while(in>>i>>j)
    {
        A[i][j]=A[j][i]=1;
    }
}

void GrafPartial1()
{
    int min=10000,max=0,Vm[101],VM[101],a=1,b=1,S;

    for(int k=1;k<=n;k++)
    {
        S=0;
        for(int j=1;j<=n;j++)
        {
            S+=A[k][j];
        }
        if(S<=min)
        {
            min=S;
            Vm[a++]=k;
        }
        if(S>=max)
        {
            max=S;
            VM[b++]=k;
        }
    }

    S=0;
    for(int k=1;k<=n;k++)
    {
        for(int l=1;l<=a;l++)
        {
            if(k==Vm[l])
            {
                for(int j=1;j<=n;j++)
                {
                    if(A[k][j]==1)
                    {
                        for(int o=1;o<=b;o++)
                        {
                            if(j==VM[o])
                            {
                                A[j][k]=A[k][j]=0;
                                S++;
                            }
                        }
                    }
                }
            }
        }
    }

    out<<S<<'\n';
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            out<<A[k][j]<<' ';
        }
        out<<'\n';
    }
}
