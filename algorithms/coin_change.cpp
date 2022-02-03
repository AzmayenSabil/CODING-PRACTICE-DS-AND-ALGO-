#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int amount, int n, vector<vector<int> >& dp)
{
	if (amount == 0)
		return dp[n][amount] = 1;
	if (n == 0)
		return 0;
	if (dp[n][amount] != -1)
		return dp[n][amount];
	if (a[n - 1] <= amount) {
		return dp[n][amount] = coinchange(a, amount - a[n - 1], n, dp) + coinchange(a, amount, n - 1, dp);
	}
	else
		return dp[n][amount] = coinchange(a, amount, n - 1, dp);
}


int main()
{
    int n, amount;

    n = 3, amount = 4;

    vector<int> a = { 1, 2, 3 };
    vector<vector<int> > dp(n + 1,vector<int>(amount + 1, -1));

    int res = coinchange(a, amount, n, dp);

    cout << res << endl;


	return 0;
}

//how many ways can we make the change  if we want to make the sum equal to n?
