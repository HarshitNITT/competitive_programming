#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main() {
    ll  q,n;
    cin>>q;

    for(ll m3=0; m3<q; m3++)
    {
        cin>>n;
        ll a[n];

        for(ll o=0; o<n; o++)
        {
            cin>>a[o];

        }
        sort(a,a+n);
        ll l=0,f=0;
        for(ll o=0; o<n-1; o++)
        {
            if(a[o]!=a[o+1])
            {
                f+=o-l;
                l=o+1;
            }

        }
        f+=n-1-l;
        cout<<f<<endl;

    }
    return 0;
}