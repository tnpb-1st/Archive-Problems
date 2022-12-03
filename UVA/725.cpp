#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;
const int arrLim = 1e6;
int dp[100001];
/*
SOLUTION BY tnpb
*/

void solve()
{
	int N;
	bool present = false;
	while(cin >> N && N) {
		if(present)cout<<endl;
		bool found_pairs = false;
		for(int num = 1234; num <= 98765/N; num++) {
			int den = num * N;
			int tmp, used = (num < 10000);
			const int zero_front = used;
			tmp = num; while(tmp) {used |= 1<<(tmp%10); tmp/=10;}
			tmp = den; while(tmp) {used |= 1<<(tmp%10); tmp/=10;}
			if(used == (1<<10)-1) {
				found_pairs = true;
				string tmp_num = (zero_front) ? '0' + to_string(num) : to_string(num);
				cout << to_string(den) + " / " + tmp_num + " = " + to_string(N)+"\n";
			}
		}
		if(!found_pairs) cout << "There are no solutions for " << N << ".\n";
		present = true;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
