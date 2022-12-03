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

//bases = 787, 997
//alt-mod = 1e9+87, 1e9 + 207
ll dp[1000001], inv[1000001];

ll chr(char &c) {return c - 'a' + 1;}

ll getHash(string &key, ll base =797, ll mod = 1e9+87) {
    ll value = 0;
    ll p = base;
    ll p_power = 1;

    for(char ch:key) {
        value = (value + chr(ch)*p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}

struct HashStr
{
    ll p, p_power, mod, sz;

    
    HashStr(string &str, ll base=797, ll md=1e9+87 ,ll p_pwr = 1) {
        p = base, p_power = p_pwr, mod = md, sz = str.size();
        inv[0] = 1;
        dp[0] = chr(str[0]);

        for(int i = 1; i < str.size(); i++) {
            char ch = str[i];
            p_power = (p_power * p) % mod;
            inv[i] = power(p_power, mod - 2);
            dp[i] = (dp[i-1] + chr(ch)*p_power)%mod;
        }
    }

    ll power(ll a, ll t) {
        ll res = 1;
        while(t) {
            if(t & 1) res = (res * a) % mod;

            t>>=1;
            a = (a*a)%mod;
        }
        return res;
    }

    ll subStrHash(int l, int r) {
        ll res = dp[r];
        if(l > 0) res = (res-dp[l-1]+mod)%mod;
        res = (res*inv[l])%mod;
        return res;
    }
};



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    while(cin >> t) {
        string ptr, text;
        cin>>ptr>>text;
        HashStr hs(text);
        ll ptr_hash = getHash(ptr); 
        const int lim = text.size() - ptr.size() + 1;
        bool found = false;
        for(int i = 0; i < lim; i++) {
            if (ptr[0] == text[i] && ptr_hash == hs.subStrHash(i, i + ptr.size()-1)) {
                cout << i << endl;
                found = true;
            }
        }
        if(!found)
            cout<<endl;
    }
    return 0;
} 