#include <stdio.h>

#define N 100

struct _Decimal 
{
    char a[N];
    unsigned int n;
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

Decimal add(Decimal a, Decimal b) 
{
    Decimal result = {{0}, {0}};
    int max_n = a.n > b.n ? a.n : b.n;
    int mind = 0;

    for (int i = 0; i <= max_n || mind; i++) 
    {
        int sum = mind;
        if (i <= a.n) sum += a.a[i];
        if (i <= b.n) sum += b.a[i];
        result.a[i] = sum % 10;
        mind = sum / 10;

        result.n = i;
    }
    return result;
}

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define MANG    "\033[1;35m"
#define WHITE   "\033[1;37m"
#define GREEN   "\033[1;32m"
#define BLUE    "\033[1;34m"
#define CEAN    "\033[1;36m"
#define YELLOW  "\033[1;33m"
void print_decimal(Decimal d) 
{
    printf("%sRESULT: %s", MANG, RESET);
    printf("%s___%s", YELLOW, RESET);
    for (int i = d.n; i >= 0; i--) 
    {
        printf("%s%d%s", GREEN, d.a[i], RESET);
    }
    printf("%s___%s", YELLOW, RESET);

}

int main() 
{
    Decimal a = {{7, 4, 1}, 2};
    Decimal b = {{3, 1}, 1};
    Decimal res;

    res = add(a, b);
    print_decimal(res);
    printf("\n");

    return 0;
}