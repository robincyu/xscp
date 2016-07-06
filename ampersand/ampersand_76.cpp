#include <ios>
#include <iostream>
#define MOD 1000000007

long long int arr[5005] = {};
long long int cnt[1000005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, x;
	bool greater;
	long long int ans, s, s2;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		greater = false;
		ans = 0;
		s = 0;
		s2 = 0;
		
		for (int i = 0; i < 1000005; i++)
			cnt[i] = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
			if (arr[i] > 1000000)
				greater = true;
		}
		if (n <= 5000)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i] != arr[j])
					{
						ans += arr[i]*arr[j];
						ans %= MOD;
					}
				}
			}
			std::cout << ans << '\n';
		}
		else if (greater)
		{
			for (int i = 0; i < n; i++)
			{
				s += arr[i];
				s2 += arr[i]*arr[i];
				s %= MOD;
				s2 %= MOD;
			}
			std::cout << ((s*s-s2)%MOD+MOD)%MOD << '\n';
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cnt[arr[i]]++;
				s += arr[i];
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
}
