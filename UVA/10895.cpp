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
	int m,n;
	// int A[m][n], int T[n][m];
	while(cin >> m)
	{
		cin >> n;
		vector<pii> V[n+1];
		for(int r = 1; r <= m; r++)
		{
			int ne, x;
			queue<int> Q;
			cin >> ne;
			if(ne == 0){
				continue;
			}
			else{
				for(int j = 0; j < ne; j++){
					cin >> x;
					Q.push(x);
				}
				while(Q.size()){
					cin >> x;
					V[Q.front()].pb(make_pair(r, x));
					Q.pop();
				}
			}
		}
		pii empt = {0,0};
		cout << n<<' '<< m<<endl;
		for(int i = 1; i <= n; i++)
		{
			string l1="", l2="";
			if(V[i].empty()){
				cout<<0<<endl<<endl;
			} else { 
				l1 += to_string(V[i].size()) + ' ';
				for(auto &pair : V[i]){
					l1 += to_string(pair.first);
					l2 += to_string(pair.second);
					if(pair != V[i].back()){
						l1+= ' ';
						l2+= ' ';
					}
					else {
						l1 += '\n';
						l2 += '\n';
					}
				}
				cout << l1 << l2;
			}
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
