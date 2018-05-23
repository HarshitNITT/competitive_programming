#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int q=0,n,m,max=1;
    long long  int  a[200002],x[200002],c[200002],d[200002],e[200002],f[200002],b[200002];
    for(int i=0; i<200002; i++)
    {
        e[i]=0;
        x[i]=0;
        c[i]=0;
        d[i]=0;
    }

    cin>>q;
    for(long long  int k=0; k<q; k++)
    {
        cin>>n;
        long long   int g=0;


        long long   int f1=0;
        for(long long int y=1; y<=n; y++)
        {
            cin>>a[y];
            if(f1<a[y])
                f1=a[y];
        }
        for(long long int y=1; y<=n; y++)
        {
            d[y]=0;
            e[y]=0;
            x[y]=0;

        }
        for(long long int y=1; y<=f1+1; y++)
        {
            e[y]=0;
            c[y]=0;

        }

        for(long long int y=1; y<=n; y++)
        {
            c[a[y]]=y-c[a[y] ];
            ++e[a[y]];
            if(e[a[y]]==2)
            {
                g=1;
                d[c[a[y]]]++;
                d[n-c[a[y]]]++;

            }
        }
        if(g==1)
        {
            long int i=0;
            int y1=0,min=100005;
            for( i=1; i<n; i++)
            {

                if(min>d[i]  )
                {
                    min=d[i];
                    y1=i;
                }

            }

            // cout<<y1;

            for(int u=1; u<=y1; u++)
            {
                x[u]=a[u];
            }
            for(int u=y1+1; u<=n; u++)
            {
                f[u-y1]=a[u];
            }
            for(int u=n-y1+1; u<=n; u++)
            {
                f[u]=x[u-n+y1];
                // cout<<x[u-n+i]<<u-n-i<<endl;
            }
            int v1=0;
            for(int i=1; i<=n; i++)
            {
                if(a[i]==f[i])
                    v1++;
            }
            cout<<n-v1<<endl;
            for(int i=1; i<=n; i++)
                cout<<f[i]<<" ";
            cout<<endl;
        }
        else
        {
            long long int t=a[0],o=0,o1=0,o2=0;
            for(long long int y=1; y<n; y++)
            {

                b[y]=a[y+1];
            }
            //   int g=0;
            b[n]=a[1];

            // int o=0,o1=0,o2=0;
            for(long long int y=1; y<=n; y++)
            {   if(a[y]==b[y])
                    o++;

            }

            for(long long int y=1; y<n; y++)
            {

                c[y]=b[y+1];
            }
            //   int g=0;
            c[n]=b[1];
            for(long long int y=1; y<=n; y++)
            {   if(a[y]==c[y])
                    o1++;

            }

            for(long long int y=1; y<n; y++)
            {

                d[y]=c[y+1];
            }
            //   int g=0;
            d[n]=c[1];
            for(long long int y=1; y<=n; y++)
            {   if(a[y]==d[y])
                    o2++;

            }
            if(o2<=o1 && o2<=o)
            {
                cout<<n-o2<<endl;

                for(long long int y=1; y<=n; y++)
                {

                    cout<<d[y]<<" ";
                }
            }
            else if(o1<=o2 && o1<=o)
            {
                cout<<n-o1<<endl;

                for(long long int y=1; y<=n; y++)
                {

                    cout<<c[y]<<" ";
                }
            }
            else    if(o<=o1 && o<=o2)
            {
                cout<<n-o<<endl;

                for(long long int y=1; y<=n; y++)
                {

                    cout<<b[y]<<" ";
                }
            }
            cout<<endl;
        }
    }
}




