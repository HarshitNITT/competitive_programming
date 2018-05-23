#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1000000007;
ll d,l;

ll power(ll x,ll y,ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
ll modDivide(ll a,ll b)
{
    return  (((a+100000*M)%M)*(power(b,M-2,M)%M))%M;
}
map<ll,ll>m;

ll h(ll o)
{
    //cout<<o<<endl;
    if(o==0)
        return 1;
    if(o==1)
    {
        // cout<<modDivide(d,l)<<endl;
        // cout<<d<<l<<endl;
        if(m.count(o)==0)
            m[o]=modDivide(d,l);
        return m[o];

    }
    else if(o%2==0)
    {

        // cout<<t<<endl;
        // cout<<p<<m<<endl;
        if(m.count(o)==0)
        {
            ll t=h(o/2);
            m[o]=(2*((t)*(t))%M-1+100000*M)%M;
        }
        return m[o];
    }
    else
    {
        if(m.count(o)==0)
        {

            m[o]=(2*h(o/2+1)*h(o/2)-h(1)+100000*M)%M;
        }
        return m[o];

    }

}
int main()
{

    ll n,s=0;
    cin>>n;
    ll a[n],b[n],c[n];
    for(ll p=0; p<n; p++)
    {
        ll t;
        cin>>l>>d>>t;

        ll t1=h(t);

        cout<<(l*(t1))%M<<endl;
        m.clear();

        // cout<<modDivide(t1.first*l,t1.second)<<endl;
        // cin>>d>>l;
    }




    return 0;
}