#include <ios>
#include <iostream>
#include <map>
#define MOD 1000000007

std::map<long long int, long long int> cnt;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int t, n, x;
	long long int s, s2;
	std::cin >> t;
	while (t--)
	{
		std::cin >> n;
		s = 0;
		s2 = 0;
		cnt.clear();
		for (int i = 0; i < n; i++)
		{
			std::cin >> x;
			if (cnt.find(x) == cnt.end())
				cnt.insert(std::make_pair(x, 1));
			else
				cnt[x]++;
			s += x;
			s %= MOD;
		}
		for (std::map<long long int, long long int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		{
			s2 += (it->second*it->second%MOD)*(it->first*it->first%MOD);
			s2 %= MOD;
		}
		std::cout << ((s*s-s2)%MOD+MOD)%MOD << '\n';
	}
}
