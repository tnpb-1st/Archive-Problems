#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// typedef __int128_t bgl;
// range of int valu'es -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
	int n,m, x, k, v;
	while(cin >> n){
		cin >> m;
		map<int, vi>G;
		for(int i = 0; i < n; i++){
			cin >> x;
			G[x].pb(i + 1);
		}
		while(m--){
			cin >> k >> v;
			if(k <= G[v].size())
				cout << G[v][k-1]<<endl;
			else
				cout<<0<<endl;
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
