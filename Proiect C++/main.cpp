#include <iostream>
#include <fstream>
#define NMAX 1001

using namespace std;

ifstream in("turn.in");
ofstream out("turn.out");

int n,h,a,b,c,d,N;
struct {int cub,culoare;}A[NMAX];

void Citire();
void Turn();
void Afisare();

int main()
{
    Citire();
    Turn();
    Afisare();
    return 0;
}

void Citire()
{
    in>>n;
    // Culorile fiecarui cub se va scrie cu ajutorul unei cifre de la 1-4 reprezentand culorile alb , verde , rosu , galben
    for(int i=1;i<=n;i++)
    {
        in>>A[i].cub>>A[i].culoare;
    }
}

void Turn()
{
    for(int i=1;i<=n;i++)
    {
        switch(A[i].culoare)
        {
            case 1:a++;break;
            case 2:b++;break;
            case 3:c++;break;
            case 4:d++;break;
        }
    }
}

void Afisare()
{
    out<<N;
}
