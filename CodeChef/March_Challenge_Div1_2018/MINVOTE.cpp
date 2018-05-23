#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll block;
/* ceil and floor functions  are taken from geeksforgeeks*/
ll ceil(ll a[], ll l, ll r, ll val)
{
    ll m;


    if(val <= a[l])
        return l;


    if(val > a[r])
        return -1;


    m = (l + r)/2;


    if(a[m] == val)
        return m;



    else if(a[m] < val)
    {
        if(m + 1 <= r && val <= a[m+1])
            return m + 1;
        else
            return ceil(a, m+1,r, val);
    }


    else
    {
        if(m - 1 >= l && val > a[m-1])
            return m;
        else
            return ceil(a, l, m - 1, val);
    }
}
ll floor(ll a[], ll l, ll r, ll val)
{

    if (l > r)
        return -1;


    if (val >= a[r])
        return r;


    ll m = (l+r)/2;


    if (a[m] == val)
        return m;


    if (m > 0 && a[m-1] <= val && val < a[m])
        return m-1;


    if (val < a[m])
        return floor(a, l, m-1, val);


    return floor(a, m+1, r, val);
}

int main() {
    ll  q,n;
    cin>>q;

    for(ll m3=0; m3<q; m3++)
    {
        cin>>n;
        ll a[n];

        ll p[n]= {0};
        ll v[n+2]= {0};
        ll cv=0;
        for(ll o=0; o<n; o++)
        {
            cin>>a[o];
            p[o]+=cv+a[o];
            cv=p[o];
        }
        for(ll k=0; k<n; k++)
        {
            ll d=p[k];
            ll d1=p[k]+a[k];
            ll m1=floor(p,k,n-1,d+a[k]);
            ll  m=ceil(p,0,k,d-2*a[k]);

            // cout<<k<<" "<<m<<" "<<m1<<endl;
            v[m]+=1;
            v[m1+2]+=-1;
            v[k]+=-1;
            v[k+1]+=1;
        }
        ll o=0;
        for(ll j=0; j<n; j++)
        {
            //cout<<v[j]<<" "<<endl;
            // v[j]+=o;
            cout<<v[j]+o<<" ";
            //   cout<<v[j]<<" ";
            o+=v[j];
        }
        cout<<endl;
    }
    return 0;
}