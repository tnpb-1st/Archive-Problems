#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
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
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		char c;
		int V = 0, E = 0;
		bitset<26> BS;
		while(cin >> s && s[0]!= '*')
		{
			E++;
			BS[(s[1] - 'A')] = true;
			BS[(s[3]) - 'A'] = true;
		}
		cin.ignore();
		getline(cin, s);
		stringstream S(s);
		int anacorn = 0, trees = V;
		while(S >> c)
		{
			if(c != ','){
				if(BS[c - 'A'] == false)
					anacorn++;
				V++;
			}
		}
		trees = V - E - anacorn;
		cout << "There are " <<trees<<" tree(s) and "<<anacorn<<" acorn(s)."<<endl;
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
