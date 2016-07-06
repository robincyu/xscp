#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void karatsuba(long long int *res, const long long int *p, const long long int *q, int sz)
{
	long long int tmp_0[sz];
	long long int tmp_1[sz];
	long long int r[sz << 1];
	
	for (int i = 0; i < 2*sz; i++)
		r[i] = 0;
	if (sz <= 4)
	{
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				r[i+j] += p[i]*q[j];
	}
	else
	{
		int sz_half = sz/2;
		for (int i = 0; i < sz_half; i++)
		{
			tmp_0[i] = p[i] + p[sz_half + i];
			tmp_1[i] = q[i] + q[sz_half + i];
			tmp_0[i + sz_half] = 0;
			tmp_1[i + sz_half] = 0;
		}
		karatsuba(r + sz_half, tmp_0, tmp_1, sz_half);
		karatsuba(tmp_0, p, q, sz_half);
		karatsuba(tmp_1, p+sz_half, q+sz_half, sz_half);
		for (int i = 0; i < sz; i++)
		{
			r[i] += tmp_0[i];
			r[i + sz_half] -= tmp_0[i] + tmp_1[i];
			r[i + sz] += tmp_1[i];
		}
	}
    
    for (int i = 0; i < 2*sz; i++)
    	res[i] = r[i];
}

void fast_polymult(long long int *r, long long int *p, long long int *q, int sz)
{
	if (sz & (sz - 1))
	{
		int k = 1;
		while (k < sz)
			k *= 2;
		while (sz+1 <= k)
		{
			p[sz] = 0;
			q[sz] = 0;
			sz++;
		}
	}
	karatsuba(r, p, q, sz);
}

long long int cnt1[66000] = {};
long long int cnt2[66000] = {};
long long int ans[66000] = {};
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
			}
			else
			{
				std::cin >> x >> y;
				v2.push_back(std::make_pair(x, 0));
				v2.push_back(std::make_pair(y+1, 1));
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
		
		fast_polymult(ans, cnt1, cnt2, r+1);
		
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
