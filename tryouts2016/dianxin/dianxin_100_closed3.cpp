#include <ios>
#include <iostream>
#define MOD 1000000007

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m, q;
	long long int a, b, c, d;
	std::cin >> n >> m >> q;
	while (q--)
	{
		std::cin >> a >> b >> c >> d;
		std::cout << (((a+b)*(b-a+1)%MOD)*((c+d)*(d-c+1)%MOD))%MOD*250000002%MOD << '\n';
	}
}
