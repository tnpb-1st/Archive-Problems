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
// Global Var =================================================================================
int N, K;
bool pieces[11][8][8];
vector<int> s[11];
bool check(int p, int x, int y);
void solve()
{
  cin >> N >> K;
  char c;
  int left, right, bot, top;
  for(int i = 0; i <= K; i++) {
    left = top = N - 1;
    right = bot = 0;
    for(int r = 0; r < N; r++) {
      for(int col = 0; col < N; col++) {
        cin >> c;
        pieces[i][r][col] = (c == '#');
        if(pieces[i][r][col]) {
          left = min(left, col);
          right = max(right, col);
          bot = max(bot, r);
          top = min(top, r);
        }
      }
      s[i] = {left, right, bot, top};
    }
  }
  for(int p1 = 1; p1 <= K; p1++) {
    for(int p2 = p1 + 1; p2 <= K; p2++) {
      for(int idx = s[p1][3] - N + 1; idx <= s[p1][2]; idx++) {
        for(int idy = s[p1][1] - N + 1; idy <= s[p1][0]; idy++) {
          for(int jdx = s[p2][3] - N + 1; jdx <= s[p2][2]; jdx++) {
            for(int jdy = s[p2][1] - N + 1; jdy <= s[p2][0]; jdy++) {
              bool good = true;
              for(int x = 0; x < N; x++) {
                for(int y = 0; y < N; y++) {
                  bool pc1 = check(p1, x + idx, y + idy);
                  bool pc2 = check(p2, x + jdx, y + jdy);
                  if(pc1 && pc2) {
                    good = false;
                    break;
                  }
                  if(pieces[0][x][y] != (pc1 || pc2)) {
                    good = false;
                    break;
                  }
                }
                if(!good) {
                  break;
                }
              }
              if(good) {
                cout << min(p1,p2) << ' ' << max(p1,p2);
                return;
              }
            }
          }
        }
      }
    }
  }
}

bool check(int p, int x, int y) {
  return x >= 0 && x < N && y >= 0 && y < N && pieces[p][x][y];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  freopen("bcs.in", "r", stdin);
  freopen("bcs.out", "w", stdout);

  solve();
  return 0;
}
