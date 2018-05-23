#include <bits/stdc++.h>


using namespace std;
int main() {

    long long  int f=0,x1,index1,index2;
    long long  int n,l,g,ne;
    long int u,v;
    string s;

    cin>>x1;

    long int max=0;


    long int a[4];

    bool visited[10001];
    for(int i=0; i<10001; i++)
        visited[i]=false;

    for(long int y2=0; y2<x1; y2++)
    {
        v=0;
        for(int i=0; i<4; i++)
            cin>>a[i];
        sort(a,a+4);
        for(int i=0; i<3; i+=2)
        {
            if(a[i]!=a[i+1])
                v=1;
        }
        if(v==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}



