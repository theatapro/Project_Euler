#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < (r); i++)
typedef long long ll;
using namespace std;

void sol_1(void)
{
	int ans = 0;
	rep(i, 0, 1000)
	{
		if(i % 3 == 0 || i % 5 == 0)
			ans+=i;
	}
	cout << ans;
}

void sol_2(void)
{
	int ans = 0;
	vector<ll> fib;
	fib.push_back(1);
	fib.push_back(2);

	int index = 2;
	ans += fib[1];

	while(1)
	{
		ll a = fib[index-2]+ fib[index-1];
		fib.push_back(a);
		if(a>4000000)
			break;
		if(a % 2 == 0)
			ans+=a;
		index++;
	}
	cout << ans;
}

void sol_6(void)
{
	ll sum_of_sq = 0;
	ll sq_of_sum = 0;

	rep(i, 1, 101)
	{
		sum_of_sq += i * i;
		sq_of_sum += i;
	}
	sq_of_sum *= sq_of_sum;

	ll ans = sq_of_sum - sum_of_sq;
	cout << abs(ans) << endl;
}

void sol_5(void)
{
	vector<int> elem;
	elem.push_back(2);
	int ans = 2;

	rep(i, 3, 21)
	{
		int mul = i;
		for(auto e:elem)
			if(mul % e == 0)
				mul /= e;
		if(mul!=0)
			elem.push_back(mul);
		ans *= mul;
	}
	cout << ans << endl;
}

void sol_3(void)
{
	ll const num = 600851475143;
	ll x = num;
	ll ans = 1;

	for(ll p=2; p*p <= num; ++p)
	{
		if(x%p == 0)
			ans = p;
		while(x%p == 0)
			x /= p;
	}
	cout << ans << endl;
}

//for sol_4
bool palin(ll num)
{
	string N, S;
	N = to_string(num);
	S = to_string(num);
	reverse(S.begin(), S.end());
	if(S==N)
		return(true);
	return(false);
}

void sol_4(void)
{
	int ans = 1;
	
	rep(i, 1, 1000)
		rep(j, 1, 1000)
			if(palin(i*j))
				ans = max(ans,i*j);
	cout << ans << endl;
}

void sol_7(void)
{
	int const num = 10001;
	vector<ll> prime_vec;
	prime_vec.push_back(2);

	ll x = 2;
	int count = 1;

	while(count<=num-1)
	{
		x++;
		bool flag = true;
		for(auto p : prime_vec)
		{
			if(x%p == 0)
			{
				flag = false;
				break;
			}
			if(p*p > x)
				break;
		}
		if(flag)
		{
			prime_vec.push_back(x);
			count++;
		}
	}
	cout << prime_vec[10000] << " ";
}

void sol_9(void)
{
	ll ans = 1;
	rep(i, 1, 334)
		rep(j, i, (1000-i)/2)
			if(i*i + j*j == pow(1000 - i - j, 2))
				ans = i*j*(1000-i-j);
	cout << ans << endl;
}

//for sol_8
ll thirteen_pro(string S, int n)
{
	ll ret = 1;
	if(n + 13 >= 1000)
		return(0);
	rep(i, n, n + 13)
		ret *= S[i] - '0';
	return(ret);
}

void sol_8(void)
{
	string S;
	cin >> S;
	ll pro = 1;
	ll ans = 0;

	rep(i, 0, 1000)
	{
		pro = 1;
		pro = thirteen_pro(S,i);
		ans = max(ans, pro);
	}
	cout << ans << endl;
}

//for sol_10
bool prime_judge(int n)
{
	for(int p = 2; p*p <= n; ++p)
		if(n % p == 0)
			return(false);
	return(true);
}

void sol_10(void)
{
	int const num = 2000000;
	ll ans = 0;
	rep(i, 2, num + 1)
		if(prime_judge(i))
			ans += i;

	cout << ans << endl;
}

int main(void)
{
	sol_10();
	return(0);
}