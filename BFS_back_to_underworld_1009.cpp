#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gap" "
#define n1 "\n"
#define white 0
#define black 1
#define red 2
#define MAX 20010
#define sfi(a) scanf("%d",&a)
#define sfii(a,b) scanf("%d %d",&a,&b)
#define pfi(a) printf("%d",a)
#define pb push_back
 vector<int>graph[MAX];
 int lyk=0,vam=0;
 int color[MAX];
 void clr()
 {
     for(int i=0;i<MAX;i++)
        graph[i].clear();
 }
 void bfs(int sn)
 {
     queue<int>q;
     q.push(sn);
     color[sn]=black;
     vam++;
     while(!q.empty())
     {
         int x=q.front();
         q.pop();
         for(int i=0;i<graph[x].size();i++)
         {
             int xx=graph[x][i];
             if(color[xx]==white)
             {
                 q.push(xx);
                 if(color[x]==black)
                 {
                     color[xx]=red;
                     lyk++;
                 }
                 else
                 {
                     color[xx]=black;
                     vam++;
                 }
             }
         }
     }
 }

 int main()
 {
     int t,tc=0;
     sfi(t);
     while(t--)
     {
         int n,u,v,ans=0;
         sfi(n);
         for(int i=0;i<n;i++)
         {
             sfii(u,v);
             graph[u].pb(v);
             graph[v].pb(u);
         }
         memset(color,0,sizeof color);
         for(int i=0;i<MAX;i++)
         {
             vam=0,lyk=0;
             if(color[i]==white && graph[i].size()>0)
             {
                 bfs(i);
             }
             ans+=max(vam,lyk);
         }
         printf("Case %d: %d\n",++tc,ans);
     }
 }
