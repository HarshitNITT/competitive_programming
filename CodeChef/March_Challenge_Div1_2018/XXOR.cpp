using namespace std;

typedef long long int ll;
ll block;
bool cmp(pair<ll,pair<ll,ll>> x,pair<ll,pair<ll,ll>> y)
{
    if(x.first/block!=y.first/block)
    {
        return (x.first/block<y.first/block);
    }
    else
        return (x.second.first<y.second.first);
}
int main() { /// x -> v; y -> h
    ll  q,n;
    cin>>n>>q;
    vector<vector<ll>> c(n);

    ll a[n]= {0};
    vector<pair<ll,pair<ll,ll>>>b;
    ll w[31][2];
    for(ll m=0; m<31; m++)
    {
        w[m][0]=0;
        w[m][1]=0;
    }
    block=sqrt(n);
    // cin>>q;

    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
        ll o=0;
        ll m=a[i];
        while(m!=0)
        {
            if(m%2==1)
                c[i].push_back(o);
            m/=2;
            o++;
        }

    }
    for(ll w1=0; w1<q; w1++)
    {
        ll k,m;
        scanf("%lld %lld",&k,&m);
        b.push_back(make_pair(k-1,make_pair(m-1,w1)));


    }
    sort(b.begin(),b.end(),cmp);

    ll o=0;


    ll m=0;
    ll cnt=0;
    ll v=0;


    ll z[q];
    ll s[31];
    ll l=0;
    ll r=-1;
    for(ll o=0; o<q; o++)
    {

        while(l<b[o].first)
        {
            for(ll u=0; u<c[l].size(); u++)
            {
                w[c[l][u]][1]--;
            }

            l++;
        }
        while(l>b[o].first)
        {
            l--;
            for(ll u=0; u<c[l].size(); u++)
            {
                w[c[l][u]][1]++;
            }
        }
        while(r>b[o].second.first)
        {
            for(ll u=0; u<c[r].size(); u++)
            {
                w[c[r][u]][1]--;
            }

            r--;

        }

        while(r<b[o].second.first)
        {
            r++;
            for(ll u=0; u<c[r].size(); u++)
            {
                w[c[r][u]][1]++;
            }
        }
        // cout<<endl;




        ll f=0;
        for(ll y=0; y<31; y++)
        {

            if(b[o].second.first-b[o].first+1-w[y][1]>w[y][1])
            {

                f+=pow(2,y);
            }


        }



        z[b[o].second.second]=f;

    }

    for(ll m=0; m<q; m++)
        printf("%lld\n",z[m]);


    return 0;
}
