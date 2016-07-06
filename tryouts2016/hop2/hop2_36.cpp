#include <ios>
#include <iostream>
#include <algorithm>

int dp[100005][145] = {};
int arr[100005] = {};
int n;

int f(int in, int s)
{
	if (s == 1)
		return std::min(in+arr[in], n-1)-std::max(in-arr[in], 0);
	int ans = 0;
	for (int i = std::max(in-arr[in], 0); i <= std::min(in+arr[in], n-1); i++)
		if (i != in)
			ans += f(i, s-1);
	return ans;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int q, a, b;
	std::cin >> n >> q;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 141; j++)
			dp[i][j] = -1;
	while (q--)
	{
		std::cin >> a >> b;
		std::cout << f(a-1, b) << '\n';
	}
}
