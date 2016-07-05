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
	long long int s, s2;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		s = 0;
		s2 = 0;
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
			s += arr[i];
			s2 += arr[i]*arr[i];
			s %= MOD;
			s2 %= MOD;
		}
		std::cout << ((s*s-s2)%MOD+MOD)%MOD << '\n';
	}
}
