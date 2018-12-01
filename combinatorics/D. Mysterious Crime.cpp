/**
Problem :: D. Mysterious Crime
Problem Link :: https://codeforces.com/problemset/problem/1043/D
**/


#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int a[11][N];
int nxt[11][N];
int n, m;

bool check( int L, int R ) {
        for(int i = 1; i <= m; i++) {
                if( nxt[i][L] != R ) return false;
        }
        return true;
}


int main() {

        scanf("%d %d", &n, &m);

        for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++)
                        scanf("%d", a[i] + j);
        }

        for(int i = 1; i <= m; i++) {
                for(int j = 1; j < n; j++) {
                        nxt[i][ a[i][j] ] = a[i][j + 1];
                }
                nxt[i][ a[i][n] ] = -1;
        }

        long long ans = 1LL * n;

        int cnt = 1;

        for(int i = 1; i < n; i++) {
                if( check(a[1][i], a[1][i + 1]) ) {
                        cnt++;
                } else {
                        ans += ( 1LL * cnt * (cnt - 1) ) / 2LL;

                        cnt = 1;
                }
        }

        if( cnt ) {
                ans += ( 1LL * cnt * (cnt - 1) ) / 2LL;
        }

        printf("%lld\n", ans);





        return 0;
}

