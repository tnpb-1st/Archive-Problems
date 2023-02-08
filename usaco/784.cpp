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
  int N; cin >> N;
  int t0, tf, l0, lf;

  for(int i = 0; i < N; i++) {
    cin >> t0 >> tf;
    shifts.push_back({t0,tf});
    
  }
  sort(all(shifts));
  int longest_shift = -1;
  for(int i = 0; i < N; i++) {
    int temp_shift = 0;
    l0 = -1, lf = -1;
    for(int j = 0; j < N; j++) {
      if(i == j) continue;
      if(l0 == -1) {
        l0 = shifts[j].first, lf = shifts[j].second;
      } else {
        if(shifts[j].first <= lf) {
          lf = shifts[j].second;
        } else {
          temp_shift += (lf - l0);
          l0 = shifts[j].first, lf = shifts[j].second;
        }
      }
    }
    temp_shift += (lf - l0);
    longest_shift = max(temp_shift, longest_shift);
  }
  cout << longest_shift;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  solve();
  return 0;
}