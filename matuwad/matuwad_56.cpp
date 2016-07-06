#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 2000000000

std::vector<std::vector<std::pair<int, int> > > adjlist;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
int mindist[2005][2005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int tc, s, v, e, q, a, b, w;
	std::cin >> tc;
	while (tc--)
	{
		std::cin >> v >> e >> q;
		adjlist.clear();
		adjlist.resize(v+5);
		s = 0;
		while (e--)
		{
			std::cin >> a >> b >> w;
			a--; b--;
			adjlist[a].push_back(std::make_pair(b, w));
			adjlist[b].push_back(std::make_pair(a, w));
		}
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < v; j++)
				mindist[i][j] = INF;
			mindist[i][i] = 0;
			
			pq.push(std::make_pair(0, i));
			while (!pq.empty())
			{
				int dist = pq.top().first;
				int vert = pq.top().second;
				pq.pop();
				for (std::vector<std::pair<int, int> >::iterator it = adjlist[vert].begin(); it != adjlist[vert].end(); it++)
				{
					if (std::max(it->second, dist) < mindist[i][it->first])
					{
						mindist[i][it->first] = std::max(it->second, dist);
						pq.push(std::make_pair(std::max(it->second, dist), it->first));
					}
				}
			}
		}
		for (int i = 0; i < q; i++)
		{
			std::cin >> a >> b;
			a = (a + s)%v;
			b = (b + s)%v;
			if (mindist[a][b] != INF)
			{
				std::cout << mindist[a][b] << '\n';
				s += mindist[a][b];
				s %= v;
			}
			else
				std::cout << "cheatr\n";
		}
	}
}
