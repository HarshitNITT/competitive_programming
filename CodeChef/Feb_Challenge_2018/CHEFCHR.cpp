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
    string s;
    for(ll o=0; o<t; o++)
    {
        vector<char>a;
        ll cnt=0,cnt1=0;

        ll r,r1;

        cin>>s;
        for(ll i=0; i<s.length(); i++)
        {
            if(s[i]>=65 && s[i]<=90)
                a.push_back(s[i]+32);
            if(s[i]>=97 && s[i]<=122)
                a.push_back(s[i]);


        }

        r=0;
        if(a.size()>3)
        {
            for(ll o=0; o<a.size()-3; o++)
            {
                char w[4];
                w[0]=a[o];
                w[1]=a[o+1];
                w[2]=a[o+2];
                w[3]=a[o+3];

                sort(w,w+4);
                if(w[0]=='c' && w[1]=='e'&& w[2]=='f' && w[3]=='h')
                    r++;

            }
        }
        if(r==0)
            cout<<"normal"<<endl;
        else
            cout<<"lovely "<<r<<endl;
        a.clear();
        s.clear();

    }
    return 0;
}
