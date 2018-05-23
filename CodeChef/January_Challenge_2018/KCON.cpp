#include <bits/stdc++.h>


using namespace std;
long int  f1(long long int a[], long int size)
{
    long int max_so_far = INT_MIN, max_ending_here = 0;

    for (long int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main() {

    long long  int f=0,k,x1,index1,index2;
    long long  int n,l,g,ne;
    long int u,v;
    string s;

    cin>>x1;

    long int max=0;


    long long  int a[100001];
    long long int a1[6];


    for(long int y2=0; y2<x1; y2++)
    {
        v=0;
        cin>>n>>k;
        long int o=0;
        for(int i=0; i<n; i++)
        {

            cin>>a[i];
            v+=a[i];
            if(a[i]<0)
            {
                o++;
            }
        }
        if(o==n)
        {
            long int z=-1000001;
            for(int i=0; i<n; i++)
            {



                if(z<a[i])
                {
                    z=a[i];
                }
            }
            cout<<z<<endl;
        }
        else
        {
            if(k==1)
            {
                cout<<f1(a,n)<<endl;
            }
            else if(k>1)
            {
                long int b1=f1(a,n);
                long int y=v*k;
                long int c;
                long int p=-1000001,m=0,m1=0,p1=-1000001;
                for(int i=0; i<n; i++)
                {
                    m+=a[i];

                    if(m>p)
                    {
                        p=m;
                    }
                }
                for(int i=n-1; i>=0; i--)
                {
                    m1+=a[i];

                    if(m1>p1)
                    {
                        p1=m1;
                    }
                }
                long int h=y-v+p;
                long int x=y-2*v+p+p1;
                long int q=y-v+p1;
                c=p+p1;
                a1[0]=b1;
                a1[1]=y;
                a1[2]=c;
                a1[3]=h;
                a1[4]=x;
                a1[5]=q;
                sort(a1,a1+6);
                cout<<a1[5]<<endl;
            }

        }
    }





    return 0;
}