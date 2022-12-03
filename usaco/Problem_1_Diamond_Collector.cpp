#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int maxAns = -1;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(vec[j] - vec[i] <= K) {
                maxAns = max(maxAns, (j - i + 1));
            } else {
                break;
            }
        }
    }
    cout << maxAns;
}