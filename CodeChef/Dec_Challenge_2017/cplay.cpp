#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int q=0,n,m,e=0,max=1;
    long long  int  a[2000002];

    char s[20];
    int i1=0;
    while(scanf("%s",s)!=EOF)
    {
        int a=0,b=0;


        int o=0;
        for(int i=0; i<10; i++)
        {
            // cout<<a<<b<<i%2<<s[i]<<endl;
            int b1=(9-i)/2;

            if(s[i]=='1' && i%2==0)
            {
                //cout<<"lo[]";
                a++;


            }
            if(s[i]=='1' && i%2==1)
                b++;
            if(i%2==0)
            {
                if(a-b>b1+1)
                {
                    cout<<"TEAM-A "<<i+1<<endl;
                    o=1;
                    break;


                }
                //  cout<<b-a<<b<<a<<b1<<i<<" wat"<<endl;
                if(b-a>b1)
                {
                    cout<<"TEAM-B "<<i+1<<endl;
                    o=1;
                    break;
                }
            }
            if(i%2==1)
            {
                if(b-a>b1)
                {
                    cout<<"TEAM-B "<<i+1<<endl;
                    o=1;
                    break;
                }
                if(a-b >b1)
                {
                    cout<<"TEAM-A "<<i+1<<endl;
                    o=1;
                    break;

                }
            }
        }

        if(o==0)
        {
            for(int i=10; i<20; i+=2)
            {
                if(s[i]=='1' && s[i+1]=='0')
                {
                    o=1;
                    cout<<"TEAM-A "<<i+2<<endl;
                    break;
                }
                if(s[i]=='0' && s[i+1]=='1')
                {
                    o=1;
                    cout<<"TEAM-B "<<i+2<<endl;
                    break;
                }
            }
            if(o==0)
                cout<<"TIE"<<endl;
        }
    }




    return 0;
}