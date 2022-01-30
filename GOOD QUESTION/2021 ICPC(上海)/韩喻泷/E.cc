#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e9 + 5;

int n, k;
int a[N];

class seg {
public:
    int l, r; // possibly negative
    seg() {}
    seg(int _l , int _r) {
        l = _l;
        r = _r;
    }
    bool operator < (seg &o) const {
        return r == o.r ? l < o.l : r < o.r;
    }
} b[N];

int main() {
    // freopen("E.in", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = seg(a[i] - k, a[i] + k);
    }
    // sort(b + 1, b + n + 1);
    sort(a + 1, a + n + 1);
    int lst = -(1e9 + 5);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] >= lst + k) {
            // printf("[%d]\n", a[i]);
            ans++;
            lst = a[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}