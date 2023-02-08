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
int cowx[101], cowy[101];
int N, B;

void solve()
{
  cin >> N >> B;
  int M = MINT;
  int a, b;
  for(int i = 1; i <= N; i++)
    cin >> cowx[i] >> cowy[i];

  int difx = MINT, dify = MINT;
  int q1, q2, q3, q4;
  for(int xI = 1; xI <= N; xI++) {
    for(int yI = 1; yI <= N; yI++) {
      a = cowx[xI] + 1, b = cowy[yI] + 1;
      q1 = q2 = q3 = q4 = 0;
      for(int i = 1; i <= N; i++) {
        int x = cowx[i], y = cowy[i];
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
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  solve();
  return 0;
}
