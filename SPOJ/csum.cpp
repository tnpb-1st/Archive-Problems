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
	int n;
	cin >> n;
	vi A(n);
	vi P(n);
	int aux;
	for(int i = 0; i < n; i++)
	{
	    cin >> aux;
	    A[i] = aux;
	    
	}
	P[0] = A[0];
	for(int i =1; i < n; i++)
		P[i] = P[i - 1] + A[i];
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int ans;
		if(l == 0) 
			ans = P[r];
		else
			ans = P[r] - P[l-1];
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