#include <ios>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

std::queue<std::pair<int, int> > cur[26];
bool subsq[100005] = {};
bool subst[100005] = {};
std::string s[100005] = {};
int sortindex[100005][30] = {};
int sarray[100005] = {};
std::vector<std::pair<std::pair<int, int>, int> > sa;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string k;
	int tc, n, q, l, logn, times, pos, prev1, prev2, status, totalcount;
	std::cin >> tc;
	while (tc--)
	{
        totalcount = 0;
		std::cin >> n >> q;
		std::cin >> k;
        
		for (logn = 0; (1 << logn) < n; logn++);
		
		for (int i = 0; i < n; i++)
		{
			sortindex[i][0] = k.at(i)-'A';
			if (i != n-1) sa.push_back(std::make_pair(std::make_pair(k.at(i)-'A', k.at(i+1)-'A'), i));
			else sa.push_back(std::make_pair(std::make_pair(k.at(i)-'A', -1), i));
		}
		std::sort(sa.begin(), sa.end());
		
		times = 1;
		while (times <= logn)
		{
			pos = 0;
			for (std::vector<std::pair<std::pair<int, int>, int> >::iterator it = sa.begin(); it != sa.end(); it++)
			{
				if (it == sa.begin())
				{
					prev1 = it->first.first;
					prev2 = it->first.second;
					sortindex[it->second][times] = 0;
				}
				else
				{
					if (it->first.first == prev1 && it->first.second == prev2)
						sortindex[it->second][times] = pos;
					else
					{
						pos++;
						sortindex[it->second][times] = pos;
						prev1 = it->first.first;
						prev2 = it->first.second;
					}
				}
			}
			
			for (std::vector<std::pair<std::pair<int, int>, int> >::iterator it = sa.begin(); it != sa.end(); it++)
			{
				it->first.first = sortindex[it->second][times];
				it->first.second = ((it->second+(1 << times) < n) ? sortindex[it->second + (1 << times)][times] : -1);
			}
			
			std::sort(sa.begin(), sa.end());
			times++;
		}
		
		pos = 0;
		for (std::vector<std::pair<std::pair<int, int>, int> >::iterator it = sa.begin(); it != sa.end(); it++, pos++)
			sarray[pos] = it->second;
		
		for (int i = 0; i < q; i++)
		{
			std::cin >> l >> s[i];
            totalcount += l;
			int lo = 0;
			int hi = n-1;
			subst[i] = false;
			while (lo <= hi)
			{
				int mid = (lo+hi)/2;
				if (n-sarray[mid] >= l)
				{
					status = 0;
					for (int j = 0; j < l; j++)
					{
						if (k.at(sarray[mid]+j) < s[i].at(j))
						{
							status = 1;
							break;
						}
						if (k.at(sarray[mid]+j) > s[i].at(j))
						{
							status = 2;
							break;
						}
					}
				}
				else
				{
					status = 1;
					for (int j = 0; j < n-sarray[mid]; j++)
					{
						if (k.at(sarray[mid]+j) < s[i].at(j))
						{
							status = 1;
							break;
						}
						if (k.at(sarray[mid]+j) > s[i].at(j))
						{
							status = 2;
							break;
						}
					}
				}
				if (status == 0)
				{
					subst[i] = true;
					break;
				}
				else if (status == 1)
					lo = mid+1;
				else
					hi = mid-1;
			}
			cur[(s[i].at(0))-'A'].push(std::make_pair(i, 0));
			subsq[i] = false;
		}
		for (int i = 0; i < k.length(); i++)
		{
			int p = (k.at(i)-'A');
			for (int x = cur[p].size(); x; x--)
			{
				if (cur[p].front().second + 1 == s[cur[p].front().first].length())
				{
					subsq[cur[p].front().first] = true;
					cur[p].pop();
				}
				else
				{
					cur[s[cur[p].front().first].at(cur[p].front().second+1)-'A'].push(std::make_pair(cur[p].front().first, cur[p].front().second+1));
					cur[p].pop();
				}
			}
		}
		
		for (int i = 0; i < q; i++)
		{
			if (subst[i])
				std::cout << "DETAINED" << '\n';
			else if (subsq[i])
				std::cout << "DENIED" << '\n';
			else
				std::cout << "APPROVED" << '\n';
		}
		
		for (int i = 0; i < 26; i++)
			while (!cur[i].empty())
				cur[i].pop();
		sa.clear();
	}
}
