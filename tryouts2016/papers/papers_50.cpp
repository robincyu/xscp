#include <ios>
#include <iostream>
#define MOD 1000000007
#define BASE 29

bool subseq(std::string &a, std::string &b)
{
	int j = 0;
	for (int i = 0; i < a.length() && j < b.length(); i++)
		if (a.at(i) == b.at(j))
			j++;
	return (j == b.length());
}

bool sub(std::string &a, std::string &b)
{
	long long int hash = 0;
	long long int hash2 = 0;
	long long int powers = 1;
	for (int i = 0; i < b.length(); i++)
	{
		hash = hash * BASE + (b.at(i)-'A');
		hash %= MOD;
	}
	for (int i = 0; i < b.length(); i++)
	{
		powers *= BASE;
		powers %= MOD;
	}
	for (int i = 0; i < a.length(); i++)
	{
		hash2 = hash2 * BASE + (a.at(i)-'A');
		hash2 %= MOD;
		if (i >= b.length())
		{
			hash2 -= (powers*(a.at(i-b.length())-'A'))%MOD;
			if (hash2 < 0) hash2 += MOD;
		}
		if (i >= b.length()-1 && hash == hash2)
			return true;
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int tc, t, n, q;
	std::string k, a;
	std::cin >> tc;
	while (tc--)
	{
		std::cin >> n >> q;
		std::cin >> k;
		while (q--)
		{
			std::cin >> t >> a;
			if (sub(k, a))
				std::cout << "DETAINED\n";
			else if (subseq(k, a))
				std::cout << "DENIED\n";
			else
				std::cout << "APPROVED\n";
		}
	}
}
