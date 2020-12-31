#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double radius,area;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>radius;
        area=((2*radius)*(2*radius)-((2 * acos (0.0))*radius*radius));

        printf("Case %d: %.2lf\n",i, area);
    }


}
