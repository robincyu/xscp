#include <stdio.h>

long long int arr[200005];
long long int pre[200005];

int main()
{
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    pre[0] = arr[0];
    pre[1] = arr[1];
    for (int i = 2; i < n; i++)
        pre[i] = pre[i-2] + arr[i];
    while (m--)
    {
        scanf("%d%d", &l, &r);
        l--; r--;
        if (l < 2)
            printf("%lld\n", pre[r]);
        else
            printf("%lld\n", pre[r] - pre[l-2]);
    }
}
