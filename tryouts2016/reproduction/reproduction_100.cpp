#include <ios>
#include <iostream>
#include <cmath>

long long int ans[50] = {};
int primes[80000] = {};
bool isprime[1000100] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int ps = 0;
	for (int i = 2; i < 1000100; i++)
		isprime[i] = true;
	for (int i = 2; i < 1000100; i++)
	{
		if (isprime[i])
		{
			primes[ps] = i;
			ps++;
			for (int j = 2*i; j < 1000100; j+=i)
				isprime[j] = false;
		}
	}
	int t, k, c;
	long long int n, p;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> k;
		c = 0;
		int s = sqrt(n)+5;
		for (int i = 0; primes[i] <= s; i++)
		{
			while (n % primes[i] == 0)
			{
				ans[c] = primes[i];
				c++;
				n /= primes[i];
			}
		}
		if (n > 1)
		{
			ans[c] = n;
			c++;
		}
		if (c < k)
			std::cout << -1 << '\n';
		else
		{
			p = 1;
			for (int i = 0; i < c-k+1; i++)
				p *= ans[i];
			std::cout << p;
			for (int i = 1; i < k; i++)
				std::cout << ' ' << ans[c-k+i];
			std::cout << '\n';
		}
	}
}
