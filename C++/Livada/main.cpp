#include <iostream>
#include <fstream>

using namespace std;

int A[100][100],B[100][100],n,m;
ofstream out("livada.out");

void Citire()
{
    ifstream in("livada.in");
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            in>>A[i][j];
        }
    }
    in.close();
}

void LaCules()
{
    B[1][1]=A[1][1];
    for(int i=2;i<=m;i++)
    {
        B[1][i]=A[1][i]+B[1][i];
    }
    for(int j=2;j<=n;j++)
    {
        B[j][1]=A[j][1]+B[j-1][1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            B[i][j]=A[i][j]+max(B[i-1][j],B[i][j-1]);
        }
    }
}

/*void Afisare2(int n,int m)
{
    if(B[n-1][m]==B[n][m]-A[n][m])
    {
        Afisare2(n-1,m);
        out<<'J';
    }
    if(B[n][m-1]==B[n][m]-A[n][m])
    {
        Afisare2(n,m-1);
        out<<'D';
    }
}*/

void Afisare()
{
    out<<B[n][m];
    Afisare2(n,m);
    out.close();
}

int main()
{
    Citire();
    LaCules();
    Afisare();
    return 0;
}
