#include <ios>
#include <iostream>

long long int arr[200005] = {};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, m, l, r;
	long long int sum;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	while (m--)
	{
		std::cin >> l >> r;
		l--; r--;
		sum = 0;
		for (int i = l; i <= r; i+=2)
			sum += arr[i];
		std::cout << sum << '\n';
	}
}
