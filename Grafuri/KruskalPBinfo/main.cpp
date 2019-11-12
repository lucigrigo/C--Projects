#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream X("kruskal.in");
ofstream Y("kruskal.out");
struct muchie {int x,y,c;};
muchie v[5151];
int n,m,N[5151],k,cost;
void citire()
{
    X>>n>>m;
    for(int i=1;i<=m;i++)
        X>>v[i].x>>v[i].y>>v[i].c;
}
void sortare()
{
    muchie aux;
    for(int i=1;i<=m-1;i++)
        for(int j=i+1;j<=m;j++)
            if(v[i].c>v[j].c)
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
}
void kruskal()
{
    int L[101],nr=0,a,b,t;
    for(int i=1;i<=n;i++)
        L[i]=i;
    t=1;
    while(nr<n-1)
    {
        if(L[v[t].x]!=L[v[t].y])
        {
            nr++;
            cost=cost+v[t].c;
            a=L[v[t].x];
            b=L[v[t].y];
            N[++k]=t;
            for(int i=1;i<=n;i++)
                if(L[i]==a) L[i]=b;
        }
        t++;
    }
}
void afisare()
{
    Y<<cost<<endl;
    for(int i=1;i<=k;i++)
        Y<<v[N[i]].x<<' '<<v[N[i]].y<<endl;
}

void QS(int st , int dr)
{
    if(st<dr)
    {
        int i,j;
        muchie x;
        i=st;
        j=dr;
        x=v[st];
        while(i<j)
        {
            while(x.c<=v[j].c && i<j)j--;
            v[i]=v[j];
            while(x.c>=v[i].c && i<j)i++;
            v[j]=v[i];
        }
        v[i]=x;
        QS(st,i-1);
        QS(i+1,dr);
    }
}

int cmp(muchie a,muchie b)
{
    return a.c<b.c;
}

int main()
{
    citire();
    sortare();
    //QS(1,m);
    sort(v,v+m,cmp);
    kruskal();
    afisare();
    return 0;
}
