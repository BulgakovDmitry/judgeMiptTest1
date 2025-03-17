#include <stdio.h>

int can_place_certificates(long long side, long long W, long long H, long long N) 
{
    long long count_horizontal = side / W;
    long long count_vertical = side / H;
    long long total_count = count_horizontal * count_vertical;
    return total_count >= N;
}

long long find_min_side(long long W, long long H, long long N) 
{
    long long left = 1;
    long long right = (W > H ? W : H) * N;
    while (left < right)
    {
        long long mid = left + (right - left) / 2;
        if (can_place_certificates(mid, W, H, N)) 
            right = mid;
        else 
            left = mid + 1;
    }
    return left;
}

int main() 
{
    long long W, H, N;
    scanf("%lld %lld %lld", &W, &H, &N);
    printf("%lld\n", find_min_side(W, H, N));
    return 0;
}