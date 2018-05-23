#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main() {
    ll  q,n;

    cin>>n;
    ll a[n];
    cin>>q;
    for(ll o=0; o<n; o++)
    {
        cin>>a[o];

    }
    //sort(a,a+n);
    ll l=0,f=0;

    ll e[n];
    for(ll o=0; o<q; o++)
    {
        ll u;
        cin>>u;
        if(u==1)
        {
            ll p,v;
            cin>>p>>v;
            a[p-1]=v;
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            l--;
            r--;
            for(ll i=l; i<=r; i++)
            {
                e[i-l]=a[i];
            }

            sort(e,e+r-l+1);
            ll w=0;
            for(ll j=r-l; j>=2; j--)
            {
                //cout<<j<<endl;
                if(e[j]<e[j-1]+e[j-2])
                {
                    w=e[j]+e[j-1]+e[j-2];
                    break;
                }
            }
            cout<<w<<endl;
        }
    }




    return 0;
}