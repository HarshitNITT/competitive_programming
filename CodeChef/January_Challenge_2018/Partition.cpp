#include <bits/stdc++.h>
using namespace std;
char s1[1000020];
long int xc=0;
void f(long int index,long int x,long int s,long int j)
{
    // cout<<s<<endl;
    if(s==j)
    {
        xc=1;
        return ;
    }
    if(index<1)
        return;
    if(index==x)
    {
        f(index-1,x,s,j);
    }
    else if (index+s<=j)
    {
        s1[index]='1';
        f(index-1,x,s+index,j);
        if(xc==0)
        {
            s1[index]='0';
            f(index-1,x,s,j);
        }
    }
    else
    {
        f(index-1,x,s,j);
    }


}

using namespace std;
int main() {

    long  int x1;
    long  int n,x;



    cin>>x1;

    long int max=0;

    for(long int y2=0; y2<x1; y2++)
    {

        cin>>x>>n;

        long int y=((n*(n+1))/2)-x;
        // cout<<y<<endl;
        if(y%2==1 || n==1 || n==2 || n==3)
            cout<<"impossible";
        else
        {
            long int u=y/2;
            long int j=0;
            for(long int  i=n; i>0; i--)
            {
                s1[i]='0';
            }
            s1[x]='2';
            f(n,x,j,u);
            for(int i=1; i<=n; i++)
                cout<<s1[i];
        }


        xc=0;

        cout<<endl;
    }





    return 0;
}

