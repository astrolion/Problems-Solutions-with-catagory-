#include "bits/stdc++.h"
using namespace std;


int main() {
        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                int n; scanf("%d", &n);

                vector< pair<int, int > > v, dp;

                for(int i = 0; i < n; i++) {

                        int x, y; scanf("%d %d", &x, &y);
                        v.push_back( make_pair(x, y) );
                }


                for(int i = 0; i < n; i++) {
                        for(int j = i + 1; j < n; j++) {
                                dp.push_back( make_pair( v[i].first + v[j].first, v[i].second + v[j].second ) );
                        }
                }
                long long ans = 0LL;
                int cnt = 0;
                sort( dp.begin(), dp.end() );

                for(int i = 0; i < dp.size(); i++) {
                        if(i == 0) {
                                cnt++; continue;
                        }
                        if( dp[i].first == dp[i - 1].first && dp[i].second == dp[i - 1].second ) {
                                cnt++;
                        } else {
                                ans += ( cnt * (cnt - 1) ) / 2;
                                cnt = 1;
                        }

                }

                if(cnt)
                ans += ( cnt * (cnt - 1) ) / 2;







                printf("Case %d: %lld\n", tc, ans);

        }


        return 0;
}
