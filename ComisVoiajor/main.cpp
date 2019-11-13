#include <fstream>

using namespace std;

ifstream in("valori.in");
ofstream out("valori.out");

int n,m,p,Vecini[10][10],Drum[20];

void citire();
void scriere(int );
void RuteAleComisuluiVoiajor();
int test(int );

int main()
{
    citire();
    RuteAleComisuluiVoiajor();
    return 0;
}

void citire()
{
    in>>n>>m>>p;
}

void scriere(int u)
{
    if(u==n-1 && Drum[0]==p && Drum[u]==p)
    {
        for(int k=0;k<n;k++)
        {
            out<<Drum[k]<<' ';
        }
        out<<'\n';
    }
}

int test(int u)
{
    int k=u--,OK=1;
    if(!Vecini[k][u])
    {
        OK=0;
    }
    return OK;
}

void RuteAleComisuluiVoiajor()
{
    int i=1;
    Drum[0]=p;
    Drum[i]=0;
    do
    {
            while(Drum[i]<n)
            {
                Drum[i]++;
                if(test(i))
                {
                    if(i<n-1)
                    {
                        i++;
                        Drum[i]=0;
                    }
                    else scriere(i);
                }
            }i--;
    }while(i>=0);
}
