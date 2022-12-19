#include <bits/stdc++.h>
#include <fstream>
#define rep(i, l, r) for(int i = l; i < (r); i++)
typedef long long ll;

using namespace std;
using P = pair<int, int>;

void sol_22(void)
{
	ifstream in("p022_names.txt");
	vector<string> name_list; 
	string name;

	while(getline(in, name, ','))
		name_list.push_back(name);

	sort(name_list.begin(), name_list.end());

	cout << name_list[937];
	ll th = 1;
	ll ans = 0;
	rep(i, 0, name_list.size())
	{
		rep(j, 0, name_list[i].size())
			if(name_list[i][j] != '"')
				ans += th * (name_list[i][j] - 'A' + 1);
		th++;
	}
	cout << ans << endl;
}

void sol_19(void)
{
	const int INI_YEAR = 1900;
	const int END_YEAR = 2001;
	//day:0 ~ 6, Monday = 0,Sunday = 6
	int day = 0;
	int ans = 0;

	rep(y, INI_YEAR, END_YEAR)
		rep(m, 1, 13)
		{
			if(day == 6 && y != 1900)
				ans++;

			if(m == 9 || m == 4 || m == 6 || m == 11)
				day = (day + 30) % 7;
			else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				day = (day + 31) % 7;
			else
			{
				if((y % 100 == 0 && y % 400 != 0) || y % 4 != 0)
					day = (day + 28) % 7;
				else
					day = (day + 29) % 7;
			}
		}
	cout << ans << endl;
}

void sol_28(void)
{
	int const diag_num = 1001;
	ll A = 0, B = 0, C = 0, D = 0;
	ll ans = 1;

	rep(level, 2, (diag_num + 1) / 2 + 1)
	{
		A = (2*level - 1)*(2*level - 1);
		B = A - (2 * (level - 1));
		C = B - (2 * (level - 1));
		D = C - (2 * (level - 1));
		ans += A + B + C + D;
	}
	cout << ans << endl;
}

void sol_67(void)
{
	ifstream in("p067_triangle.txt");
	vector<vector<int>> num_list(100, vector<int>(100, 0)); 
	int num;

	rep(i, 0, 100)
		rep(j, 0, i + 1)
		{
			in >> num;
			num_list[i][j] = num;
		}

	//dp[x][y]:max sum at (x,y)
	//ans = max(num_list[99][0~99])
	vector<vector<int>> dp(100, vector<int>(100, 0));
	dp[0][0] = num_list[0][0];
	rep(i, 0, 99)
		rep(j, 0, i + 2)
		{
			if(j == 0)
				dp[i+1][j] = dp[i][0] + num_list[i+1][j];
			else if(j == i + 1)
				dp[i+1][j] = dp[i][i] + num_list[i+1][j];
			else	
				dp[i+1][j] = max(dp[i][j - 1], dp[i][j]) + num_list[i+1][j];
		}

	int ans = 0;
	rep(i, 0, 100)
		ans = max(ans, dp[99][i]);
	cout << ans;
}

void sol_24(void)
{
	const int N = 1000000;
	int M = 10;
	int width = 1;
	vector<int> dig_list = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	rep(i, 1, M + 1)
		width *= i;

	int cnt = 0;
	int search_width = width;
	string ans = "";
	while(1)
	{
		search_width /= M;
		int dig = 0;
		while(1)
		{
			cnt += search_width;
			if(cnt >= N)
			{
				ans += to_string(dig_list[dig]);
				dig_list.erase(dig_list.begin() + dig);
				cnt -= search_width;
				break;
			}
			dig++;
		}
		if(M == 1)
			break;
		M --;
	}

	cout << ans << endl;
}

//for sol_30
int fifth_digit(string S)
{
	int ret = 0;
	rep(i, 0, S.size())
		ret += pow(S[i] - '0', 5);
	return(ret);
}

void sol_30(void)
{
	const int N = 10000;
	string S;
	ll ans = 0;

	rep(i, 2, 100*N)
	{
		S = to_string(i);
		if(fifth_digit(S) == i)
		{
			cout << i << endl;
			ans += i;
		}
	}
	cout << ans;
}

