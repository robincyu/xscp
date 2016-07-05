#include <ios>
#include <iostream>
#define MOD 1000000007

long long int arr[200005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n;
	long long int ans;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		ans = 0;
		for (int i = 0; i < n; i++)
			std::cin >> arr[i];
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
		std::cout << ans%MOD << '\n';
	}
}
