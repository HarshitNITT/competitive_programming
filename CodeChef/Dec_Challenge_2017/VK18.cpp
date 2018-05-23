#include<bits/stdc++.h>
using namespace std;
long long  int  odd[2000011],even[2000011],s[2000011],a[2000011],as[2000011];
long int dp(long int n)
{
    //  cout<<n<<endl;
    if(n==1)
    {
        s[n]=2;
        a[n]=2;
        return 2;
    }
    else if(s[n]!=0)
        return s[n];
    s[n]=dp(n-1);
    int g=(n+1)/10;
    int k=(2*n-1)/10;
    if(n==2)
    {
        for(int i=n+1; i<=2*n-1; i++)
        {
            if(odd[i]>even[i])
                a[n]=a[n]+2*(odd[i]-even[i]);

            else
                a[n]=a[n]-2*(odd[i]-even[i]);
        }
        if(odd[2*n]>even[2*n])
            a[n]=a[n]+(odd[2*n]-even[2*n]);

        else
            a[n]=a[n]-(odd[2*n]-even[2*n]);
    }
    else
    {

        if(even[n]>odd[n])
            a[n]=a[n-1]-2*(even[n]-odd[n]);
        if(even[n]<=odd[n])
            a[n]=a[n-1]-2*(odd[n]-even[n]);

        if(even[2*n-1]>odd[2*n-1])
            a[n]=a[n]+2*(even[2*n-1]-odd[2*n-1]);
        if(even[2*n-1]<=odd[2*n-1])
            a[n]=a[n]+2*(odd[2*n-1]-even[2*n-1]);
        if(even[2*n]>odd[2*n])
            a[n]=a[n]+(even[2*n]-odd[2*n]);
        if(even[2*n]<=odd[2*n])
            a[n]=a[n]+(odd[2*n]-even[2*n]);
        if(even[2*(n-1)]<=odd[2*(n-1)])
            a[n]=a[n]+(odd[2*(n-1)]-even[2*(n-1)]);
        if(even[2*(n-1)]>odd[2*(n-1)])
            a[n]=a[n]+(even[2*(n-1)]-odd[2*(n-1)]);
    }
    // cout<<n<<a[n]<<endl;
    s[n]=s[n]+a[n];
    return s[n];

}
int main()
{
    long long int q=0,n,m,e=0,max=0;
    long long int max1=0;
    for(int j=0; j<1000002; j++)

    {

        s[j]=0;
    }
    for(int j=0; j<2000001; j++)

    {

        as[j]=0;
    }
    for(int j=1; j<10; j++)
    {
        if(j%2==0)
        {
            even[j]=j;
            odd[j]=0;
        }
        else
        {
            odd[j]=j;
            even[j]=0;

        }
    }
    cin>>q;
    for(long long  int k=0; k<q; k++)
    {
        cin>>n;
        long long int s1=0;
        long int y=0;
        long long int j;
        //cout<<max;
        for( j=max1;; j++)
        {
            if(j>=2*n)
                break;
            //   cout<<j;
            for(long long int k=0; k<10; k++)
            {

                if(k%2==0)
                {
                    even[j*10+k]=even[j]+k;
                    odd[j*10+k]=odd[j];

                }
                else
                {
                    odd[j*10+k]=odd[j]+k;
                    even[j*10+k]=even[j];

                }
                if(j*10+k>=2*n)
                {
                    y=1;
                    break;

                }
            }
            if(y==1)
                break;
            if(j>=2*n)
                break;

            //  cout<<"wer";
        }
        //cout<<j<<endl;
        max1=j;
        int t=0;
        //     cout<<n;



        cout<<dp(n)<<endl;
        //   cout<<max<<endl;

    }
    return 0;
}