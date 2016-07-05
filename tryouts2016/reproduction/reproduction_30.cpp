#include <ios>
#include <iostream>

int pf[5005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, k;
	bool found;
	for (int i = 0; i < 5005; i++)
	{
		pf[i] = -1;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				pf[i] = j;
				break;
			}
		}
	}
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
		else if (k == 2)
		{
			if (pf[n] == -1)
				std::cout << -1 << '\n';
			else
				std::cout << pf[n] << ' ' << n/pf[n] << '\n';
		}
		else
		{
			found = false;
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0 && pf[i] != -1)
				{
					std::cout << pf[i] << ' ' << i/pf[i] << ' ' << n/i << '\n';
					found = true;
					break;
				}
			}
			if (!found)
				std::cout << -1 << '\n';
		}
	}
}
