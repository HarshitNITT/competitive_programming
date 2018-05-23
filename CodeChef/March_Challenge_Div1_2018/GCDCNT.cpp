#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll N = 100005;
const ll M = 100005;
const ll LN = 17;
ll result[N];
vector < ll > f[M];
ll n , q;
ll arr[N];
ll cur;

struct templ
{
    bool update;
    ll index;
    ll val;
    ll id;
};
vector < templ > templs[M];
ll marr[N];
ll level[N];
ll marr1[N];
ll dynpro[LN][N];
vector < ll > adj[N];
void dfs(ll s , ll parent)
{
    marr[s] = ++cur;
    dynpro[0][s] = parent;
    level[s] =level[parent] + 1;
    for(ll children : adj[s])
    {
        if(children != parent)
        {
            dfs(children , s);
        }
    }
    marr1[s] = cur;
}
ll bset[N];
void update(ll index , ll val)
{
    while(index <= n)
    {
        bset[index] += val;
        index += index & -index;
    }
}

void update(ll index , ll l , ll r , ll val , ll h)
{
    templs[index].push_back({1 , l , val , h});
    templs[index].push_back({1 , r + 1 , -val , h});
}
ll query(ll index)
{
    ll res = 0;
    while(index)
    {
        res += bset[index];
        index -= index & -index;
    }
    return res;
}
ll ancestor(ll a , ll b)
{
    ll sub = level[a] - level[b];
    if(sub < 0)
    {
        sub = -sub;
        swap(a , b);
    }
    for(ll i = 0 ; i < LN ; ++i)
    {
        if(sub & (1 << i))
        {
            a = dynpro[i][a];
        }
    }
    if(a != b)
    {
        for(ll i = LN - 1 ; i >= 0 ; --i)
        {
            if(dynpro[i][a] != dynpro[i][b])
            {
                a = dynpro[i][a];
                b = dynpro[i][b];
            }
        }
        a = dynpro[0][a];
    }
    return a;
}
ll type[N] , x[N] , y[N] , z[N];
ll parent[N];
ll al[M];
void query(ll a , ll b , ll c , ll index)
{
    parent[index] = ancestor(a , b);
    for(ll it : f[c])
    {
        templs[it].push_back({0 , 0 , 0 , index});
    }
}
ll add(ll a , ll b , ll lca)
{
    return query(marr[a]) + query(marr[b]) - query(marr[lca]) - query(marr[dynpro[0][lca]]);
}
void clear(ll index)
{
    while(index <= n)
    {
        bset[index] = 0;
        index += index & -index;
    }
}
void solve(ll val)
{
    for(auto it : templs[val])
    {
        if(it.update)
        {
            update(it.index , it.val);
        }
        else
        {
            result[it.id] += add(x[it.id] , y[it.id] , parent[it.id]) * al[val];
        }
    }
    for(auto it : templs[val])
    {
        if(it.update)
        {
            clear(it.index);
        }
    }
}
void process() {
    for(ll i = 0 ; i < M ; ++i)
    {
        al[i] = 1;
        f[i].clear();
        f[i].emplace_back(1);
    }
    for(ll i = 2 ; i < M ; ++i)
    {
        if(f[i].size() == 1)
        {
            for(ll j = i ; j < M ; j += i)
            {
                al[j] *= -1;
            }
            for(ll j = i * i ; j < M ; j += i * i)
            {
                al[j] = 0;
            }
        }
        if(al[i])
        {
            for(ll j = i ; j < M ; j += i)
            {
                f[j].emplace_back(i);
            }
        }
    }
}
int main()
{

    scanf("%lld",&n);
    process();
    for(ll i = 1 ; i <= n ; ++i)
    {
        scanf("%lld" , &arr[i]);
    }

    for(ll i = 1 ; i < n ; ++i)
    {
        adj[i+1].emplace_back(i);
        adj[i].emplace_back(i+1);
    }


    scanf("%lld",&q);
    dfs(1 , 0);
    for(ll i = 1 ; i < LN ; ++i)
    {
        for(ll j = 1 ; j <= n ; ++j)
        {
            dynpro[i][j] = dynpro[i - 1][dynpro[i - 1][j]];
        }
    }
    for(ll i = 1 ; i <= q ; ++i)
    {
        scanf("%lld %lld %lld" , type + i , x + i , y + i);
        if(type[i]==2)
        {
            scanf("%lld" , z + i);
        }
    }
    for(ll i = 1 ; i <= n ; ++i)
    {
        for(ll x : f[arr[i]])
        {
            update(x , marr[i] , marr1[i] , 1 , 0);
        }
    }
    for(ll i = 1 ; i <= q ; ++i)
    {
        if(type[i]==2)
        {
            query(x[i] , y[i] , z[i] , i);
        }
        else
        {
            for(ll it : f[arr[x[i]]])
            {
                update(it , marr[x[i]] , marr1[x[i]] , -1 , i);
            }
            arr[x[i]] = y[i];
            for(ll it : f[arr[x[i]]])
            {
                update(it , marr[x[i]] ,marr1[x[i]] , 1 , i);
            }
        }
    }
    for(ll i = 1 ; i < M ; ++i)
    {
        solve(i);
    }
    for(ll i = 1 ; i <= q ; ++i)
    {
        if(type[i]==2)
        {
            printf("%lld\n" , result[i]);
        }
    }
}
