#include <ios>
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, k;
	bool found;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> k;
		if (k == 1)
		{
			if (n == 1)
				std::cout << -1 << '\n';
			else
				std::cout << n << '\n';
		}
		else
		{
			found = false;
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					std::cout << i << ' ' << n/i << '\n';
					found = true;
					break;
				}
			}
			if (!found)
				std::cout << -1 << '\n';
		}
	}
}
