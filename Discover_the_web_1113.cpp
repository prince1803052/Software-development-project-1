#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,max;
    cin>>t;
   for(int j=1;j<=t;j++)
    {
        string webpage[100],keyword;
       webpage[0]="http://www.lightoj.com/";
       i=0;
       max=0;
       cout<<"Case"<<" "<<j<<":"<<endl;
       label1:
       cin>>keyword;
       if(keyword=="VISIT")
       {
           i=i+1;
           max=i;
           cin>>webpage[max];
           cout<<webpage[max]<<endl;
           goto label1;

       }
       else if(keyword=="BACK")
       {
           if(i<1)
           {
               cout<<"Ignored"<<endl;
               goto label1;

           }

           else
            {cout<<webpage[--i]<<endl;
           goto label1;
            }
       }
       else if(keyword=="FORWARD")
       {
           if(max-1<i)
           {
               cout<<"Ignored"<<endl;
               goto label1;
           }
           else
           {cout<<webpage[++i]<<endl;
           goto label1;}
        }
        else if(keyword=="QUIT")
        {
            continue;
        }
          }
          return 0;

}
