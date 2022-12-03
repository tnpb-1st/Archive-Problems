#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
bool isPossible(vi &A, int n, int m, int lim)
{
	int students_required = 1;
	ll curr_sum = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] > lim)
			return false;
		else if(curr_sum + A[i] > lim)
		{
			students_required++;
			curr_sum = A[i];
			if(students_required > m)
				return false;
		}
		else
			curr_sum += A[i];
	}
	return true;
}


int findPages(vi &A, int n, int k)
{
	ll sum = 0;

	if(n < k)
		return -1;
	for(int i =0; i < n; i++)
		sum += A[i];

	int l = A[n-1], r = sum;
	int res = 11000000;
	while(l < r)
	{
		int mid = l + (r-l)/2;
		if (isPossible(A, n, k, mid))
		{
			res = mid;
			r = mid;
		}
		else
			l = mid + 1;
	}
	return res;
}

void solve()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vi A(n);
		string ans = "";
		for(int i =0; i < n; i++)
			cin >> A[i];
		int lim = findPages(A, n, k);
		int curr_l = 0;
		vi p_indexes;
		for(int i = n - 1; i >= 0; i--)
		{
			// cout << A[i]<< endl;
			if(curr_l + A[i] <= lim)
			{
				curr_l += A[i];
			}
			else {
				p_indexes.push_back(i);
				curr_l = A[i];
			}
		}
		int index = 0;
		sort(p_indexes.begin(), p_indexes.end());
		for(int i = 0; i < n; i++)
		{
			if(i == p_indexes[index])
			{
				cout << A[i] << " / ";
				index++;
			}
			else if (i == n - 1)
			{
				cout << A[i] << endl;
			}
			else
				cout << A[i] << " ";
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}