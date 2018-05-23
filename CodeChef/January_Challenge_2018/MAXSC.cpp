#include <bits/stdc++.h>


using namespace std;
int main() {

    long long  int f=0,x1,index1,index2;
    long long  int n,l,g,ne;
    long int u,v;
    string s;

    cin>>x1;

    long int max=0;


    long int a[701][701];

    bool visited[10001];
    for(int i=0; i<10001; i++)
        visited[i]=false;

    for(long int y2=0; y2<x1; y2++)
    {
        v=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>a[i][j];
            sort(a[i],a[i]+n);
        }
        long int t=0;
        long int o=a[n-1][n-1];
        long int s=o;
        for(int i=n-2; i>=0; i--)
        {
            long int c=0;
            for(int j=n-1; j>=0; j--)
            {
                if(a[i][j]<o)
                {
                    c=1;
                    o=a[i][j];
                    s+=a[i][j];
                    break;
                }
            }
            if(c==0)
            {
                t=1;
                break;
            }

        }

        if(t==0)
            cout<<s<<endl;
        else
            cout<<"-1"<<endl;
    }
    return 0;
}


