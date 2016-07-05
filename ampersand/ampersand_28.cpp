#include <ios>
#include <iostream>
#define MOD 1000000007

long long int cnt[1000005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, x;
	long long int s, s2;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		s = 0;
		s2 = 0;
		for (int i = 0; i < 1000005; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> x;
			cnt[x]++;
			s += x;
			s %= MOD;
		}
		for (long long int i = 0; i < 1000005; i++)
		{
			s2 += (cnt[i]*cnt[i]%MOD)*(i*i%MOD);
			s2 %= MOD;
		}
		std::cout << ((s*s-s2)%MOD+MOD)%MOD << '\n';
	}
}
