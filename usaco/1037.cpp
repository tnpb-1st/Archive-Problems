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
const int inf = 0x6FFFFFFF;
// Global Var =================================================================================
tuple<int,int,int> h; // handshake
int N, T;
int t, cx, cy;
int kMin = inf, kMax = 0;
int cowx[251], cowy[251], K[101]; // handshakes
bitset<101> sickCows;
bitset<101> patientsZ0;

bool simulate(int p0, int k){
  bitset<101> isSick;
  memset(K, 0, sizeof(K));
  isSick[p0] = 1;
  for(int t = 1; t <= 250; t++) {
    cx = cowx[t], cy = cowy[t];
    if(cx > 0) {
      if(isSick[cx]) K[cx]++;
      if(isSick[cy]) K[cy]++;
      if(isSick[cx] && (K[cx] <= k)) isSick[cy] = 1;
      if(isSick[cy] && (K[cy] <= k)) isSick[cx] = 1;
    }
  }
  for(int i = 1; i <= N; i++) {
    if(isSick[i] != sickCows[i])
      return false;
  }
  return true;
}

void solve()
{
  cin >> N >> T;
  string s; cin >> s;
  for(int i = 0; i < s.length(); ++i)
    sickCows[i+1] = (s[i] == '1') ? 1 : 0;
  for(int i = 0; i < T; i++) {
    cin >> t >> cx >> cy;
    cowx[t] = cx;
    cowy[t] = cy;
  }

  for(int p0 = 1; p0 <= N; p0++) {
    for(int k = 0; k <= T; k++) {
      if(simulate(p0, k)) {
        kMax = max(kMax, k);
        kMin = min(kMin, k);
        patientsZ0[p0] = 1;
      }
    }
  }
  // output
  cout << patientsZ0.count() << ' ' << kMin << ' ';
  if(kMax == T)
    cout << "Infinity";
  else
    cout << kMax;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  // freopen("in.txt", "r", stdin);
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  solve();
  return 0;
}
