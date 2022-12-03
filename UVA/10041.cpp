#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main

void solve()
{
	int t;
	cin >> t;
	while(t--)
	{
		int r;
		cin >> r;
		vector<int> A(r);
		for(int i=0; i < r; i++)
			cin >> A[i];
		sort(A.begin(),A.end());
		int ans = 0;
		int mid = 0 + (r-0)/2;
		int median = A[mid];
		for(int &x: A)
			ans += abs(x - median);
		cout << ans << endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}