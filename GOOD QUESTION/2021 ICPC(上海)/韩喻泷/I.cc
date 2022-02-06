#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int v[105], w[105];
ll dp[2][6000][105], op;

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &w[i], &v[i]);
    }
    op = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 6000; j++) {
            for(int q = 0; q <= k; q++) {

                dp[op][j][q] = dp[op^1][j][q];

                if(j >= v[i])
                    dp[op][j][q] = max(dp[op][j][q], dp[op^1][j - v[i]][q] + w[i]);

                if(j + v[i] < 6000)
                    dp[op][j][q] = max(dp[op][j][q], dp[op^1][j + v[i]][q] + w[i]);

                if(j >= 2 * v[i] && q >= 1)
                    dp[op][j][q] = max(dp[op][j][q], dp[op^1][j - 2 * v[i]][q - 1] + w[i]);

                if(j + 2 * v[i] < 6000 && q >= 1)
                    dp[op][j][q] = max(dp[op][j][q], dp[op^1][j + 2 * v[i]][q - 1] + w[i]);
            }
        }
        op ^= 1;
    }
    op ^= 1;
    ll ans = -1;
    for(int q = 0; q <= k; q++) {
        ans = max(ans, dp[op][0][q]);
    }
    printf("%d\n", ans);
    return 0;
}