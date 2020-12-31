#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,count=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
       int j=0;
       for(int j=0;j<n;j++)
        {
            if(a[j]-a[j-1]>=n)
            {
                int l=a[j]-a[j-1];
                a[j]=l-n;
                n--;
                count++;
                j--;

            }
            else if(a[i]-a[i-1]<n)
            {
             count++;
            }
        }

        cout<<count<<endl;

    }
    return 0;
}
