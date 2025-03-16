#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *dig;  // массив для хранения числа
    int n;      // размер числа в разрядах
    char sign;  // знак числа (0 для положительных, 1 для отрицательных)
} LongN;

LongN getLongN(char *s) {
    LongN num;
    int len = strlen(s);
    int start = 0;

    if (s[0] == '-') {
        num.sign = 1;
        start = 1;
    } else if (s[0] == '+') {
        num.sign = 0;
        start = 1;
    } else {
        num.sign = 0;
    }

    while (start < len && s[start] == '0') {
        start++;
    }

    if (start == len) {
        num.dig = (char *)malloc(1 * sizeof(char));
        num.dig[0] = 0;
        num.n = 1;
        num.sign = 0;
        return num;
    }

    int digits = len - start;
    num.n = (digits + 1) / 2;

    num.dig = (char *)malloc(num.n * sizeof(char));

    for (int i = 0; i < num.n; i++) {
        int idx = len - 2 * (i + 1);
        if (idx < start) {
            num.dig[i] = s[start] - '0';
        } else {
            num.dig[i] = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
        }
    }

    return num;
}

void printLongN(LongN num) {
    if (num.sign == 1) {
        printf("-");
    }
    for (int i = num.n - 1; i >= 0; i--) {
        printf("%02d", num.dig[i]);
    }
    printf("\n");
}

int main() {
    char s[201];
    printf("Введите строку цифр: ");
    scanf("%s", s);

    LongN num = getLongN(s);
    printLongN(num);

    // Освобождаем память
    free(num.dig);

    return 0;
}