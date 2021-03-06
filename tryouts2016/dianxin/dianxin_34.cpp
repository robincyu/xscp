#include <ios>
#include <iostream>
#define MOD 1000000007

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m, q, a, b, c, d;
	long long int ans;
	std::cin >> n >> m >> q;
	while (q--)
	{
		std::cin >> a >> b >> c >> d;
		ans = 0;
		for (int i = a; i <= b; i++)
			for (int j = c; j <= d; j++)
				ans += i*j;
		std::cout << ans%MOD << '\n';
	}
}
