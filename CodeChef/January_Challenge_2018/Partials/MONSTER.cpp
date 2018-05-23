#include <bits/stdc++.h>
using namespace std;
long int  a[1000020];

int main() {

    long  int x1;
    long  int n,x,q,y;

    vector<int>c;
    vector<int>d;

    cin>>x1;

    long int o=0;
    for(int i=0; i<x1; i++)
    {
        cin>>a[i];
        if(a[i]==1)
            o++;

    }
    cin>>q;
    for(int i=0; i<x1; i++)
    {

        c.push_back(i);
    }
    for(long int y2=0; y2<q; y2++)
    {

        cin>>x>>y;
        long int p=0;
        if(o==x1 && y==1)
        {
            for(int i=0; i<c.size(); i++) {
                if((c[i]&x)==c[i])
                {}
                else
                {
                    d.push_back(c[i]);
                }

            }
            c.clear();
            cout<<d.size()<<endl;
            c=d;
            d.clear();
        }
        else
        {
            long int p=0,i=0;
            for( i=0; i<c.size(); i++)
            {
                if(c[i]<=x)
                {
                    if((c[i]&x)==c[i])
                    {

                        a[c[i]]-=y;
                        //cout<<c[i]<<endl;
                        if(a[c[i]]<=0)
                        {}
                        else
                            d.push_back(c[i]);
                    }
                    else
                        d.push_back(c[i]);
                }
                else
                {
                    break;
                }
            }
            c.erase(c.begin(),c.begin()+i);
            // cout<<i<<endl;cout<<c.size();
            d.insert(d.end(), c.begin(), c.end());
            c.clear();
            cout<<d.size()<<endl;
            c=d;

            d.clear();

        }
        // cout<<endl;






    }





    return 0;
}