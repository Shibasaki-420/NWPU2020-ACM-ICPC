#include <iostream>
#include <cstdio>
#include <vector>
#include <fstream>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MOD = 998244353;

int n;

//图
vector<int> vec[MAXN];

//访问
bool vis[MAXN];

//可用的孩子个数
int able[MAXN];

// 半阶乘
ll bjc(int k){
	ll ans = 1;
	while(k > 1){
		ans *= k;
		ans %= MOD;
		k -= 2;
	}
	return ans;
}

// 
ll dfs(int u){

	vis[u] = true;

	ll ans = 1;
	int size = vec[u].size();

	if(u == 1)
		able[u] = size;
	else
		able[u] = size - 1;
	// cout << "able[" << u << "]> " << able[u] << endl;

	if(size > 1 || u == 1){

		for(int i = 0 ; i < size ; i ++){

			int v = vec[u][i];

			if(vis[v] == false){
				
				ll bf = dfs(v);
				// cout << u << "->" << v << "> " << bf << endl;

				ans *= bf;
				ans %= MOD;

				if(able[v] % 2 == 1){
					able[u] --;
					// cout << "reduse> " << u << "->" << v << " because able: " << able[v] << endl;
					// cout << "after reduce> " << able[u] << endl;
				}
			}
		}

		if(able[u] > 1){
			ll bf = (able[u] % 2 == 0 ? bjc(able[u] - 1) : bjc(able[u]));
			// cout << "cal> " << u << " " << bf << endl;

			ans *= bf;
			ans %= MOD;
		}
	}
	
	return ans;
}

int main(){

	// freopen("G.in", "r", stdin);

    scanf("%d", &n);
    for(int i = 0 ; i < n - 1 ; i ++){
        int u, v;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

	printf("%lld", dfs(1));
	return 0;
}