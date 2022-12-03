#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;
const int arrLim = 1e6;
int dp[100001];
char M[100][100];
int R, C;
// N L O S NE SE SO NO
int mov_r[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int mov_c[] = {0, 1, 0, -1, 1, 1, -1, -1};

struct UnionFind {
    vi p, rank, setSize;
    int numSets;

    UnionFind(int N) {
        p.assign(N,0); for(int i = 0; i < N; i++) p[i] = i;
        rank.assign(N,0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i) {return (p[i] == i) ? i : p[i] = findSet(p[i]);}
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j); }
    int numDisjointSets() {return numSets; }
    int sizeOfSet(int i) {return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if(isSameSet(i,j)) return;
        int x = findSet(i), y = findSet(j);
        if(rank[x] > rank[y]) swap(x,y);
        p[x] = y;
        if(rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

/*
SOLUTION BY tnpb
*/
template<class T>
void printContainer(T &container) {
    for(auto &ele:container) cout << ele << ' ';
    cout<<'\n';
}

int floodFill(int r, int c, char c1, char c2) {
    if((r < 0) || (r >= R)) return 0;
    if((c < 0) || (c >= C)) return 0;
    if(M[r][c] != c1 ) return 0;
    M[r][c] = c2;
    int ans = 1;
    for(int i = 0; i < 8; i++) { // i < 4 se apenas N,L,O,S
        int y = r + mov_r[i], x = c + mov_c[i];
        if(y < 0 || y >= R || x < 0 || x >= C) continue;
        int e1 = r * R + c, e2 = y * R + x;
        if(M[y][x] != c1) continue;
        ans += floodFill(y, x, c1, c2);
    }
    return ans;
}

void solve()
{
    string line;
    getline(cin, line);
    int test = stoi(line);
    getline(cin,line);
    for(int t = 0; t < test; t++) {
        if(t > 0) cout << endl;
        vector<string> lines;vector<pii> queries;
        while(getline(cin,line) && line != "") {
            if(line[0] == 'W' || line[0] == 'L') {
                lines.push_back(line);
            }
            else {
                stringstream S(line);
                int row, cel;
                S >> row >> cel;
                queries.push_back({row,cel});
            }
        }
        C = lines[0].size();
        R = lines.size();

        for(int m = 0; m < R; m++) {
            string s = lines[m];
            for(int n = 0; n < C; n++) {
                M[m][n] = s[n];
            }
        }

        for(auto &pair:queries) {
            int row = pair.first, cel = pair.second;
            int r = row - 1 , c = cel - 1;
            if(M[r][c] == 'L') cout << 0 << endl;
            else {
                char c1 = 'W', c2 = '.';
                cout << floodFill(r, c, c1, c2) << endl;
                floodFill(r,c,c2,c1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    solve();
    return 0;
}
