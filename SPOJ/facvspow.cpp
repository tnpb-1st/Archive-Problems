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
vector<double> dp(10000001, -1);
/*
SOLUTION BY tnpb
*/

double facLog(ll &n) {
   double ans = log(1);
   if(dp[n] != -1) return dp[n];
   for(int i = 2; i<= n; i++) {
       ans = ans + log(i);
       dp[i] = ans;
   }
   return dp[n];
}

double facPow(ll &n, ll &a) {
    return n * log(a);
}

bool monoF(ll &n, ll a) {
    return facLog(n) > facPow(n,a);
}

void solve()
{
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        ll l = 1, r = 10000000, mid, ans;
        while(l <= r) {
            mid = l + (r-l)/2;
            if(monoF(mid, a)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
