#include <bits/stdc++.h>
using namespace std;
long int  a[1000020];

int main() {

    string x1;
    long  int p,m,q,y;



    cin>>x1;
    vector<string>s;
    vector<char>l;
    for(long  int i=0; i<x1.length(); i++)
    {
        for(int o=1; o<=x1.length()-i; o++)
        {
            s.push_back(x1.substr(i,o)) ;
        }
    }
    sort(s.begin(),s.end());

    for(int i=0; i<s.size(); i++)
    {
        for(int u=0; u<s[i].size(); u++)
            l.push_back(s[i][u]);
        // cout<<s[i]<<endl;
    }

    cin>>q;
    long int h=0;
    for(int y=0; y<q; y++)
    {
        cin>>p>>m;
        cout<< l[(p*h)%m]<<endl;
        h+=l[(p*h)%m];
        // cout<<h<<endl;


    }


    return 0;
}