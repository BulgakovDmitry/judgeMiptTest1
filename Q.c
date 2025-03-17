#include <stdio.h>

int toDecimal(int number, int base) {
    int decimal = 0;
    int power = 1;
    while (number > 0) {
        decimal += (number % 10) * power;
        number /= 10;
        power *= base;
    }
    return decimal;
}

int isAutomorphic(int number, int base) {
    long long square = (long long)number * number;
    int original = number;
    while (original > 0) {
        if (square % base != original % base) {
            return 0;
        }
        square /= base;
        original /= base;
    }
    return 1;
}

int main() {
    int x;
    scanf("%d", &x);

    int maxNumber = 0;

    for (int i = x * x; i < x * x * x; i++) {
        if (isAutomorphic(i, x)) {
            maxNumber = i;
        }
    }

    int decimalNumber = toDecimal(maxNumber, x);
    printf("%d\n", decimalNumber);

    return 0;
}