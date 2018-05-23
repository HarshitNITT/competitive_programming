#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
vector<ll>w;
int main()
{
    ll t,k,q,c,d;
    string s;
    ll  n;

    cin>>t;

    ll e=0;
    //ll j=0;


    for(ll j=0; j<t; j++)
    {

        cin>>s;
        ll a[123];
        for(ll i=97; i<=122; i++)
        {
            a[i]=0;
        }
        ll o=0;
        ll o1[s.length()];
        vector<vector<ll>>w(123);
        for(ll i=0; i<s.length(); i++)
        {
            a[s[i]]++;
            w[s[i]].push_back(i+1);
        }
        for(ll i=97; i<=122; i++)
        {
            if(a[i]%2==1)
                o++;
        }
        if(o>1)
            cout<<"-1";
        else
        {
            ll e=0,u=0,k=s.length()-1;
            for(ll i=97; i<=122; i++)
            {
                if(w[i].size()%2==0)
                {
                    for(ll j=0; j<w[i].size()/2; j++)
                    {
                        o1[u]=w[i][j];
                        o1[s.length()-1-u]=w[i][w[i].size()-1-j];
                        u++;
                        k--;
                    }
                }
                else
                {
                    e=i;
                }
            }
            if(e!=0)
            {

                for(ll j=0; j<w[e].size(); j++)
                {

                    o1[u]=w[e][j];
                    u++;

                }

            }
            for(ll t=0; t<s.length(); t++)
                cout<<o1[t]<<" ";

        }

        cout<<endl;
        for(ll m=0; m<123; m++)
            w[m].clear();
    }
    return 0;
}