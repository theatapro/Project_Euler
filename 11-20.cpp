#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < (r); i++)
typedef long long ll;
using namespace std;

void sol_16(void)
{
	vector<int> dig(350, -1);
	dig[0] = 1;

	rep(i, 0, 1000)
	{
		int flag = 1;
		int j = 0;
		int pre = 0;
		while(flag != -1)
		{
			int n = dig[j];
			flag = dig[j + 1];
			dig[j] = (2 * n) % 10 + pre;
			pre = 0;
			if(n >= 5)
			{
				if(flag == -1)
					dig[j + 1] = 1;
				else
					pre = 1;
			}
			j++;
		}
	}
	ll ans = 0;
	for(auto p : dig)
		if(p != -1)
			ans += p;

	cout << ans << endl;
}

//for sol_11
bool grid_valid(int x, int y, int dx, int dy)
{
	int edge_x = x + 3*dx;
	int edge_y = y + 3*dy;
	
	if((0 <= edge_x && edge_x <20) && (0 <= edge_y && edge_y <20))
		return(true);
	return(false);
}

void sol_11(void)
{
	vector<vector<int> > grid(20,vector<int>(20));
	ll ans = 1;
	const int dx[4] = {1,1,1,0};
	const int dy[4] = {-1,0,1,1};

	rep(i, 0, 20)
		rep(j, 0, 20)
			cin >> grid[i][j];

	rep(i, 0, 20)
		rep(j, 0, 20)
			{
				rep(k, 0, 4)
				{
					ll pro = 1;
					if(grid_valid(i, j, dx[k], dy[k]))
						rep(l, 0, 4)
							pro *= grid[i+l*dx[k]][j+l*dy[k]];
					ans = max(ans, pro);
				}
			}
	cout << ans << endl;
	
}

void sol_20(void)
{
	vector<int> dig(10000,0);
	dig[0] = 1;

	rep(i, 1, 101)
	{
		rep(j, 0, 10000)
			dig[j] *= i;
		rep(j, 0, 10000)
			if(dig[j] >= 10)
			{
				dig[j + 1] += dig[j] / 10;
				dig[j] %= 10;
			}
	}
	ll ans = 0;
	rep(i, 0, 10000)
		ans += dig[i];
	cout << ans << endl;

}

void sol_13(void)
{
	string S;
	vector<int> dig(60, 0);

	rep(i, 0, 100)
	{
		cin >> S;
		rep(j, 0, 50)
			dig[j] += S[50 - 1 - j] - '0';
		rep(k, 0, 59)
			if(dig[k] >= 10)
			{
				dig[k + 1] ++;
				dig[k] %= 10;
			}
	}

	for(int p = 59; p >= 0; --p)
		if(dig[p] != 0)
		{
			for(int i = p; i > p - 10; i--)
				cout << dig[i];
			break;
		}
}

void sol_14(void)
{
	vector<bool> longest_chain(1000001);
	ll max_cnt = 0;
	ll max_i = 1;

	rep(i, 1, 1000001)
	{
		ll num = i;
		ll cnt = 0;
		while(num != 1)
		{
			if(num % 2 == 0)
				num /= 2;
			else
				num = num * 3 + 1;
			if(num <= 1000000)
				longest_chain[num] = false;
			cnt++;
		}
		max_cnt = max(cnt, max_cnt);
		if(cnt == max_cnt)
		{
			longest_chain[max_i] = false;
			longest_chain[i] = true;
			max_i = i;
		}
	}

	rep(i, 1, 1000001)
		if(longest_chain[i])
			cout << i;
}

//for sol_12
ll divisor_cnt(ll x)
{
	ll cnt = 0;

	for(ll d = 1; d*d<=x; d++)
		if(x % d == 0)
		{
			if(d*d == x)
				cnt ++;
			else
				cnt += 2;
		}
	return(cnt);
}

void sol_12(void)
{
	ll triangle_num = 1;
	ll add_num = 1;

	while(divisor_cnt(triangle_num) <= 500)
	{
		add_num ++;
		triangle_num += add_num;
	}
	cout << triangle_num;
}

//for sol_15
vector<vector<ll> > nCk(int n, int k)
{
	vector<vector<ll> > ret(n + 1, vector<ll>(n + 1, 0));

	rep(i, 0, ret.size())
	{
		ret[i][0] = 1;
		ret[i][i] = 1;
	}
	rep(i, 1, ret.size())
		rep(j, 1, i)
			ret[i][j] = (ret[i - 1][j - 1] + ret[i - 1][j]);

	return ret;

}

void sol_15(void)
{
	vector<vector<ll> > Comb(41,vector<ll>(41));
	const int n = 40;
	const int k = 20;
	Comb = nCk(n, k);
	cout << Comb[n][k];
}

int main(void)
{
	sol_15();
	return(0);
}