#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 0xfffffff
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
vector<ll> A;

ll calculateCowsForDist(int &c) {
	int d = c, l = 1, r = A.size() - 1;
	ll cow = 1;
	for(int i = 2; i <= r; i++) {
		if (abs(A[l] - A[i]) >= c) {
			l = i;
			cow++;
		}
	}
	return cow;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, N, C, ans;
	cin >> t;
	while(t--) {
		cin >> N >> C;
		A.resize(N+1);
		for(int i = 1; i <= N; i++) {
			cin >> A[i];
		}
		
		sort(all(A));
		int l = 1, r = A[N] - A[1], mid;
		while(l <= r) {
			mid = l + (r-l)/2;
			if(calculateCowsForDist(mid) >= C) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}