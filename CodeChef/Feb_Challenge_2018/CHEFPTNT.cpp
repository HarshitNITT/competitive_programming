#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long int ll;
int main() {
    ll t,n,m,x,k;
    cin >> t;
    for(ll o=0; o<t; o++)
    {
        ll cnt=0,cnt1=0;
        // string s;
        ll r,r1;
        cin>>n;
        cin>>m;
        cin>>x;
        cin>>k;
        //cin>>s;
        for(ll i=0; i<k; i++)
        {
            char l;
            cin>>l;
            if(l=='E')
                cnt++;
            else
                cnt1++;
        }
        ll cnt2=min(x,cnt);

        r=cnt2*(m/2);
        if(r>cnt)
            r=cnt;

        ll cnt3=min(x,cnt1);

        r1=cnt3*(m/2+m%2);
        if(r1>cnt1)
            r1=cnt1;
        // cout<<r+r1<<endl;
        if(r+r1>=n)
        {
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;

    }
    return 0;
}