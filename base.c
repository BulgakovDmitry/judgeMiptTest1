#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_DIGITS 11
#define MAX_BASE 36

int charToValue(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 10;
    return -1;
}

int toDecimal(char *num, int base) {
    int value = 0;
    for (int i = 0; num[i]; i++) {
        int digit = charToValue(num[i]);
        if (digit < 0 || digit >= base) return -1;
        value = value * base + digit;
    }
    return value;
}

int findBase(char *equation) {
    char *left = strtok(equation, "=");
    char *right = strtok(NULL, "=");
    char *op = strpbrk(left, "+*");

    if (!op) return -1;

    char *A = strtok(left, "+*");
    char *B = strtok(NULL, "+*");

    int a, b, c;
    for (int base = 2; base <= MAX_BASE; base++) {
        a = toDecimal(A, base);
        b = toDecimal(B, base);
        c = toDecimal(right, base);

        if (a == -1 || b == -1 || c == -1) continue;

        if (*op == '+' && a + b == c) return base;
        if (*op == '*' && a * b == c) return base;
    }

    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    int base = -1;
    for (int i = 0; i < N; i++) {
        char equation[100];
        fgets(equation, sizeof(equation), stdin);
        equation[strcspn(equation, "\n")] = 0;

        int currentBase = findBase(equation);
        if (currentBase == 0) {
            printf("0\n");
            return 0;
        }

        if (base == -1) {
            base = currentBase;
        } else if (base != currentBase) {
            printf("1\n");
            return 0;
        }
    }

    printf("%d\n", base);
    return 0;
}