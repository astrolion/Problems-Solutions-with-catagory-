#include "bits/stdc++.h"
using namespace std;
// Problem link :: https://codeforces.com/contest/1056/problem/E

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int SEED = 31;
long long POWER[N];
long long HASH[N];
long long INV[N];

char bin[N], s[N];

long long EXP( long long base, long long power ) {
        long long ret = 1LL;
        long long po = base;
        while(power) {
                if( power & 1LL  )
                        ret = (ret * po) % MOD;
                power /= 2LL;
                po = (po * po) % MOD;
        }
        return ret;
}



int main() {

        scanf("%s %s", bin, s);

        int zeros = 0, ones = 0;

        int binLen = strlen(bin);

        for(int i = 0; i < binLen; i++) {
                zeros += bin[i] == '0';
                ones += bin[i] == '1';
        }

        int n = strlen(s);

        POWER[0] = 1;
        for(int i = 1; i <= n; i++) {
                POWER[i] = ( POWER[i - 1] * SEED ) % MOD;
                INV[i] = EXP( POWER[i], MOD - 2 );
        }

        for(int i = 1; i <= n; i++)
                HASH[i] = ( HASH[i - 1] + ( s[i - 1] - 'a' + 1 ) * POWER[i]  ) % MOD;

        int ans = 0;

        for(int i = 1; i <= n; i++) {

                int seg_zero = -1, seg_one = -1;

                if( bin[0] == '0' ) {

                        int rem = n - ( zeros * i );
                        if(rem <= 0 || rem % ones != 0 ) continue;
                        seg_zero = i;
                        seg_one = rem / ones;
                } else {
                        int rem = n - ( ones * i );
                        if( rem <= 0 || rem % zeros != 0 ) continue;
                        seg_one = i;
                        seg_zero = rem / zeros;
                }

                //cout<<seg_one<<" "<<seg_zero<<endl;
                //assert( seg_one == -1 || seg_zero == -1 );

                long long HASH_ONE = -1LL, HASH_ZERO = -1LL;

                int st = 1;
                bool flag = true;

                for(int pos = 0; pos < binLen; pos++) {
                        int ed;
                        if( bin[pos] == '0' ) {
                                ed = st + seg_zero;
                                long long hs = ( HASH[ed - 1] - HASH[st - 1]  + MOD ) % MOD;
                                hs = ( hs * INV[ st ] ) % MOD;
                                if( HASH_ZERO == -1LL ) {
                                        HASH_ZERO = hs;
                                } else if( HASH_ZERO != hs ) {
                                        flag = false;
                                        break;
                                }
                                st = ed;

                        } else {
                                ed = st + seg_one;
                                long long hs = ( HASH[ed - 1] - HASH[st - 1] + MOD ) % MOD;
                                hs = ( hs * INV[st] ) % MOD;

                                if( HASH_ONE == -1LL ) HASH_ONE = hs;
                                else if( HASH_ONE != hs ) {
                                        flag = false; break;
                                }
                                st = ed;
                        }

                        if(!flag) break;
                }

                if(flag && HASH_ONE != HASH_ZERO ) ans++;

        }

        printf("%d\n", ans);
        return 0;
}
