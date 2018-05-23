#include <bits/stdc++.h>
using namespace std;
char s1[1000020],a[1000020];
vector<char>a1;
vector<char>s2;
int y[5001][5001];
int u[5001][5001][2];
long int max1=1000000;
void f(long int index,long int s,long int t,long int x,long int n)
{
    if(t==x)
    {
        // cout<<s<<endl;
        if(s<max1)
            max1=s;
        return;
        // cout<<s<<endl;
    }
// cout<<a[t]<<s<<endl;
    if(index==n)
    {
        //cout<<s<<endl;
        long int p=0;
        for(int j=t; j<x-1; j++)
        {

            if(a[j]!=a[j+1])
            {
                p++;
            }
        }
        if(s+p+1<max1)
            max1=s+p+1;
        return;
    }
    char e=a[t];
    for(int i=index; i<n; i++)
    {
        if(s1[i]==e)
        {
            int j=0;
            for(j=t; j<x-1; j++)
            {
                if(a[j]!=a[j+1])
                {
                    break;
                }
            }
            long int j1;

            for( j1=i; j1<n-1; j1++)
            {
                if(s1[j1]!=s1[j1+1])
                    break;
            }
            f(j1+1,s,j+1,n,x);
            break;
        }
    }
    if(max1==1)
        return;
    if(s1[index]!=e)
    {
        for(int i=index; i<n; i++)
        {
            if(index>0)
            {
                if( s1[i]!=s1[i-1] )
                {
                    int j=0;
                    for(j=t; j<x-1; j++)
                    {
                        if(a[j]!=a[j+1])
                        {
                            break;
                        }
                    }
                    f(i,s+1,j+1,n,x);
                    break;
                }
            }
            else
            {
                int j=0;
                for(j=t; j<x-1; j++)
                {
                    if(a[j]!=a[j+1])
                    {
                        break;
                    }
                }
                f(i,s+1,j+1,n,x);
                break;

            }

        }
        if(index>0&& s1[index]==s1[index-1])
        {
            int j=0;
            for(j=t; j<x-1; j++)
            {
                if(a[j]!=a[j+1])
                {
                    break;
                }
            }
            f(index,s+2,j+1,n,x);

        }


    }
    if(max1==1)
        return;

}

using namespace std;
int main() {

    long  int x1;
    long  int n,x;



    cin>>x1;

    long int o=0;

    for(long int y2=0; y2<x1; y2++)
    {

        cin>>x>>n;

        for(int i=0; i<x; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
        {
            cin>>s1[i];

        }
        long int p2=0;
        // cout<<y<<endl;

        for(int i=0; i<n-1; i++)
        {
            if(s1[i]!=s1[i+1])
            {
                p2++;
                s2.push_back(s1[i]);
            }

        }
        s2.push_back(s1[n-1]);
        for(int i=0; i<x-1; i++)
        {
            if(a[i]!=a[i+1])
            {

                a1.push_back(a[i]);
            }

        }
        a1.push_back(a[x-1]);

        if(x<2000 || n<2000)
        {
            f(0,p2+1,0,x,n);
            // cout<<max1<<endl;
            cout<<max1<<endl;

            max1=1000000;
        }
        else
        {
            for(int i=0; i<a1.size(); i++)
            {

                for(int j=0; j<s2.size(); j++)
                {

                    // cout<<a1[i]<<endl;
                    if(a1[i]==s2[j])
                    {
                        y[i][j]=0;
                    }
                    else
                    {
                        y[i][j]=1;
                        // cout<<a1[i]<<" "<<s2[j]<<" "<<i<<" "<<j<<endl;
                    }
                    if(j==s2.size()-1)
                    {
                        y[i][j+1]=y[i][j];
                    }

                }

            }





            long int p=100000;
            for(int j=0; j<=s2.size(); j++)
            {
                u[0][j][0]=y[0][j];
                if(p>u[0][j][0])
                    p=u[0][j][0];
                u[0][j][1]=p;
            }
            for(int i=1; i<a1.size(); i++)
            {
                p=100000;
                for(int j=0; j<=s2.size(); j++)
                {
                    if(j>0)
                    {
                        if(u[i-1][j][0]==u[i-1][j][1] && u[i-1][j-1][1]!=u[i-1][j][1]&& y[i-1][j]==0)
                            u[i][j][0]=y[i][j]+u[i-1][j][1]+1;
                        else
                            u[i][j][0]=y[i][j]+u[i-1][j][1];
                    }
                    else
                    {
                        if(y[i-1][j]==0)
                            u[i][j][0]=y[i][j]+1+u[i-1][j][1];
                        else
                            u[i][j][0]=y[i][j]+u[i-1][j][1];
                    }

                    if(p>u[i][j][0])
                        p=u[i][j][0];
                    u[i][j][1]=p;
                }
            }

            cout<<u[a1.size()-1][s2.size()][1]+p2+1<<endl;
        }

    }





    return 0;
}