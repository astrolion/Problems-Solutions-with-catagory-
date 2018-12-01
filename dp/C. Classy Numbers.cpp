/***
Problem link :: https://codeforces.com/problemset/problem/1036/C
Used approach :: digit dynamic programming

***/

#include "bits/stdc++.h"
using namespace std;



int main() {
        int t; scanf("%d", &t);

        while(t--) {
                long long L, R; scanf("%lld %lld", &L, &R);
                L--;

                long long dp[20][12][2][10];
                string s;

                function< long long ( int, int, int, int   ) > solve = [&] ( int i, int d, int flag, int cnt ) {
                        if( cnt > 3 ) return 0LL;
                        if( i >= s.size() ) return 1LL * (cnt <= 3);

                        long long &ret = dp[i][d][flag][cnt];
                        if( ret != -1LL ) return ret;

                        int lim = flag  ? s[i] - '0' : 9;
                        ret = 0LL;
                        for(int digit = 0; digit <= lim; digit++) {
                                if(digit == lim) {
                                        ret += solve(i + 1, digit, flag, cnt + ( digit != 0 ));
                                } else ret += solve( i + 1, digit, 0, cnt + ( digit != 0 ) );
                        }
                        return ret;
                };

                memset( dp, -1LL, sizeof dp );
                s = to_string(R);

                long long tot = solve(0, 0, 1, 0);
                memset( dp, -1LL, sizeof dp );
                s = to_string(L);
                long long sub = solve( 0, 0, 1, 0 );


                printf("%lld\n", tot - sub );




        }



        return 0;
}
