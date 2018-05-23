#include <bits/stdc++.h>

using namespace std;



typedef long long int ll;

void q(ll index,ll end,ll t[])
{


    if(index>=(end))
    {
        return;
    }

    if((index+2)==(end))
    {



        if(t[index]>t[index+2])
        {
            t[index]=-t[index];
        }

        else
            t[index+2]=-t[index+2];
        return;


    }

    if(t[index+2]<=t[index]+t[index+4])
    {

        q(index+6,end,t);



        t[index]=-t[index];
        t[index+4]=-t[index+4];

        return;
    }
    if(t[index+2]>=t[index])
    {

        q(index+4,end,t);
        t[index+2]=-t[index+2];

        return;

    }
    if(t[index]>t[index+2] && t[index+2]>t[index]+t[index+4])
    {

        ll g=t[index]+t[index+4];
        ll g1=t[index+2];
        vector<ll>k1;
        vector<ll>k;
        k1.push_back(index+2);
        k.push_back(index);
        k.push_back(index+4);
        for(ll o=6;; o=o+2)
        {
            if((index+o)>(end))
                break;
            else
            {
                if((o/2)%2==0)
                {
                    g+=t[index+o];
                    k.push_back(index+o);
                    if(g>=g1)
                    {
                        q(index+o+2,end,t);

                        for(ll o2=0; o2<k.size(); o2++)
                        {
                            t[k[o2]]=-t[k[o2]];

                        }
                        return;
                    }

                }
                else
                {
                    g1+=t[index+o];
                    k1.push_back(index+o);
                    if(g1>=g)
                    {
                        q(index+o+2,end,t);

                        for(ll o2=0; o2<k1.size(); o2++)
                        {
                            t[k1[o2]]=-t[k1[o2]];
                        }
                        return;
                    }

                }

            }

        }
        if(g>g1)
        {
            for(ll o=0; o<k.size(); o++)
            {
                t[k[o]]=-t[k[o]];

            }
        }
        else
        {
            for(ll o=0; o<k1.size(); o++)
            {
                t[k1[o]]=-t[k1[o]];

            }
        }
        k.clear();
        k1.clear();
        return;
    }




}
int main()
{
    ll t2,n;
    scanf("%lld",&t2);

    for(ll i1=0; i1<t2; i1++)
    {
        scanf("%lld",&n);
        ll a[n];
        for(ll i=0; i<n; i++)
            scanf("%lld",&a[i]);
        if(a[0]<a[1] )
        {
            a[0]=-a[0];
        }
        for(ll u=1; u<n-1; u++)
        {
            if(a[u]<a[u-1] && a[u]<a[u+1] )
                a[u]=-a[u];
        }
        if(a[n-1]<a[n-2] )
            a[n-1]=-a[n-1];



        ll flag=-1;
        ll val2=0;
        for(ll i=1; i<n-1; i++)
        {
            if(a[i]>0)
            {
                if(a[i-1]+a[i]+a[i+1]<=0 )
                {
                    val2=i+1;
                    if(flag==-1)
                        flag=i-1;
                }
                else if(flag!=-1)
                {
                    q(flag,val2,a);


                    flag=-1;

                }

            }

        }
        if(flag!=-1)
        {
            q(flag,val2,a);


            flag=-1;

        }


        for(ll i=0; i<n; i++)
        {
            printf("%lld ",a[i]);

        }
        printf("\n");
    }
    return 0;
}