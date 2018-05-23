#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll binarySearch(vector<pair<ll,ll>> arr,ll l, ll r,ll x)
{
    if (r >= l)
    {
        ll mid = l + (r - l)/2;
        if (arr[mid].first == x)
            return mid;
        if (arr[mid].first > x)
            return binarySearch(arr, l, mid-1, x);

        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}
bool comp(const pair<ll,ll> &a,
          const pair<ll,ll> &b)
{
    return (a.first < b.first);
}
map<ll,ll>m;
map<ll,ll>m1;
ll g[10000001];
ll g1[10000001];
vector<pair<ll,ll>>w1;
vector<pair<ll,ll>>w2;
int main()
{
    ll n,q,t;
    cin>>t;
    for(ll sq=0; sq<t; sq++)
    {
        cin>>n>>q;

        vector<pair<ll,ll>>a;
        vector<pair<ll,ll>>z;
        ll quer[n+1];
        for(ll i=1; i<=n; i++)
        {
            ll cur;
            cin>>cur;
            a.push_back(make_pair(cur,i));
            // cout<<a[i-1].first<<" "<<a[i-1].second<<endl;
            quer[i]=cur;

        }
        //  cout<<"op"<<endl;
        sort(a.begin(),a.end(),comp);
        for(ll sd=0; sd<q; sd++)
        {

            ll search;
            cin>>search;
            z.push_back(make_pair(search,sd));

        }
        sort(z.begin(),z.end(),comp);

        vector<pair<ll,ll>>important;
        for(ll o=0,g=0;;)
        {
            if(g==z.size())
            {
                break;
            }

            if(a[o].first==z[g].first)
            {
                important.push_back(make_pair(o+1,a[o].second));


                ll m=z[g].first;
                g++;
                for(;;)
                {
                    if(z[g].first==m)
                    {
                        important.push_back(make_pair(o+1,a[o].second));
                        g++;
                    }
                    else
                        break;
                }
                o++;
                continue;
            }
            else
                o++;


        }

        ll ans[q];
        for(ll o=0; o<q; o++)
        {
            // cout<<important[o].first<<" "<<important[o].second<<endl;
            ll  val1=important[o].first;
            ll val=important[o].second;


            vector<ll>w;

            ll low=1;
            ll high=n;
            for(ll o=0;; o++)
            {

                if(((low+high)/2)<val)
                {
                    w.push_back((low+high)/2);
                    low=((low+high)/2)+1;

                }
                else if(((low+high)/2)>val)
                {
                    w.push_back((low+high)/2);
                    high=((low+high)/2)-1;
                }
                else
                    break;

            }
            ll small=0,large=0,q1=0,qe=0;;
            ll e=val1-1;
            ll e1=n-val1;
            ll qw=0,aw=0;
            for(ll o=0; o<w.size(); o++)
            {
                if(w[o]<val) {
                    qw++;
                }
                else
                    aw++;

            }
            if(qw>e)
            {
                ans[z[o].second]=-1;
                continue;
            }
            if(aw>e1) {
                ans[z[o].second]=-1;
                continue;
            }
            for(ll o=0; o<w.size(); o++)
            {
                // cout<<w[o]<<" ";
                if(w[o]<val && quer[w[o]]>quer[val])
                {   small++;


                }

                else if(w[o]<val && quer[w[o]]<quer[val])
                    q1++;
                else if(w[o]>val && quer[w[o]]<quer[val])
                {
                    large++;
                }
                else if(w[o]>val && quer[w[o]]>quer[val])
                    qe++;
            }
            // cout<<endl;
            ll k=min(large,small);
            //cout<<val1<<q1<<qe<<w.size()<<endl;
            if(large>small)
            {
                ll y=large-small;
                if(y<=n-val1-small-qe)
                {
                    ans[z[o].second]=k+y;
                    // cout<<k+y<<" "<<z[o].second<<" "<<ans[z[o].second]<<endl;

                }

            }
            else if(large<small)
            {
                ll o1=small-large;
                if(o1<=val1-1-large-q1)
                {
                    ans[z[o].second]=k+o1;
                    //  cout<<k+o1<<" "<<z[o].second<<" "<<ans[z[o].second]<<endl;
                }

            }
            else
            {
                ans[z[o].second]=k;
                // cout<<k<<" "<<z[o].second<<" "<<ans[z[o].second]<<endl;
            }
            w.clear();

        }

        for(ll o=0; o<q; o++)
            cout<<ans[o]<<endl;
        important.clear();
        a.clear();
        z.clear();
    }
    return 0;
}