#include <iostream>
#include <fstream>
#include <stdlib.h>

#define NMAX 134001
#define MMAX NMAX(NMAX-1)/2

using namespace std;

//ifstream in("tarjan.in");
//ofstream out("tarjan.out");

ifstream  in("componentebiconexe.in");
ofstream out("componentebiconexe.out");

struct muchie
        {
            int k,l;
        } S[NMAX];

int *A[NMAX], *compBiconex[NMAX], low[NMAX], dfn[NMAX], artPoint[NMAX], cnt, n, m, p, vf, nr, nrArtPoint, nrPunti, nrFii, start;

void DFS(int, int);
void Citire();
void Citire1();
void AfisareArt();
void AfisarePunti();
void Initializare();
void AfisareBiconex(int, int);
void AfisareBiconex1();
void ConstruireBiconex(int, int);

int main()
{
    //Citire();
    Citire1();
    Initializare();

    DFS(start, -1);

    if (nrFii > 1)
    {
        nrArtPoint++;
        artPoint[start] = 1;
    }

    if (p == 1)
        AfisareBiconex1();
    else if (p == 2)
            AfisareArt();
         else
            AfisarePunti();

    return 0;
}

void DFS(int u,int tu)
{
    int x;

    dfn[u] = low[u] = ++cnt;
    for(int i = 1; i <= A[u][0]; i++)       //parcurg lista de adiacenta a nodului u; pentru fiecare vecin al lui u
    {
        x = A[u][i];

        if(x != tu && dfn[x] < dfn[u])
        {
            S[++vf].k = x;
            S[vf].l = u;
        }
        if(dfn[x] == -1)
        {
            if (u == start)
            {
                nrFii++;
            }
            DFS(x,u);
            low[u] = min(low[u],low[x]);
            if(dfn[u] <= low[x])
            {
               // AfisareBiconex(x,u);
                ConstruireBiconex(x,u);
                if (u != start && artPoint[u] == 0)
                {
                    nrArtPoint++;
                    artPoint[u] = 1;
                }
            }
        }
        else
        {
            if(x != tu)
            {
                low[u] = min(low[u],dfn[x]);
            }
        }
    }
}

void Citire()
{
    int a,b;

    in>>n>>m;
    for(int k = 1; k <= n; k++)
    {
        A[k] = (int *) realloc(A[k], sizeof(int));
        A[k][0] = 0;
    }

    for(int k = 1; k <= m; k++)
    {
        in>>a>>b;

        A[a][0]++;
        A[a] = (int *) realloc(A[a], (A[a][0] + 1) * sizeof(int));
        A[a][A[a][0]] = b;

        A[b][0]++;
        A[b] = (int *) realloc(A[b], (A[b][0] + 1) * sizeof(int));
        A[b][A[b][0]] = a;
    }

    in.close();
}

void Citire1()
{
    in>>p;
    Citire();
}

void Initializare ()
{
    for(int k = 1; k <= n; k++)
    {
        dfn[k] = -1;
    }
    start = 1;
    S[0].k = start;
    S[0].l = -1;
}

void ConstruireBiconex(int a, int b)
{
    muchie m;
    int tempCompBiconex[NMAX];

    nr++;
    compBiconex[nr] = (int *) realloc(compBiconex[nr], sizeof(int));
    compBiconex[nr][0] = 0;

    do
    {
        m = S[vf--];
        if (tempCompBiconex[m.k] != nr)
        {
            compBiconex[nr][0]++;
            compBiconex[nr] = (int *) realloc(compBiconex[nr], (compBiconex[nr][0] + 1) * sizeof(int));
            compBiconex[nr][compBiconex[nr][0]] = m.k;
        }
        if (tempCompBiconex[m.l] != nr)
        {
            compBiconex[nr][0]++;
            compBiconex[nr] = (int *) realloc(compBiconex[nr], (compBiconex[nr][0] + 1) * sizeof(int));
            compBiconex[nr][compBiconex[nr][0]] = m.l;
        }
        tempCompBiconex[m.k] = tempCompBiconex[m.l] = nr;
     }while (m.k != a || m.l != b);

    if (compBiconex[nr][0] == 2)
    {
        nrPunti++;
    }
}

void AfisareArt()
{
    out<<nrArtPoint<<endl;
    for(int k = 1; k <= n; k++)
    {
        if(artPoint[k] == 1)
        {
            out<<k<<' ';
        }
    }
    out.close();
}

void AfisareBiconex1()
{
    out<<nr<<endl;

    for (int i = 1; i <= nr; i++)
    {
        for (int j = 0; j <= compBiconex[i][0]; j++)
        {
            out<<compBiconex[i][j]<<" ";
        }
        out<<endl;
    }

    out.close();
}

void AfisareBiconex(int a, int b)
{
    muchie m;

    nr++;
    cout<<"Componenta biconexa "<<nr<<" este:\n";
    do
    {
        m = S[vf--];
        cout<<'('<<m.k<<','<<m.l<<')'<<"\t";
    }while (m.k != a || m.l != b);
    cout<<endl;
}

void AfisarePunti()
{
    out<<nrPunti<<endl;

    for (int i = 1; i <= nr; i++)
    {
        if (compBiconex[i][0] == 2)
        {
            for (int j = 1; j <= compBiconex[i][0]; j++)
            {
                out<<compBiconex[i][j]<<" ";
            }
            out<<endl;
        }
    }

    out.close();
}
