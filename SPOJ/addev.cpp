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

ll reverse(ll x)
{
	ll rev = 0LL;
	int pot = pow(10,(floor(log10(x) + 1) - 1));
	while(x > 0)
	{
		rev += (pot * (x%10));
		pot/=10;
		x/=10;
	}
	return rev;
}

void solve()
{
	int t;
	ll n1, n2,res;
	cin >> t;
	while(t--)
	{
		cin >> n1 >> n2;
		res = (ll)(reverse(n1) + reverse(n2));
		cout << reverse(res)<<endl;
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