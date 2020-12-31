#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int t,b,b1,p,r,i;
    cin>>t;
    for( i=0;i<t;i++)
    {
        cin>>a>>b;
        r=0;
        if(b<0)
        {
            b1=b*(-1);
        }
        else
        {
            b1=b;
        }
        for(int j=0;j<a.length();j++)
        {
            if(a[j]!='-')
            {
                r=((r*10)+(a[j]-'0'))%b1;
            }
        }
        if(r==0)
        {
            cout<<"case"<< i<<": divisible"<<endl;
        }
        else
        {
            cout<<"case"<< i<<": not divisible"<<endl;
        }
    }
}
