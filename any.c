#include <stdio.h>
#include <string.h>
#include <ctype.h>

int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
    if (c >= 'a' && c <= 'z') return 10 + c - 'a';
    return -1; 
}

char valueToChar(int v) {
    if (v >= 0 && v <= 9) return '0' + v;
    if (v >= 10 && v <= 35) return 'A' + v - 10;
    return '?'; 
}

long long toDecimal(char *number, int base) {
    long long result = 0;
    for (int i = 0; number[i] != '\0'; i++) {
        result = result * base + charToValue(number[i]);
    }
    return result;
}

void fromDecimal(long long number, int base, char *result) {
    int index = 0;
    if (number == 0) {
        result[index++] = '0';
    } else {
        while (number > 0) {
            result[index++] = valueToChar(number % base);
            number /= base;
        }
    }
    result[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }
}

int main() {
    int n, k;
    char A[100];
    char result[100];

    scanf("%d", &n);
    scanf("%s", A);
    scanf("%d", &k);

    long long decimal = toDecimal(A, n);

    fromDecimal(decimal, k, result);

    printf("%s\n", result);

    return 0;
}