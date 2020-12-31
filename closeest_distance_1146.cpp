#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
#define point pair<double, double>
point a,b,c,d;

double distance(point x,point y)
{
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
void minimum(int p)
{
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    cin>>d.first>>d.second;

    double ac=distance(a,c);
    double bd=distance(b,d);

    while(abs(ac-bd)>eps){

            point a1,b1,c1,d1;
    a1.first=a.first+(b.first-a.first)/3;
    a1.second=a.second+(b.second-a.second)/3;

       b1.first=b.first-(b.first-a.first)/3;
    b1.second=b.second-(b.second-a.second)/3;

         c1.first=c.first+(d.first-c.first)/3;
    c1.second=c.second+(d.second-c.second)/3;

       d1.first=d.first-(d.first-c.first)/3;
    d1.second=d.second-(d.second-c.second)/3;

    ac=distance(a1,c1);
    bd=distance(b1,d1);

    if(ac>bd)
      a=a1,c=c1;
      else
        b=b1,d=d1;



    }

   printf("Case %d: %0.8F\n",p,(ac+bd)/2.0);

}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        minimum(i);
    }
    return 0;
}
