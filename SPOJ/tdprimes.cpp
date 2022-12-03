#include <bits/stdc++.h>
#define large_n 100000000
#define endl '\n'
using namespace std;
bool is_prime[large_n] = {0};


int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n = large_n;
    is_prime[0] = is_prime[1] = 1;
    for (int i = 2; i * i <= n; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 1;
        }
    }

    for(int i=2, j = 100; i<= n; i++)
        if(!is_prime[i])
        {
            if((j)%100 == 0)printf("%d\n",i);
            j++;
        }
    
    return 0;
}