//for sol_29
void prime_fact(int N, vector<vector<vector<P>>> &num_vec)
{
	int num = N;
	while(num != 1)
	{
		for(int p = 2; p<=N; p++)
		{
			if(num % p == 0)
				num_vec[N][1].push_back(make_pair(p, 0));
			while(num % p == 0)
			{
				num /= p;
				num_vec[N][1][num_vec[N][1].size() - 1].second++;
			}
		}
	}
	return;
}

void sol_29(void)
{
	const int N = 100;
	vector<vector<vector<P>>> num_vec(N + 1,vector<vector<P>>(N + 1));
	map<vector<P>,int> count;
	int ans = 0;
	
	rep(i, 2, N + 1)
		prime_fact(i, num_vec);

	rep(a, 2, N + 1)
		rep(b, 2, N + 1)
			rep(size, 0, num_vec[a][1].size())
				{
					num_vec[a][b].push_back(make_pair(num_vec[a][1][size].first,b*num_vec[a][1][size].second)); 
					count[num_vec[a][b]] = 1;
				}

	rep(a, 2, N + 1)
		rep(b, 2, N + 1)
		{
			ans += count[num_vec[a][b]];
			count[num_vec[a][b]] = 0;
		}

	cout << ans << endl;
}

//for ab_num for sol_23
int sum_divs(int n)
{
	int ret = 0;

	for(int p = 1; p * p<= n; p++)
	{
		if(n % p == 0)
		{
			ret += p;
			ret += n / p;
		}
		if(p * p == n)
			ret -= p;
	}
	ret -= n;
	return(ret);
}

//for sol_23
void ab_num(vector<int> &ab_num_list, int K)
{
	int N = 1;
	rep(i, N, K)
		if(sum_divs(i) > i)
		{
			ab_num_list.push_back(i);
			// cout << i << endl;
		}
}

void sol_23(void)
{
	const int K = 28125;
	vector<bool> sum_able(K);
	vector<int> ab_num_list;
	ab_num(ab_num_list, K);

	rep(i, 0, ab_num_list.size())
		rep(j, 0, ab_num_list.size())
		{
			int n = ab_num_list[i] + ab_num_list[j];
			if(n < K)
				sum_able[n] = true;
		}
	ll ans = 0;
	rep(i, 0, K)
		if(!sum_able[i])
			ans += i;
	cout << ans << endl;
}

//for sol_26
bool list_check(vector<int> &list, int r)
{
	rep(i, 0, list.size())
		if(list[i] == r)
			return(true);
	return(false);
}

void sol_26(void)
{
	const int K = 1001;
	vector<vector<int>> r_list(K, vector<int>());
	int max_cnt = 0;
	int max_d = 0;

	rep(i, 1, K)
	{
		int numerator = 1;
		while(numerator/i == 0)
			numerator *= 10;
		int r;
		int cnt = 0;
		while(1)
		{
			r = numerator % i;
			if(list_check(r_list[i], r))
				break;
			r_list[i].push_back(r);
			numerator = r * 10;
			cnt ++;
		}
		max_cnt = max(cnt, max_cnt);
		if(max_cnt == cnt)
			max_d = i;
	}
	cout << max_d;

}

//for sol_27
bool prime_check(int n)
{
	if(n <= 1)
		return(false);
	for(int p = 2; p*p <= n; ++p)
		if(n % p == 0)
			return(false);
	return(true);
}

void sol_27(void)
{
	const int N = 1000;
	vector<int> prime_list;

	rep(i, 0, N + 1)
		if(prime_check(i))
			prime_list.push_back(i);
	
	int max_n = 0;
	int ans = 0;
	for(auto b : prime_list)
		for(int a = -b; a < N; a++)
		{	
			int n = 0;
			int result = n * n + a * n + b;
			while(prime_check(result))
			{
				n++;
				result = n * n + a * n + b;
			}
			max_n = max(max_n, n);
			// cout << "a:" << a << " b:" << b << " n:" << n <<endl;
			if(n == max_n)
				ans = a * b;
		}
	cout << ans << endl;
}

void sol_31(void)
{
	const int K = 200;
	vector<ll> dp(K + 1);
	vector<int> money_vec = {1, 2, 5, 10, 20, 50, 100, 200};

	dp[0] = 1;
	dp[1] = 1;

	rep(i, 2, K + 1)
		for(auto m : money_vec)
		{
			if(i - m < 0)
				continue;
			dp[i] += dp[i - m];
		}

}

int main(void)
{
	sol_31();
	return(0);
}