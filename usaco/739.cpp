// Problem: Problem 2. Bovine Genomics
// Contest: USACO - USACO 2017 US Open Contest, Silver
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=739
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
author: eiji_tnpb
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define REP(idx,x) for(int i = idx; i<x; i++)
#define REPN(idx,x) for(int i = idx; i<=x; i++)
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
const int INF = 0x3f3f3f3f;
const ll INFLL = 8e18;
const int mx = 500;
// int R, C;
// N L O S NE SE SO NO
int dr[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dc[] = {0, 1, 0, -1, 1, 1, -1, -1};
//g++ -std=c++17 main.cpp -o main && time ./main
//g++ -std=c++17 -Wall main.cpp -o main && time ./main

set<size_t> sc_genes;
string sg[mx], ng[mx];
int C, GL;
hash<string> str_hash;

void solve()
{
	cin >> C >> GL;
	for(int sc = 0; sc < C; sc++) cin >> sg[sc];
	for(int nc = 0; nc < C; nc++) cin >> ng[nc];
	int ans = 0;
	
	for(int g1 = 0; g1 < GL-2; g1++) {
		for(int g2 = g1 + 1; g2 < GL - 1; g2++) {
			for(int g3 = g2 + 1; g3 < GL; g3++) {
				bool s_gen = true;
				sc_genes.clear();
				
				string s;
				for(int sc = 0; sc < C; sc++){
					s.push_back(sg[sc][g1]);
					s.push_back(sg[sc][g2]);
					s.push_back(sg[sc][g3]);
					sc_genes.insert(str_hash(s));
					s = "";
				}
				
				for(int nc = 0; nc < C && s_gen; nc++){
					s.push_back(ng[nc][g1]);
					s.push_back(ng[nc][g2]);
					s.push_back(ng[nc][g3]);
					if(sc_genes.find(str_hash(s)) != sc_genes.end() )
						s_gen = false;
					s = "";
				}
				if(s_gen) ans++;
			}
		}
	}
	
	cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    solve();
    return 0;
}
