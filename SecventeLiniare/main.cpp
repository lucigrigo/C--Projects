#include <fstream>

using namespace std;

ifstream x("valori.in");
ofstream y("valori.out");

int A[1000],n;

void SecventeLiniare();

int main()
{
    while(x>>A[n++]);
    n--;
    SecventeLiniare();
    return 0;
}

void SecventeLiniare()
{
    int l,lmax=0,R[100],dif,q;
    for(int i=0; i<n; i++)
    {
        if((A[i+1]-A[i]) == 1)
        {
            l=2;
            dif=1;
            int k=i;
            while((A[k+1]-A[k++]) == dif++)
            {
                l++;
            }
            l--;
            if(l>lmax)
            {
                lmax=l;
                int j;
                for(k=i,j=0; j<lmax; j++,k++)
                {
                    R[j]=A[k];
                }
            }
        }
    }

    for(int k=0; k<lmax; k++)
    {
        y<<R[k]<<' ';
    }
}
