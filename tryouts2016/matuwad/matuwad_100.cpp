#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define INF 1000000001

int par[100005] = {};
int rnk[100005] = {};
int rep[100005] = {};
bool visit[100005] = {};

int level[100005] = {};
int parl[20][100005] = {};
int wl[20][100005] = {};

std::vector<std::vector<std::pair<int, int> > > adjtemp;
std::vector<std::vector<std::pair<int, int> > > adjlist;
std::vector<std::pair<int, std::pair<int, int> > > edgelist;
std::queue<int> bfs;

int find(int a)
{
	int x = par[a];
	while (x != par[x])
		x = par[x];
	return x;
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if (rnk[a] < rnk[b])
		par[a] = b;
	else if (rnk[a] > rnk[b])
		par[b] = a;
	else
	{
		par[a] = b;
		rnk[b]++;
	}
}

int compute_ans(int a, int b)
{
	if (a == b)
		return 0;
	else
	{
		int curr_max = 0;
		if (level[a] != level[b])
		{
			if (level[a] > level[b])
			{
				int temp_variable = a;
				a = b;
				b = temp_variable;
			}
			for (int j = 19; j >= 0; j--)
			{
				if (level[b] - (1 << j) >= level[a])
				{
					curr_max = std::max(curr_max, wl[j][b]);
					b = parl[j][b];
				}
			}
		}
		if (a == b)
			return curr_max;
		else
		{
			for (int j = 19; j >= 0; j--)
			{
				if (parl[j][a] != parl[j][b])
				{
					curr_max = std::max(curr_max, wl[j][a]);
					curr_max = std::max(curr_max, wl[j][b]);
					a = parl[j][a];
					b = parl[j][b];
				}
			}
			curr_max = std::max(curr_max, wl[0][a]);
			curr_max = std::max(curr_max, wl[0][b]);
			a = parl[0][a];
			b = parl[0][b];
			return curr_max;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int tc, n, m, q, a, b, w, ccs, s;
	std::cin >> tc;
	while (tc--)
	{
		std::cin >> n >> m >> q;
		adjlist.clear();
		adjlist.resize(n+5);
		adjtemp.clear();
		adjtemp.resize(n+5);
		edgelist.clear();
		ccs = 0;
		s = 0;
		for (int i = 0; i < n; i++)
		{
			visit[i] = false;
			par[i] = i;
			rnk[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			std::cin >> a >> b >> w;
			a--; b--;
			adjtemp[a].push_back(std::make_pair(b, w));
			adjtemp[b].push_back(std::make_pair(a, w));
			edgelist.push_back(std::make_pair(w, std::make_pair(a, b)));
		}
		for (int i = 0; i < n; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				bfs.push(i);
				while (!bfs.empty())
				{
					int x = bfs.front();
					bfs.pop();
					
					for (std::vector<std::pair<int, int> >::iterator it = adjtemp[x].begin(); it != adjtemp[x].end(); it++)
						if (!visit[it->first])
							visit[it->first] = true;
				}
				if (i != 0)
				{
					rep[ccs] = i;
					ccs++;
				}
			}
		}
		for (int i = 0; i < ccs; i++)
		{
			adjtemp[0].push_back(std::make_pair(rep[i], INF));
			adjtemp[rep[i]].push_back(std::make_pair(0, INF));
			edgelist.push_back(std::make_pair(INF, std::make_pair(0, rep[i])));
		}
		std::sort(edgelist.begin(), edgelist.end());
		for (std::vector<std::pair<int, std::pair<int, int> > >::iterator it = edgelist.begin(); it != edgelist.end(); it++)
		{
			int g = find(it->second.first);
			int h = find(it->second.second);
			if (g != h)
			{
				join(g, h);
				adjlist[it->second.first].push_back(std::make_pair(it->second.second, it->first));
				adjlist[it->second.second].push_back(std::make_pair(it->second.first, it->first));
			}
		}
		for (int i = 0; i < n; i++)
			parl[0][i] = -1;
		parl[0][0] = 0;
		wl[0][0] = INF;
		level[0] = 0;
		bfs.push(0);
		while (!bfs.empty())
		{
			int x = bfs.front();
			bfs.pop();
			for (std::vector<std::pair<int, int> >::iterator it = adjlist[x].begin(); it != adjlist[x].end(); it++)
			{
				if (parl[0][it->first] == -1)
				{
					parl[0][it->first] = x;
					wl[0][it->first] = it->second;
					level[it->first] = level[x]+1;
					bfs.push(it->first);
				}
			}
		}
		parl[0][0] = -1;
		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (parl[i-1][j] != -1)
				{
					parl[i][j] = parl[i-1][parl[i-1][j]];
					wl[i][j] = std::max(wl[i-1][j], wl[i-1][parl[i-1][j]]);
				}
				else
				{
					parl[i][j] = -1;
					wl[i][j] = INF;
				}
			}
		}
		while (q--)
		{
			std::cin >> a >> b;
			a = (a + s)%n;
			b = (b + s)%n;
			
			int ans = compute_ans(a, b);
			if (ans == INF)
				std::cout << "cheatr\n";
			else
			{
				std::cout << ans << '\n';
				s += ans;
				s %= n;
			}
		}
	}
}
