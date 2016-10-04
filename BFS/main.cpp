#include <fstream>

using namespace std;

ifstream in("graf.in");
ofstream out("graf.out");

int viz[100],M[100][100],n,m,C[100];

void Citire();
void BF(int );
void DF(int );

int main()
{
    Citire();
   //BF(1);
   //DF(1);
   int con=0;
   for(int i=1;i<=n;i++)
   {
       if(viz[i]==0)
       {
           con+=1;
           DF(i);
           out<<'\n';
       }
   }
   if(con==1)
   {
       out<<"Graful este conex!";
   }
   else
   {
       out<<"Graful nu este conex!";
   }
    return 0;
}

void Citire()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        int i,j;
        in>>i>>j;
        M[i][j]=M[j][i]=1;
    }
}

void BF(int x)
{
    int p=1,u=1;
    C[p]=x;
    viz[p]=1;
    out<<C[p];
    while(p<=u)
    {
        int y=C[p++];
        for(int i=1;i<=n;i++)
        {
            if(M[y][i]==1 && viz[i]==0)
            {
                C[++u]=i;
                viz[i]=1;
                out<<i;
            }
        }
    }
}

void DF(int x)
{
    out<<x;
    viz[x]=1;
    for(int k=1;k<=n;k++)
    {
        if(M[x][k]==1 && viz[k]==0)
        {
            DF(k);
        }
    }
}
