/*
ID: samotbn1/eiji_tnpb/tomeslav
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

void solve()
{
  vector<pii> shifts;
  vector<int> times(1001, 0);
  int N; cin >> N;
  int t0, tf, l0, lf;
  l0 = INT_MAX, lf = -1;

  for(int i = 0; i < N; i++) {
    cin >> t0 >> tf;
    shifts.push_back({t0,tf});
    l0 = min(t0, l0), lf = max(lf, tf);
    for(int t = t0; t < tf; t++) times[t]++;
  }
  int longest_shift = -1, cont = 0;
  for(auto & [t0, tf] : shifts) {
    cont = 0;
    for(int t = t0; t < tf; t++) times[t]--;
    for(int t = l0; t < lf; t++) 
      if(times[t] > 0)cont++;
    for(int t = t0; t < tf; t++) times[t]++;
    longest_shift = max(longest_shift, cont);
  }
  cout << longest_shift;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  // freopen("in.txt", "r", stdin);
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  solve();
  return 0;
}