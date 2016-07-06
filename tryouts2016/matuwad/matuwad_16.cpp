#include <ios>
#include <iostream>
#define INF 1000000001

int adjmat[2005][2005] = {};

int main()
{
	int tc, n, m, q, a, b, w, s;
	std::cin >> tc;
	while (tc--)
	{
		std::cin >> n >> m >> q;
		s = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				adjmat[i][j] = (i == j ? 0 : INF);
		while (m--)
		{
			std::cin >> a >> b >> w;
			a--; b--;
			adjmat[a][b] = w;
			adjmat[b][a] = w;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					adjmat[i][j] = std::min(adjmat[i][j], std::max(adjmat[i][k], adjmat[k][j]));
		while (q--)
		{
			std::cin >> a >> b;
			a = (a + s)%n;
			b = (b + s)%n;
			if (adjmat[a][b] == INF)
				std::cout << "cheatr\n";
			else
			{
				std::cout << adjmat[a][b] << '\n';
				s += adjmat[a][b];
				s %= n;
			}
		}
	}
}
