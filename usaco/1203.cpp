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
// Global Variables
int N, sum;
vi vec;
//---------------------------------------------------------------------------------------------

bool check(int sum, int N, int hours) {
  stack<int> stk;
  stk.emplace(vec[0]);
  for (int i = 1; i < vec.size(); i++) {
    int a = vec[i];
    if (a > hours) return false;
    else if (stk.top() == hours)
      stk.emplace(a);
    else if (stk.top() + a == hours) {
      stk.pop();
      stk.emplace(hours);
    } else if (stk.top() + a < hours ){
      int temp = stk.top() + a;
      stk.pop();
      stk.emplace(temp);
    } else 
      return false;
  }
  if(stk.top() == hours)
    return true;

  return false;
}

void solve()
{
  int TC; cin >> TC;
  while(TC--) {
    cin >> N;
    vec = vi(N);
    sum = 0;
    int max_i = -1;
    for (auto &x : vec) {
      cin >> x;
      sum += x;
      max_i = max(max_i, x);
    }
    int ans = N - 1;
    if(sum == 0) ans = 0;
    for (int hi = max_i; hi < sum; hi++) {
      if((sum % hi == 0)) {
        if(check(sum, N, hi)) {
          ans = N - (sum/hi);
          break;  
        }
      }
    }
    cout << ans << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  // freopen("in.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  solve();
  return 0;
}
