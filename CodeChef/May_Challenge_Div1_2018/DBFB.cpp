#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1000000007;
pair<ll,ll>a[100001];
int main()
{

    ll t,n,m;
    cin>>t;
    for(ll b=0; b<t; b++)
    {
        cin>>m>>n;

        a[1]=make_pair(1,0);
        a[2]=make_pair(0,1);
        for(ll r=3; r<=n; r++)
        {
            a[r]=make_pair((a[r-1].first+a[r-2].first%M),(a[r-1].second+a[r-2].second%M));

        }
        // cout<<a[n].first<<endl;
        ll s=0,s1=0;
        for(ll o=0; o<m; o++)
        {
            ll k;
            cin>>k;
            s+=k;
        }
        for(ll o=0; o<m; o++)
        {
            ll k1;
            cin>>k1;
            s1+=k1;
        }
        cout<<(m*((((a[n].first%M)*(s%M))%M+((a[n].second%M)*(s1%M))%M)%M))%M<<endl;
    }
    return 0;
}