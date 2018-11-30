#include "bits/stdc++.h"
using namespace std;

// problem :: https://codeforces.com/contest/245/problem/H

const int N = 5005;
char ss[N];
const int mod = 1e9 + 7;
const int seed = 31;

long long bin_pow( long long base, long long power ) {
        long long ret = 1LL;
        long long p = base;

        while( power ) {
                if( power & 1LL ) ret = (ret * p) % mod;
                power /= 2LL;
                p = (p * p) % mod;
        }

        return ret;
}

int dp[N][N];

int main() {
        scanf("%s", ss);
        int n = strlen(ss);

        vector< long long > HL(n + 1), HR(n + 1), PO(n + 1), INV(n + 1) ;

        PO[0] = 1LL;
        for(int i = 1; i <= n; i++) {
                PO[i] = ( PO[i - 1] * seed ) % mod;
                INV[i] = bin_pow( PO[i], mod - 2 );
        }

        HL[0] = HR[0] = 0LL;

        for(int i = 1; i <= n; i++) {
                HL[i] = ( HL[i - 1] + ( ss[i - 1] - 'a' + 1 ) * PO[i] ) % mod;
                HR[i] = ( HR[i - 1] + ( ss[n - i] - 'a' + 1 ) * PO[i] ) % mod;
        }




        for(int i = 1; i <= n; i++) {
                //string sss  = "";
                for(int j = i; j <= n; j++) {
                        long long L = ( HL[j] - HL[i - 1] + mod ) % mod;
                        L = ( L * INV[i] ) % mod;

                        int ii = n - j + 1;
                        int jj = n - i + 1;

                        long long R = ( HR[jj] - HR[ii - 1] + mod ) % mod;
                        R = ( R * INV[ii] ) % mod;

                        if( L == R ) {
                                dp[i][j]++;


                        }


                }
        }

        for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                        dp[i][j] += dp[i][j - 1];
                }
        }

        for(int j = 1; j <= n; j++) {
                for(int i = 1; i <= n; i++) {
                        dp[i][j] += dp[i - 1][j];
                }
        }

        int q; scanf("%d", &q);

        while(q--) {
                int x, y; scanf("%d %d", &x, &y);

                printf("%d\n", dp[y][y] - dp[x - 1][y] );



        }











        return 0;
}
