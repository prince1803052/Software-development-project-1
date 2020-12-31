#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const int MAX=110;
int n;
int f[110];
double a[110][110];
int gauss(int n,int m){
    int col,i,mxr,j,row;
    for(row=col=1;row<=n&&col<=m;row++,col++){
        mxr = row;
        for(i=row+1;i<=n;i++)
            if(fabs(a[i][col])>fabs(a[mxr][col]))
                mxr = i;
        if(mxr != row) swap(a[row],a[mxr]);
        if(fabs(a[row][col]) < eps){
            row--;
            continue;
        }
        for(i=1;i<=n;i++)
            if(i!=row&&fabs(a[i][col])>eps)
                for(j=m;j>=col;j--)
                    a[i][j]-=a[row][j]/a[row][col]*a[i][col];
    }
    row--;
    for(int i = row;i>=1;i--){///Return into a diagonal matrix
        for(int j = i + 1;j <= row;j++){
			a[i][m] -= a[j][m] * a[i][j];
        }
    	a[i][m] /= a[i][i];
    }
    return row;
}
int main(){
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		memset(f,-1,sizeof(f));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1,a,b;i<=n;i++){
			cin>>a>>b;
			f[a]=b;
		}
		a[100][100]=1;
		a[100][101]=0;
		for(int i=1;i<100;i++){
			if(~f[i]){
				a[i][101]=0;
				a[i][i]=1;
				a[i][f[i]]=-1;
			}else{
				int cnt=min(6,100-i);
				a[i][i]=cnt;
				for(int j=1;j<=cnt;j++){
					a[i][i+j]=-1;
				}
				a[i][101]=6;
			}
		}
		int row=gauss(100,101);
		printf("Case %d: %.6f\n",cas,a[1][101]);
	}
	return 0;
}
