#include <ios>
#include <iostream>
#include <algorithm>
#define MOD 1000000007

long long int arr[200005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n;
	long long int s, s2, c;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		s = 0;
		s2 = 0;
		c = 1;
		for (int i = 0; i < n; i++)
		{
			std::cin >> arr[i];
			s += arr[i];
			s %= MOD;
		}
		std::sort(arr, arr+n);
		for (int i = 1; i < n; i++)
		{
			if (arr[i] != arr[i-1])
			{
				s2 += (c*c%MOD)*(arr[i-1]*arr[i-1]%MOD);
				s2 %= MOD;
				c = 1;
			}
			else
				c++;
		}
		s2 += (c*c%MOD)*(arr[n-1]*arr[n-1]%MOD);
		s2 %= MOD;
		std::cout << ((s*s-s2)%MOD+MOD)%MOD << '\n';
	}
}
