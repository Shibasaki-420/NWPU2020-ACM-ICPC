#include <bits/stdc++.h>
using namespace std;

const int N = 130;

class tag{
public:
    int c4, c5, a2;
    tag() {}
    tag(int _c4, int _c5, int _a2) {
        c4 = _c4;
        c5 = _c5;
        a2 = _a2;
    }
} a[N];

int main() {
    int n;
    scanf("%d", &n);
    if(n == 3) {
        puts("Unlucky");
        return 0;
    }
    if(n == 2) {
        puts("10");
        return 0;
    }
    string ans = "";
    for(int i = 1; i * 4 < N; i++) {
        a[i * 4] = tag(i, 0, 0);
        if(i * 4 + 2 < N) {
            a[i * 4 + 2] = tag(i, 0, 1);
        }
    }
    for(int i = 1; i * 5 < N; i++) {
        a[i * 5] = tag(0, i, 0);
        if(i * 5 + 2 < N) {
            a[i * 5 + 2] = tag(0, i, 1);
        }
    }
    for(int i = 1; i * 4 < N; i++) {
        for(int j = 1; i * 4 + j * 5 < N; j++) {
            a[i * 4 + j * 5] = tag(i, j, 0);
            if(i * 4 + j * 5 + 2 < N) {
                a[i * 4 + j * 5 + 2] = tag(i, j, 1);
            }
        }
    }
    tag &x = a[n];
    for(int i = 1; i <= x.c4; i++) {
        ans += "1001";
    }
    for(int i = 1; i <= x.c5; i++) {
        ans += "10001";
    }
    if(x.a2) {
        ans += "10";
    }
    cout << ans << endl;
    return 0;
}