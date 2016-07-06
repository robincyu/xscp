#include <ios>
#include <iostream>

bool subseq(std::string &a, std::string &b)
{
	int j = 0;
	for (int i = 0; i < a.length() && j < b.length(); i++)
		if (a.at(i) == b.at(j))
			j++;
	return (j == b.length());
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
			if (k.find(a) != std::string::npos)
				std::cout << "DETAINED\n";
			else if (subseq(k, a))
				std::cout << "DENIED\n";
			else
				std::cout << "APPROVED\n";
		}
	}
}
