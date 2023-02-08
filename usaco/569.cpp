/*
ID: samotbn1/tnpb/tomeslav
*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// ============================ GLOBAL VAR ===================================
int N, M, D, S;

void solve()
{
  cin >> N >> M >> D >> S;
  vector<vector<pii>> peopleMilk(N+1, vector<pii>());
  vector<pii> sickPeople;
  vector<vector<bool>> sickPeopleMilk(N+1, vector<bool>(M+1, false));
  vector<int> badMilk(M + 1, 0);
  vector<int> possibleBadMilks;
  vector<int> minVaccines(M + 1, 0);  
  for(int i = 0; i < D; i++) {
    int p, m, t;
    cin >> p >> m >> t;
    peopleMilk[p].push_back({m, t});
  }
  for(int i = 0; i < S; i++) {
    int p, t;
    cin >> p >> t;
    sickPeople.push_back({p, t});
  }
  for(auto &[p, ts] : sickPeople) {
    for(auto &[m, tm] : peopleMilk[p]) {
      if(ts > tm && !sickPeopleMilk[p][m]) {
        badMilk[m] += 1;
        sickPeopleMilk[p][m] = true;
      }
    }
  }
  for(int i = 1; i <= M; i++) {
    if(badMilk[i] == S)
      possibleBadMilks.push_back(i);
  }
  for(auto &m : possibleBadMilks) {
    for(int p = 1; p <= N; p++) {
      for(auto &[mp, t] : peopleMilk[p]) {
        if(m == mp) {
          minVaccines[m] += 1;
          break;
        }
      }
    }
  }
  int minVax = -1;
  for(auto &x: minVaccines) minVax = max(minVax, x);
  cout << minVax;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  // freopen("in.txt", "r", stdin);
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);

  solve();
  return 0;
}
