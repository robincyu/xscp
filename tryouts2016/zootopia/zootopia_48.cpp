#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int cnt1[100005] = {};
int cnt2[100005] = {};
long long int ans[100005] = {};
std::vector<std::pair<int, int> > v1;
std::vector<std::pair<int, int> > v2;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int tc, n, m, r, typ1, typ2, x, y, s, last, range;
	char temp;
	
	std::cin >> tc;
	while (tc--)
	{
		std::cin >> n >> m >> r;
		v1.clear();
		v2.clear();
		typ1 = 0;
		typ2 = 0;
		for (int i = 0; i <= r; i++)
		{
			cnt1[i] = 0;
			cnt2[i] = 0;
			ans[i] = 0;
		}
		for (int i = 0; i < r; i++)
		{
			std::cin >> temp;
			if (temp == 'C')
			{
				std::cin >> x >> y;
				v1.push_back(std::make_pair(x, 0));
				v1.push_back(std::make_pair(y+1, 1));
				typ1++;
			}
			else
			{
				std::cin >> x >> y;
				v2.push_back(std::make_pair(x, 0));
				v2.push_back(std::make_pair(y+1, 1));
				typ2++;
			}
		}
		std::sort(v1.begin(), v1.end());
		std::sort(v2.begin(), v2.end());
		last = 0;
		range = 0;
		s = 0;
		for (std::vector<std::pair<int, int> >::iterator it = v1.begin(); it != v1.end(); it++)
		{
			if (range > 0)
			{
				cnt1[range] += it->first - last;
				s += it->first - last;
			}
			last = it->first;
			if (it->second)
				range--;
			else
				range++;
		}
		cnt1[0] = m-s;
		
		last = 0;
		range = 0;
		s = 0;
		for (std::vector<std::pair<int, int> >::iterator it = v2.begin(); it != v2.end(); it++)
		{
			if (range > 0)
			{
				cnt2[range] += it->first - last;
				s += it->first - last;
			}
			last = it->first;
			if (it->second)
				range--;
			else
				range++;
		}
		cnt2[0] = n-s;
		
		for (int i = 0; i <= r; i++)
		{
			for (int j = 0; j <= r; j++)
			{
				if (i+j > r)
					break;
				ans[i+j] += ((long long int)(cnt1[i]))*cnt2[j];
			}
		}
		
		for (int i = r-1; i >= 0; i--)
			ans[i] += ans[i+1];
		for (int i = 0; i <= r; i++)
		{
			if (i != 0)
				std::cout << ' ';
			std::cout << ans[i];
		}
		std::cout << '\n';
	}
}
