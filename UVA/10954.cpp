#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void solve()
{
	int N, num, n1, n2;
	ll sum;
	while(cin >> N && N != 0)
	{
		sum = 0;
		priority_queue<int,vi,greater<int>> hp;
		for(int i=0; i<N; i++)
		{
			cin>>num;
			hp.emplace(num);
		}

		n1 = hp.top();hp.pop();
		n2 = hp.top();hp.pop();
		sum += n1 + n2;
		hp.emplace(n1+n2);
		while(!hp.empty())
		{
			n1 = hp.top();hp.pop();
			if(hp.empty())break;
			n2 = hp.top(); hp.pop();
			sum+= n1 + n2;
			hp.emplace(n1+n2);
		}
		cout<<sum<<endl;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freeopen("input.txt", "r", stdin);
	// freeopen("output.txt", "w", stdout);

	solve();
	return 0;
}