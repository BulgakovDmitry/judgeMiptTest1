#include <stdio.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    long long max_num = x * x * x - 1;
    long long min_num = x * x;
    long long result = 0;

    for (long long num = max_num; num >= min_num; num--)
    {
        long long sq = num * num;
        if (sq % (max_num + 1) == num)
        {
            result = num;
            break;
        }
    }
    printf("%lld", result);

    return 0;
}