#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B; cin >> N >> B;
    vector<ii> points;
    for(int i = 0; i < N; i++) {
        int x,y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    int ans = N;
    for(int xInd = 0; xInd < N; xInd++) {
        for(int yInd = 0; yInd < N; yInd++) {
            int a = points[xInd].first + 1;
            int b = points[yInd].second + 1;
            int n1, n2, n3, n4;
            n1 = n2 = n3 = n4 = 0;
            for(int i = 0; i < N; i++) {
                int x = points[i].first, y = points[i].second;
                if(x < a && y > b) n1++;
                else if(x > a && y > b) n2++;
                else if(x < a && y < b) n3++;
                else n4++;
            }
            ans = min(ans,max({n1,n2,n3,n4}));
        }
    }
    cout << ans;
    return 0;
}