#include <ios>
#include <iostream>
#include <cmath>

int ans[50] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, k, c, p;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> k;
		c = 0;
		int s = sqrt(n)+5;
		for (int i = 2; i <= s; i++)
		{
			while (n % i == 0)
			{
				ans[c] = i;
				c++;
				n /= i;
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
