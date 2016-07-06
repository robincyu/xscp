#include <ios>
#include <iostream>
#include <algorithm>
#define MOD 1000000007

int ftree[145][100005] = {};
int arr[100005] = {};
int n;

void add(int tree, int ind, int v)
{
	while (ind <= n)
	{
		ftree[tree][ind] += v;
		
		if (ftree[tree][ind] >= MOD)
			ftree[tree][ind] -= MOD;
		
		ind += (ind & -ind);
	}
}

int cul(int tree, int ind)
{
	int sum = 0;
	while (ind >= 1)
	{
		sum += ftree[tree][ind];
		ind -= (ind & -ind);
		
		if (sum >= MOD)
			sum -= MOD;
	}
	return sum;
}

int rsq(int tree, int a, int b)
{
	int l = cul(tree, a-1);
	int r = cul(tree, b);
	
	if (r-l < 0)
		return r-l+MOD;
	else
		return r-l;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int q, a, b;
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];
	for (int k = 0; k <= 140; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (k == 0)
				add(k, i, 1);
			else
			{
				int x = rsq(k-1, std::max(1, i-arr[i]), std::min(n, i+arr[i]));
				int y = rsq(k-1, i, i);
				
				if (x < y)
					add(k, i, x-y+MOD);
				else
					add(k, i, x-y);
			}
		}
	}
	while (q--)
	{
		std::cin >> a >> b;
		std::cout << rsq(b, a, a) << '\n';
	}
}
