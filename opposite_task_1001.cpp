#include <bits/stdc++.h>
using namespace std;
int main()
{
    long t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        if(a<=10)
        cout<<"0"<<" "<<a<<endl;
        else
            cout<<a-10<<" "<<"10"<<endl;
    }
}

