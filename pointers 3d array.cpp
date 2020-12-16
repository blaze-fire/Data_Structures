#include<iostream>

//using std::cout;

int main()
{
    int m,n,d,counters=1;
    std::cin>>m>>n>>d;
    int *x=new int[m*n*d];

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<d;k++)
            {
                x[i*n+j*d+k]=counters;
                counters++;
            }

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
           {
               for(int k=0;k<d;k++)
                {
                    std::cout<<x[i*n+j*d+k]<<" , ";
                }
                std::cout<<std::endl<<"\t";
           }


}
