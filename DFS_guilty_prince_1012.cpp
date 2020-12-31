#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gap" "
#define n1 "\n"
#define white 0
#define black 1
#define red 2
#define MAX 30
#define sfi(a) scanf("%d",&a)
#define sfii(a,b) scanf("%d %d",&a,&b)
#define pfi(a) printf("%d",a)
#define pb push_back
int X[]={0,1,0,-1};
int Y[]={-1,0,1,0};
int color[MAX][MAX];
char graph[MAX][MAX];
int ans=0,m,n,x,y;
bool border(int x,int y)
{
    if((x>=0 && x<m) && (y>=0 && y<n))
        return true;
    else
        return false;
}
void DFS(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        if(border(x=X[i],y+Y[i] && color[x+X[i]][y+Y[i]] && graph[x+X[i]][y+Y[i]]=='.' ))
        {
            ans++;
            color[x+X[i]][y+Y[i]]=true;
            DFS(x+X[i],y+Y[i]);
        }
    }
}

int main()
{
    int t,tc=0;
    sfi(t);
    while(t--)
    {
        sfii(n,m);
        ans=0;
        memset(color,0,sizeof color);
        getchar();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                graph[i][j]=getchar();
                if(graph[i][j]=='@')
                {
                    x=i;
                    y=j;
                    ans++;
                    color[x][y]=true;

                }
            }
            getchar();

        }
        DFS(x,y);
        printf("Case %d: %d\n",++tc,ans);
    }
    return 0;
}
