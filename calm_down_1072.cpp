#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    int t,n;
    double R;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>R>>n;
        double r=(R*sin(M_PI/n))/(1+sin(M_PI/n));
        cout<<setprecision(10)<<"Case"<<" "<<i<<":"<<" "<<r<<endl;
    }
    return 0;
}
