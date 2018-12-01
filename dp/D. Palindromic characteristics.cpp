#include "bits/stdc++.h"
using namespace std;
const int N = 5005;

// Problem link :: https://codeforces.com/problemset/problem/835/D

char s[N];
int dp[N][N];

int main() {


        scanf("%s", s);

        int n = strlen(s);

        for(int i = 0; i < n; i++) {

                for(int st = 0;; st++) {
                        int ed = st + i;
                        if(ed >= n) break;

                        if(i == 0) {
                                dp[st][ed] = 1;
                                continue;
                        }
                        if( i == 1 ) {
                                dp[st][ed] = ( s[st] == s[ed] ? 2 : 0 );
                                continue;
                        }

                        if( s[st] != s[ed] || dp[st + 1][ed - 1] == 0 ) {
                                dp[st][ed] = 0;
                                continue;
                        }
                        dp[st][ed] = 1;

                        int mid = (st + ed) >> 1;

                        if(i & 1) {
                                if( dp[st][mid] && dp[mid + 1][ed] ) {
                                        dp[st][ed] = dp[st][mid] + 1;
                                }
                        } else {
                                if( dp[st][mid - 1] && dp[mid + 1][ed] ) {
                                        dp[st][ed] = dp[st][mid - 1] + 1;
                                }
                        }
                }
        }

        vector< long long > ans(n + 1, 0);
        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                        ans[ dp[i][j] ]++;
                }
        }

        for(int i = n - 1; i >= 1; i--) ans[i] += ans[i + 1];

        for(int i = 1; i <= n; i++) {
                printf("%d ", ans[i]);
        }





        return 0;
}
