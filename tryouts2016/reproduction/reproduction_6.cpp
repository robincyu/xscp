#include <ios>
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, k;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n >> k;
		if (n == 1)
			std::cout << -1 << '\n';
		else
			std::cout << n << '\n';
	}
}
