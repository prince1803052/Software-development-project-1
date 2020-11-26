#include<bits/stdc++.h>

using namespace std;

int  n, r[100020];

int check(int k) {
    int f = 0;
    for(int i = 0; i < n; i++) {
        if(r[i] - f < k) {
            f += r[i] - f;
        } else if(r[i] - f == k) {
            f += k;
            k--;
        } else return -1;
    }
    return k;
}

int main() {
    int T;
    cin>>T;
    for(int i = 1; i <= T; i++) {
        cin>>n;
        for(int j = 0; j < n; j++)
            cin>>r[j];

        int P = 10000020, L = 0;
        while(P - L > 0) {
            if(check(P) >= 0) {
                P = L + (P - L) / 2;
            } else {
                L = P;
                P = P + P / 2;
            }
        }

        cout<<"Case "<<i<<":"<<"\t"<<P+1<<endl;
    }

    return 0;
}
