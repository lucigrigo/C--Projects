#include <iostream>
#include <fstream>

using namespace std;

int n,k;
unsigned short int L[100000];

void Zen()
{
    ifstream in("zen.in");
    in>>n>>k;
    int i=1,c,minim;

    while(in>>c)
    {
        if(i<=k)
        {
            L[i++]=c;
        }
        else
        {
            minim=L[i-1];
            for(int j=i-2;j>=i-k;j--)
            {
                if(minim>L[j])
                {
                    minim=L[j];
                }
            }
            L[i++]=minim+c;
        }
    }
    ofstream out("zen.out");
    out<<L[n];
    in.close();
    out.close();
}

int main()
{
    Zen();
    return 0;
}
