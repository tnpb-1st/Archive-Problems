#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<char> segmentedSieve(ll L, ll R) {
    // generate all primes up to sqrt(R)
    ll lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<ll> primes;
    for (ll i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (ll j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (ll i : primes)
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n_loops;
    ll L,R;
    cin>>n_loops;
    for(int i=0; i< n_loops; i++)
    {
        cin>>L>>R;
        vector<char> res = segmentedSieve(L, R);
        for(int j = 0; j <= R - L; j++)
            if(res[j])cout<<L+j<<endl;
        cout<<endl;
    }
    
    return 0;
}