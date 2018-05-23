#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
vector<ll>w;
int main()
{
    ll t,k,q,c,d,s;
    ll  n;

    cin>>t;

    ll e=0;
    //ll j=0;


    for(ll j=0; j<t; j++)
    {

        cin>>n;
        ll a[100001];

        for(ll i=0; i<n; i++)
        {
            cin>>a[i];


        }

        cin>>c>>d>>s;

        ll o=a[0];
        ll k=(c-1)*a[0];
        for(ll i=1; i<n; i++)
        {


            if(a[i]<=o)
            {

            }
            else
            {
                k+=(c-1)*(a[i]-o);
                o=a[i];
            }

        }
        cout<<k<<".000000000"<<endl;
    }
    return 0;
}