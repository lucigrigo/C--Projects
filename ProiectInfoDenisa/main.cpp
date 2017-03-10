#include <iostream>

using namespace std;

typedef struct n{int nr;n *next;n *prev;}AB;
AB *A,*S1,*S2;
int N;

void Citire()
{
    cin>>N;
}

void TD()
{

    while(N!=0)
    {
        AB *a=new AB;
        a->nr=N%2;
        N=N/2;
        if(S2==NULL)
        {
            S1->next=a;
            a->prev=S1;
            S2=a;
        }
        else
        {
            S2->next=a;
            a->prev=S2;
            S2=a;
        }
    }
}

void Afisare()
{
    while(S2->prev!=S1)
    {
        cout<<S2->nr;
        S2=S2->prev;
    }
}

int main()
{
    Citire();
    S1->next=S2;
    S1->prev=0;
    S2->next=0;
    S1->prev=S1;
    TD();
    Afisare();
    return 0;
}
