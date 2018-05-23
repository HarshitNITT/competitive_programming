#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 vector<vector<ll>>adj(100001);
ll parent[100001]={-1};
ll parent1[100001]={-1};
ll find(ll i)
{
    if (parent1[i] == -1)
        return i;
    return find( parent1[i]);
}
void dfs(ll s,bool visited[])
{
    visited[s] = true;
    
    for(ll i=0;i<adj[s].size();i++)
    { 
        if(!visited[adj[s][i]] )
        {
            parent[adj[s][i]]=s;
            dfs(adj[s][i],visited);  
            
        }  
    }
 
}
bool sortbysec(pair<ll,pair<ll,ll>> &a,
              pair<ll,pair<ll,ll>> &b)
{
    return (a.first < b.first);
}
// A utility function to do union of two subsets 
void Union(ll x,ll y)
{
    ll xset = find( x);
    ll yset = find( y);
    parent1[xset] = yset;
}
 
int main()
{
    ll u=0,t,n;
   
        ll k;
       cin>>t;
        for(ll r=0;r<t;r++)
        {
            cin>>n;
            ll a[n][n];
            
            for(ll o=0;o<n;o++)
            {
                for(ll k=0;k<n;k++)
                    cin>>a[k][o];
            }
        
            ll j=0;
            ll total=0;
            bool f=false;
            for(ll o=0;o<n;o++)
            {
                for(ll k=0;k<n;k++)
                {
                    if(a[k][o]>1 || a[o][k]>1)
                        f=true;
                    if(a[k][o]!=a[o][k] )
                    { 
                    
                    if(a[k][o]>a[o][k])
                    {
                        j+=a[k][o]-a[o][k];
                        a[o][k]=a[k][o];
                    }
                    else
                    {
                        j+=a[o][k]-a[k][o];
                        a[k][o]=a[o][k];   
                    }
                    }
               
                
                }
            }
            bool visited1[n]={false};
            ll p=0;
            vector<pair<ll,pair<ll,ll>>>l;
            vector<ll>qw;
            vector<ll>q;
            ll flag=0;
            for(ll o=0;o<n;o++)
            {
                ll e=0;
                if(!visited1[o])
                {
                   // e++;
                    visited1[o]=true;
                    q.push_back(o);
                    qw.push_back(o);
                   
                    while(q.size())
                    {
                        for(ll n1=0;n1<n;n1++)
                        {
                            if(a[q[0]][n1])
                            {
                     
                                if(!visited1[n1])
                                {
                                    e++;
                                    visited1[n1]=true;
                                    q.push_back(n1);
                                    // l.push_back(make_pair(a[q[0]][n1],make_pair(n1,q[0])));
                                    qw.push_back(n1);
                    
                                }
                           
                            }
                        }
                        q.erase(q.begin());
                    }
                
               
                    sort(qw.begin(),qw.end());
                    //cout<<qw.size()<<endl;
                    for(ll p=0;p<qw.size();p++)
                    {
                       for(ll p1=p+1;p1<qw.size();p1++)
                        {
                            if(a[qw[p1]][qw[p]])
                            {
                                l.push_back(make_pair(a[qw[p1]][qw[p]],make_pair(qw[p1],qw[p])));
                            }
                        }
                    }
                    sort(l.begin(),l.end(),sortbysec);
                    
//                     cout<<l.size()<<" wow "<<qw.size()<<endl;
                    for(ll o1=0;o1<=n;o1++)
                    {
                        // cout<<o<<": ";
                        parent1[o1]=-1;
                        parent[o1]=-1;
                    }
                    for(ll uy=l.size()-1;uy>=0;uy--)
                    {
                        // cout<<l[uy].first<<" "<<l[uy].second.second<<" J "<<l[uy].second.first<<" "<<find(l[uy].second.second)<<" "<<find(l[uy].second.first)<<endl;
                        if(find(l[uy].second.second)!=find(l[uy].second.first))
                        {
                            Union(l[uy].second.second,l[uy].second.first);
                            adj[l[uy].second.second].push_back(l[uy].second.first);
                            adj[l[uy].second.first].push_back(l[uy].second.second);
                        //  cout<<"op"<<endl;
                        }
                    }
                    bool visited[n];
                    for(ll om=0;om<n;om++)
                    {
                        // cout<<om<<": ";
                        // for(ll p=0;p<adj[om].size();p++)
                        //     cout<<adj[om][p]<<" ";
                        // cout<<endl;
                        visited[om]=false;  
                      
                    }
                    dfs(qw[0],visited);
                    for(ll om=0;om<qw.size();om++)
                    {
                        for(ll sde=om+1;sde<qw.size();sde++)
                        {
                            
                            ll h=0,g=0;
                            ll w=qw[om];
                            ll b=qw[sde];
                            ll p=w;
      
                            for(;p!=-1;)
                            {
                                p=parent[p];
                                h++;
                            }
                            p=b;
        
                            for(;p!=-1;)
                            {
                                p=parent[p];
                                g++;
                            }
                           
                            ll a1=b;
                            ll  a2=w;
                            ll min1=100000000000;
                            
                            if(g>h)
                            {
  
                                for(ll i=0;i<g-h;i++)
                                {   
                                    min1=min(min1,a[a1][parent[a1]]);
                                    a1=parent[a1];
                                }
    
                            }
                            if(h>g)
                            {
   
                                for(ll i=0;i<h-g;i++)
                                {
                                    min1=min(min1,a[a2][parent[a2]]);
                                    // cout<<a2<<" "<<parent[a2]<<" "<<o<<" "<<y<<endl;
                                    a2=parent[a2];
                                }
    
                            }
       
                            while(a1!=a2)
                            {
                                min1=min(min1,a[a1][parent[a1]]);
                                min1=min(min1,a[a2][parent[a2]]);
                                a2=parent[a2];
                                a1=parent[a1];
                            }
                            j+=2*(min1-a[qw[om]][qw[sde]]);
                            
                            // cout<<min1<<" "<<a[qw[om]][qw[sde]]<<" "<<min1-a[qw[om]][qw[sde]]<<" "<<qw[om]<<" "<<qw[sde]<<endl;
                            a[qw[om]][qw[sde]]=min1;
                            a[qw[sde]][qw[om]]=min1;
                        }
                    }
 
                    l.clear();
                    qw.clear();
                }
                // for(ll i=0;i<n;i++)
                // {
                //     for(ll j=0;j<n;j++)
                //     {
                //         cout<<a[j][i]<<" ";
                //     }
                //     cout<<endl;
                // }
                // cout<<j<<endl;
                for(ll i=0;i<=n;i++)
                {
                parent[i]=-1; 
                parent1[i]=-1;
                adj[i].clear();
                }
            }
        
            // for(ll i=0;i<n;i++)
            // {
            //     for(ll j=0;j<n;j++)
            //     {
            //         cout<<a[j][i]<<" ";
            //     }
            //     cout<<endl;
            // }
            cout<<j<<endl;
            
        }
    
    
       // cout<<q<<endl;
    
    return 0;
} 
 
  
