#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int q=0,n,m;
    char a[101][101],b[101][101],c[101][101];
    cin>>q;
    for(int k=0; k<q; k++)
    {
        cin>>n>>m;
        int s=0,s1=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {

                cin>>c[i][j];
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i%2==0 && j%2==0)
                    a[i][j]='R';
                if(i%2==0 && j%2==1)
                    a[i][j]='G';
                if(i%2==1 && j%2==0)
                    a[i][j]='G';
                if(i%2==1 && j%2==1)
                    a[i][j]='R';

            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i%2==0 && j%2==0)
                    b[i][j]='G';
                if(i%2==0 && j%2==1)
                    b[i][j]='R';
                if(i%2==1 && j%2==0)
                    b[i][j]='R';
                if(i%2==1 && j%2==1)
                    b[i][j]='G';

            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(c[i][j]=='G'&& a[i][j]=='R')
                    s+=3;
                if(c[i][j]=='R'&& a[i][j]=='G')
                    s+=5;


            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(c[i][j]=='G'&& b[i][j]=='R')
                    s1+=3;
                if(c[i][j]=='R'&& b[i][j]=='G')
                    s1+=5;

            }
        }
        //  cout<<s<<s1<<a[0][0]<<b[0][0];
        if(s<s1)
            cout<<s<<endl;
        else
            cout<<s1<<endl;

    }
}