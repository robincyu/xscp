#include <ios>
#include <iostream>
#define MOD 1000000007

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m, q;
	long long int a, b, c, d, s1, s2;
	std::cin >> n >> m >> q;
	while (q--)
	{
		std::cin >> a >> b >> c >> d;
		s1 = (a+b)*(b-a+1)/2;
		s2 = (c+d)*(d-c+1)/2;
		std::cout << (s1%MOD)*(s2%MOD)%MOD << '\n';
	}
}
