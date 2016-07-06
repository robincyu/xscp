#include <ios>
#include <iostream>

int row[5005] = {};
int col[5005] = {};
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
            row[i] = 0;
        for (int i = 0; i < m; i++)
            col[i] = 0;
        for (int i = 0; i <= r; i++)
            cnt[i] = 0;
        for (int rt = 0; rt < r; rt++)
        {
            std::cin >> c >> x >> y;
            x--; y--;
            if (c == 'C')
            {
                for (int i = x; i <= y; i++)
                    col[i]++;
            }
            if (c == 'R')
            {
                for (int i = x; i <= y; i++)
                    row[i]++;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cnt[row[i]+col[j]]++;
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
