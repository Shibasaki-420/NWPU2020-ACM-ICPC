#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;


typedef long long ll;

const int N = 100;
const int K = 5300;

int n;
int m;

int v[N];
int t[N];
int dp[N + 2][N + 2][K];


int main(){

	scanf("%d%d", &n, &m);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d%d", &v[i], &t[i]);
	}

	for(int i = 0 ; i < N ; i ++){
		for(int j = 0 ; j <= N ; j ++){
			for(int k = 0 ; k < K ; k ++){
				if(i == 0)
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
				

			}
		}
	}
}