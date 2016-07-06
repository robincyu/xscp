#include <ios>
#include <iostream>

int grid[5005][5005] = {};
int cnt[5005] = {};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int tc, n, m, r, x, y;
    char c;
    std::cin >> tc;
    while (tc--)
    {
        std::cin >> n >> m >> r;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = 0;
        for (int i = 0; i <= r; i++)
            cnt[i] = 0;
        for (int rt = 0; rt < r; rt++)
        {
            std::cin >> c >> x >> y;
            x--; y--;
            if (c == 'C')
            {
                for (int i = 0; i < n; i++)
                    for (int j = x; j <= y; j++)
                        grid[i][j]++;
            }
            if (c == 'R')
            {
                for (int i = x; i <= y; i++)
                    for (int j = 0; j < m; j++)
                        grid[i][j]++;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt[grid[i][j]]++;
        for (int i = r-1; i >= 0; i--)
            cnt[i] += cnt[i+1];
        for (int i = 0; i <= r; i++)
        {
            if (i != 0)
                std::cout << ' ';
            std::cout << cnt[i];
        }
        std::cout << '\n';
    }
}
