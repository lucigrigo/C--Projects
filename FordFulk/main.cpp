#include <fstream>
#include <iostream>
#include <stdlib.h>
#define NMAX 100

using namespace std;

int Flw[NMAX][NMAX], C[NMAX][NMAX], n, m, s, t, Viz[NMAX];

void citire()
{
    int x,y;
    ifstream f("ek.in");
    f>>n>>m>>s>>t;
    for (int i = 1; i<=m; i++)
    {
        f>>x>>y;
        f>>C[x][y];
    }

    f.close();
}

int Bfs()
{
    int Q[NMAX], p, u, v;

    p = u = 0;
    Q[p] = s;
    Viz[s] = 1;
    while(p <= u && Viz[t] == 0)
    {
        v = Q[p++];
        for (int i = 1; i<= n;i++)
            if (!Viz[i])
                if(Flw[v][i] < C[v][i]) //arc de inaintare nesaturat
                {
                    Viz[i] = v;
                    Q[++u] = i;
                }
                else
                    if(Flw[i][v] > 0 ) //arc de intoarcere
                    {
                        Viz[i] = -v;
                        Q[++u] = i;
                    }
    }

    return Viz[t];
}

void ek()
{
    int a, b, e, L[NMAX], dim;

    do
    {
        for(int i = 0; i<=n; i++)
            Viz[i] = 0;
        if(Bfs() == 0) return;

        L[0] = t;
        dim = 0;
        a = b = INT_MAX;
        while(L[dim] != s)
        {
            L[++dim] = abs(Viz[L[dim-1]]);
            if(Viz[L[dim-1]] > 0)
                a = min(C[L[dim]][L[dim-1]] - Flw[L[dim]][L[dim-1]], a);
            else
                if(Viz[L[dim-1]] < 0)
                    b = min(Flw[L[dim-1]][L[dim]], b);
        }

        e = min(a, b);
        for(int i = dim; i > 0; i--)
        {
            if(Viz[L[i-1]] > 0)
                Flw[L[i]][L[i-1]] += e;
            else
                Flw[L[i-1]][L[i]] -= e;
        }
    }while(1);
}

void afisare()
{
    ofstream g("ek.out");

    int i, j;
    for (i=1; i<=n; i++)
    {
        for (j = 1; j<=n; j++)
            g<<Flw[i][j]<<" ";
        g<<endl;
    }

    int s = 0;
    for (i=1;i<=n;i++)
        if (Flw[i][t] > 0)
        {
            g<<Flw[i][t]<<" ";
            s += Flw[i][t];
        }
    g<<endl<<s;
    g.close();
}

int main()
{
    citire();
    ek();
    afisare();
    return 0;
}
