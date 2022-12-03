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
const ll LIM = 1000000;

ll cycle_length(ll n, vector<ll> &A)
{
	ll num = 0;
	while(n != 1)
	{
		if(n & 1)
			n = 3*n + 1;
		else
			n = n / 2;
		
		num++;
		if(n <= LIM)
		{
			if(A[n] != 0) return A[n] + num;
		}
	}
	num++;
	return num;
}

void solve()
{
	vector<ll> PS(1000001, 0);
	ll f_out;
	for(ll i = 1000000; i > 0; i--)
	{
		f_out = cycle_length(i, PS);
		// if(i == 956739) cout << f_out<<endl;
		// if(i == 956006) cout << f_out << endl;
		PS[i] = f_out;	
	}
	ll l, r;
	while(cin >> l)
	{
		cin >> r;
		ll max_v = 0;
		ll t_l, t_r;
		t_l = min(l,r);
		t_r = max(l,r);
		for(ll i = t_l; i <= t_r; i++)
		{
			max_v = max(max_v, PS[i]);
		}
		cout << l << " " << r << " " << max_v << endl;
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