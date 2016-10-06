#include <fstream>

using namespace std;

ifstream in("graf.in");
ofstream out("graf.out");

int viz[100],M[100][100],n,m,C[100];
struct  {
        int a;
        int b;
        int c;}E[100];
struct  {
        int a1;
        int b1;
        int c1;}R[100];

void Citire();
void BF(int );
void DF(int );
void CitireExpo();
void ScriereExpo();
void ExpozitiaDeRoboti();

int main()
{
    //Citire();
   //BF(1);
   //DF(1);
   /*int con=0;
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
   }*/
    ExpozitiaDeRoboti();
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

void CitireExpo()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        in>>E[k].a>>E[k].b>>E[k].c;
    }
}

void ScriereExpo()
{
    int S=0;
    for(int k=1;k<=n;k++)
    {
        S+=R[k].c1;
    }
    out<<S<<'\n';
    for(int k=1;k<=n;k++)
    {
        out<<R[k].a1<<' '<<R[k].b1<<'\n';
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

void ExpozitiaDeRoboti()
{
    CitireExpo();
    int costmax=0;
    for(int k=1;k<=m;k++)
    {
        if(E[k].c>costmax)
            costmax = E[k].c;
    }
    int L[100];
    for(int k=0;k<=n;k++)
    {
        L[k]=k;
    }
    int prim=0,cost=1;
    for(int k=0;k<=n;k++)
    {
        if(L[k]==k) prim+=1;
    }
    int i=1;
    while(prim>1 && cost<=costmax)
    {
        for(int k=1;k<=m;k++)
        {
            if(E[k].c==cost && L[E[k].a]!=L[E[k].b])
            {
               R[i].a1=E[k].a;
               R[i].b1=E[k].b;
               R[i++].c1=E[k].c;
               int d = min(L[E[k].a],L[E[k].b]);
               L[E[k].a]=L[E[k].b]=d;
            }
        }
        cost+=1;
        prim=0;
        for(int k=0;k<=n;k++)
        {
            if(L[k]==k) prim+=1;
        }
    }
    ScriereExpo();
}
