#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



typedef long long int ll;
int main() {
    ll o,i,n,as;
    cin>>as;
    for(ll y=0; y<as; y++)
    {
        cin>>n;
        ll a[n][2],r,t;
        for(ll o=0; o<n; o++)
        {
            cin>>a[o][0]>>a[o][1];

        }
        cin>>t;
        for(ll p=0; p<t; p++)
        {
            cin>>r;
            ll x[r];
            ll h=0;
            for(ll j=0; j<r; j++)
                cin>>x[j];
            for(ll o=0; o<n; o++)
            {
                ll m=0;
                for(ll j=0; j<r; j++)
                {
                    if(x[j]>=a[o][0] && x[j]<=a[o][1])
                        m++;
                }
                if(m%2==1)
                    h++;
            }
            cout<<h<<endl;
        }
    }
    return 0;
}

