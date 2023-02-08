/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: samotbn1
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

void solve()
{
	int N; cin >> N;
	vi petals(N);
	int ans = 0;
	for (auto &p: petals) cin >> p;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			ll totalPetals = 0, numFlowers = 0;
			for(int a = i; a <= j; a++) {
				totalPetals += petals[a];
				numFlowers++;
			}
			if(totalPetals % numFlowers != 0) continue;
			ll avgFlower = totalPetals / numFlowers;
			for(int a = i; a <= j; a++) {
				if(petals[a] == avgFlower) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
}

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(0);
   // freeopen("input.txt", "r", stdin);
   // freeopen("output.txt", "w", stdout);

   solve();
   return 0;
}
