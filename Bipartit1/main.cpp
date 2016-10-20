#include <fstream>
#include <iostream>

using namespace std;

ifstream in("bipartit1.in");
ofstream out("bipartit1.out");

void Back(int );
int Conditie(int );
int Solutie(int );
int  Muchii();
void Back2();

int n,m,ST[120],Ochei,A[101][101];
struct {int x;
        int y;}V[10102];

int main()
{
    in>>n>>m;
    for(int k=1;k<=m;k++)
    {
        in>>V[k].x>>V[k].y;
    }
    ST[1]=1;
    //Back(2);
    Back2();
    if(Ochei==0)
    {
        out<<"NU";
    }
    in.close();
    out.close();
    return 0;
}

int Conditie(int k)
{
    if(k<n)
    {
        return 1;
    }
    else
    {
        for(int i=1;i<k;i++)
        {
            if(ST[i]!=ST[i+1])
            {
                return 1;
            }
        }
        return 0;
    }
}

int Solutie(int k)
{
    if(k==n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Muchii()
{
    for(int i=1;i<=m;i++)
    {
        if(ST[V[i].x]==ST[V[i].y] && A[V[i].x][V[i].y]==0)
        {
             A[V[i].x][V[i].y]=A[V[i].y][V[i].x]=1;
            return 0;
        }
        A[V[i].x][V[i].y]=A[V[i].y][V[i].x]=1;
    }
    return 1;
}

void Back(int k)
{
    for(int i=1;i<=2;i++)
    {
        ST[k]=i;
        if(Conditie(k))
        {
            if(Solutie(k))
            {
                for(int o=1;o<n;o++)
                {
                    for(int p=o+1;p<=n;p++)
                    {
                        A[o][p]=0;
                    }
                }
                if(Muchii())
                {
                    Ochei=1;
                    out<<"DA"<<'\n';
                    for(int l=1;l<=2;l++)
                    {
                        for(int j=1;j<=n;j++)
                        {
                            if(ST[j]==l)
                            {
                                out<<j<<' ';
                            }
                        }
                        out<<'\n';
                    }
                   // return false;
                }
            }
            else
            {
                Back(k+1);
            }
        }
    }
}

void Back2()
{
    int k=2;
    ST[k]=0;
    while(k>1 && Ochei==0)
    {
        if(ST[k]<2)
        {
            ST[k]++;
            if(Conditie(k))
            {
                if(Solutie(k))
                {
                   if(Muchii())
                    {
                        Ochei=1;
                        out<<"DA"<<'\n';
                        for(int l=1;l<=2;l++)
                        {
                            for(int j=1;j<=n;j++)
                            {
                                if(ST[j]==l)
                                {
                                    out<<j<<' ';
                                }
                            }
                            out<<'\n';
                        }
                    }
                }
                else ST[++k]=0;
            }
        }
        else
        {
            k--;
        }
    }
}
