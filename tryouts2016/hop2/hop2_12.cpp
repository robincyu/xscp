#include <ios>
#include <iostream>
#include <algorithm>

int arr[100005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, q, a, b;
	std::cin >> n >> q;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	while (q--)
	{
		std::cin >> a >> b;
		a--;
		std::cout << std::min(a+arr[a], n-1)-std::max(a-arr[a], 0) << '\n';
	}
}
