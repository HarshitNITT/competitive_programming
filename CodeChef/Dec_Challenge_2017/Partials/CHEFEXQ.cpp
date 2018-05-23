#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int q=0,n,m,s[2000002],e=0,max=1,o=0,a1,b,c;
    long long  int  a[2000002];
    cin>>n;


    cin>>q;
    for(long long int y=1; y<=n; y++)
    {
        cin>>a[y];
        o=o^a[y];
        s[y]=o;



    }
    for(long long  int k=0; k<q; k++)
    {
        cin>>a1>>b>>c;
        if(a1==1)
        {
            int g=a[b];
            a[b]=c;
            for(int i=b; i<=n; i++)
            {
                s[i]=s[i]^a[b]^g;
            }

        }
        if(a1==2)
        {
            int y=0;
            for(int i=1; i<=b; i++)
            {

                if(s[i]==c)
                    y++;
            }
            cout<<y<<endl;
        }
    }
}