#include <bits/stdc++.h>
#include <fstream>
#define rep(i, l, r) for(int i = l; i < (r); i++)
typedef long long ll;

using namespace std;
using P = pair<int, int>;

bool prime_check(int n)
{
	if(n <= 1)
		return(false);
	for(int p = 2; p*p <= n; ++p)
		if(n % p == 0)
			return(false);
	return(true);
}

//dp[i][j]:=硬貨種a[0]~a[i]まで使う時jとなる総数
//a[i+1][j] = a[i][j-a[i]] + a[i][j]
//a[]={1,2,3}
void sol_31(void)
{
	const vector<ll> money_vec = {1, 2, 5, 10, 20, 50, 100, 200};
	const ll K = 200;
	ll M = money_vec.size();
	vector<ll> dp(K + 1);

	dp[0] = 1;

	rep(i, 0, M)
		rep(j, money_vec[i], K + 1)
			dp[j] += dp[j - money_vec[i]];

	cout << dp[200] << endl;

}

int main(void)
{
	sol_31();
	return(0);
}