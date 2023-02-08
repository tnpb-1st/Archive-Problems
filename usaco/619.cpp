/*
ID: samotbn1/tnpb/tomeslav
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int MINT = 2e9 + 7;
const ll MLON = 9e18 + 7;
// Global Var =================================================================================
int N, B;

void solve()
{
  cin >> N;
  int M = MINT;
  int a, b;
  unordered_set<int> cowx, cowy;
  vector<pii> cows; 
  for(int i = 1; i <= N; i++) {
    int x, y; cin >> x >> y;
    cowx.insert(x);
    cowy.insert(y);
    cows.push_back({x,y});
  }

  int difx = MINT, dify = MINT;
  int q1, q2, q3, q4;
  for(int xi : cowx) {
    for(int yi : cowy) {
      q1 = q2 = q3 = q4 = 0;
      for(int i = 1; i <= N; i++) {
        int x = cows[i].first, y = cows[i].second;
		a = xi + 1, b = yi + 1;
        if(x < a && y > b) q1++;
        else if(x > a && y > b) q2++;
        else if(x < a && y < b) q3++;
        else q4++;
      }
      M = min(M, max({q1,q2,q3,q4}));
    }
  }
  cout << M;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  // freopen("balancing.in", "r", stdin);
  // freopen("balancing.out", "w", stdout);

  solve();
  return 0;
}
