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

double calc_dist(ll x1, ll y1, ll x2, ll y2) {
  double d = abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
  d = sqrt(d);
  return d;
}

void solve()
{
  ll N; cin >> N;
  vector<pair<long,long>> points;
  for(ll i = 0; i < N; i++) {
    ll x,y; cin >> x >> y;
    points.push_back({x,y});
  }
  ll ans = INT_MIN;
  for(ll i = 0; i < N; i++) {
    for(ll j = i + 1; j < N; j++) {
      for(ll k = j + 1; k < N; k++) {
        pair<ll,ll> p1, p2, p3; ll x1, x2, x3, y1, y2, y3;
        p1 = points[i], p2 = points[j], p3 = points[k];
        x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second, x3 = p3.first, y3 = p3.second;
        double l1, l2, l3;
        if((((x1 == x2) || (x1 == x3)) && (y2 == y3)) || 
        (((x2 == x3) || (x2 == x1)) && (y1 == y3))
        || (((x3 == x1) || (x3 == x2)) && (y2 == y1))) {
          l1 = calc_dist(x1, y1, x2, y2), l2 = calc_dist(x1, y1, x3, y3), l3 = calc_dist(x2, y2, x3, y3);
          if(((l1 + l2) >= l3) && ((l1 + l3) >= l2) && ((l2 + l3) >= l1)) {
            double p = (l1 + l2 + l3) / 2;
            double area = sqrt(p * (p-l1) * (p-l2) * (p-l3));
            if((ll)(2 * area) > ans)
              ans = round(2 * area);
          }
        }
      }
    }
  }

  cout << ans;
}

int main()
{
   cin.tie(0);
   ios::sync_with_stdio(0);
   freopen("triangles.in", "r", stdin);
   freopen("triangles.out", "w", stdout);

   solve();
   return 0;
}
