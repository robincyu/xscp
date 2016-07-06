#include <ios>
#include <iostream>

long long int arr[200005] = {};
long long int pre[200005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m, l, r;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	pre[0] = arr[0];
	pre[1] = arr[1];
	for (int i = 2; i < n; i++)
		pre[i] = pre[i-2] + arr[i];
	while (m--)
	{
		std::cin >> l >> r;
		l--; r--;
		if (l < 2)
			std::cout << pre[r] << '\n';
		else
			std::cout << pre[r] - pre[l-2] << '\n';
	}
}
