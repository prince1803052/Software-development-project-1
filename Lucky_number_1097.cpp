#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1429431+100;
int sum[MAX_N<<2],T;

void build(int idx,int l,int r){
    if( l==r ){
        if(l&1) sum[idx] = 1;
        else sum[idx] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(idx<<1,l,m);
    build(idx<<1|1,m+1,r);
    sum[idx] = sum[idx<<1]+sum[idx<<1|1];
}

int query(int x,int idx,int l,int r){
    if( l==r ) return l;
    int m = (l+r)>>1;
    if(sum[idx<<1]>=x) return query(x,idx<<1,l,m);
    else return query(x-sum[idx<<1],idx<<1|1,m+1,r);
}

int update(int pos,int x,int idx,int l,int r){
    if( l==r ) {
        sum[idx] = x;
        return l;
    }
    int m = (l+r)>>1;
    int res = 0;
    if( sum[idx<<1]>=pos ) res = update(pos,x,idx<<1,l,m);
    else res = update(pos-sum[idx<<1],x,idx<<1|1,m+1,r);
    sum[idx] = sum[idx<<1] + sum[idx<<1|1];
    return res;
}

int main(){
    build(1,1,MAX_N);
    int now = 2;
    while( sum[1]>=now ){
        int t = query(now,1,1,MAX_N);
        int nowt = t;
        bool flag = false;
        while(sum[1]>=nowt){
            flag = true;
            int res = update(nowt,0,1,1,MAX_N);
            nowt+=t-1;
        }
        if(!flag) break;
        now++;
    }

    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int num;
        scanf("%d",&num);
        int ans = query(num,1,1,MAX_N);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
