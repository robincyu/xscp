#include <ios>
#include <iostream>
#include <algorithm>
#define MOD 1000000007

int cul[145][100005] = {};
int arr[100005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, q, a, b;
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];
	for (int k = 0; k <= 140; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (k == 0)
				cul[k][i] = 1;
			else
			{
				int x = (cul[k-1][std::min(n, i+arr[i])] - cul[k-1][std::max(1, i-arr[i])-1] + MOD)%MOD;
				int y = (cul[k-1][i] - cul[k-1][i-1] + MOD)%MOD;
				
				if (x < y)
					cul[k][i] = x-y+MOD;
				else
					cul[k][i] = x-y;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cul[k][i] += cul[k][i-1];
			if (cul[k][i] >= MOD)
				cul[k][i] -= MOD;
		}
	}
	while (q--)
	{
		std::cin >> a >> b;
		std::cout << (cul[b][a] - cul[b][a-1] + MOD)%MOD << '\n';
	}
}
