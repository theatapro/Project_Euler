#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = l; i < r; ++i)
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
	ll num = 600851475143;
	ll ans = 1;

	for(ll p=1; p*p <= num; p++)
	{
		if(num % p == 0)
			ans = p;
	}
	ans = max(ans,num/ans);
	cout << ans << endl;
}

int main(void)
{
	sol_3();
}