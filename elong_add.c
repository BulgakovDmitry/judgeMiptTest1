#include <stdio.h>

#define N 100

struct _Decimal {
    char a[N];
    unsigned int n;
};
typedef struct _Decimal Decimal;

Decimal zero = {{0}, 0};

Decimal add(Decimal a, Decimal b) {
    Decimal result = zero;
    int carry = 0;
    int max_n = a.n > b.n ? a.n : b.n;

    for (unsigned int i = 0; i <= max_n; i++) {
        int sum = carry;
        if (i <= a.n) {
            sum += a.a[i];
        }
        if (i <= b.n) {
            sum += b.a[i];
        }
        result.a[i] = sum % 10;
        carry = sum / 10;
    }

    result.n = max_n;
    if (carry > 0) {
        result.a[max_n + 1] = carry;
        result.n++;
    }

    return result;
}

void print_decimal(Decimal d) {
    for (int i = d.n; i >= 0; i--) {
        printf("%d", d.a[i]);
    }
}

int main() {
    Decimal a = {{7, 4, 1}, 2};
    Decimal b = {{3, 1}, 1};
    Decimal res;

    res = add(a, b);
    print_decimal(res);
    printf("\n");

    return 0;
}