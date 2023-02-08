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
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int lb(ll x, vll &vec) {
  int l = 0, r = vec.size() - 1, mid;
  while(l <= r) {
    mid = l + (r - l) / 2;
    if(vec[mid] < x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  mid = l;
  while((mid < vec.size()) && (vec[mid] < x))
    mid++;
  if(mid == vec.size())
    return -1;
  else
    return mid;
}

int ub(ll x, vll &vec) {
  int l = 0, r = vec.size() - 1, mid;
  while(l <= r) {
    mid = l + (r - l) / 2;
    if(vec[mid] <= x) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  mid = l;
  while((mid < vec.size()) && (vec[mid] <= x))
    mid++;
  if(mid == vec.size())
    return -1;
  else
    return mid;
}

void solve()
{
  int N, ng, nl; cin >> N;
  ng = nl = 0;
  vll vg, vl;
  for(int i = 0; i < N; i++) {
    char c; ll p;
    cin >> c >> p;
    if(c == 'L'){
      vl.push_back(p);
      nl++;
    }else {
      vg.push_back(p);
      ng++;
    }
  }
  sort(all(vl));
  sort(all(vg));
  int ans = INT_MAX;
  int lyingCows;

  for(int i = 0; i < nl; i++) {
    ll pi = vl[i]; 
    lyingCows = 0;
    int _pos = lb(pi, vl);
    lyingCows += _pos;

    _pos = ub(pi, vg);
    if(_pos != -1) {
      lyingCows += (ng - _pos);
    }
    if(lyingCows < ans)
      ans = lyingCows;
  }

  for(int i = 0; i < ng; i++) {
    ll pi = vg[i];
    lyingCows = 0;
    int _pos = ub(pi, vg);
    if(_pos != -1) {
      lyingCows += (ng - _pos);
    }
    _pos = lb(pi, vl);
    if(_pos != -1) {
      lyingCows += _pos;
    } else {
      lyingCows += nl;
    }
    if(lyingCows < ans)
      ans = lyingCows;
  }

  cout << ans;
}

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(0);
  //  freopen("in.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

   solve();
   return 0;
}
