#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx];
int tree[mx*3];
void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    int p1=query(Left,b,mid,i,j);
    int p2=query(Right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e||i<b) return;
    if(b>=i&&e<=i)
    {
        tree[node]=newvalue;
        return;
    }
    int Left=node*2;
    int Right=node*2+1;
    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);
    tree[node]=tree[Left]+tree[Right];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int a=1;a<=t;a++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int b=0;b<n;b++)
            scanf("%d",&arr[b]);
        init(1,0,n-1);
        printf("Case %d:\n",a);
        for(int b=0;b<q;b++)
        {
            int num;
            scanf("%d",&num);
            if(num==1)
            {
                int i;
                scanf("%d",&i);
                printf("%d\n",arr[i]);
                arr[i]=0;
                update(1,0,n-1,i,0);
            }
            if(num==2)
            {
                int i,v;
                scanf("%d%d",&i,&v);
                arr[i]=arr[i]+v;
                update(1,0,n-1,i,arr[i]);
            }
            if(num==3)
            {
                int i,j;
                scanf("%d%d",&i,&j);
                printf("%d\n",query(1,0,n-1,i,j));
            }
        }
    }
    return 0;
}
