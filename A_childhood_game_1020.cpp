#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       long long int n;
        string name;
        cin>>n>>name;
        n=n%3;
        if(name=="Alice")
        {
            if(n==1)
                cout<<"Case"<<" "<<i<<":"<<" "<<"Bob"<<endl;
            else
                   cout<<"Case"<<" "<<i<<":"<<" "<<"Alice"<<endl;
        }
        else if(name=="Bob")
        {
            if(n==1)
                   cout<<"Case"<<" "<<i<<":"<<" "<<"Bob"<<endl;
            else
                   cout<<"Case"<<" "<<i<<":"<<" "<<"Alice"<<endl;

        }
    }
    return 0;

}
