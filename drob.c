#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double parseDecimal(char *s) {
    double integerPart = 0, fractionalPart = 0;
    int i = 0;
    while (s[i] != '.' && s[i] != '\0') {
        integerPart = integerPart * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.') {
        i++;
        double divisor = 10;
        while (s[i] != '\0' && s[i] != '(') {
            fractionalPart += (s[i] - '0') / divisor;
            divisor *= 10;
            i++;
        }
        if (s[i] == '(') {
            i++;
            double periodicDivisor = divisor;
            while (s[i] != ')') {
                fractionalPart += (s[i] - '0') / periodicDivisor;
                periodicDivisor *= 10;
                i++;
            }
        }
    }
    return integerPart + fractionalPart;
}

void formatResult(double result) {
    if (result == (int)result) {
        printf("%d\n", (int)result);
    } else {
        printf("%.10g\n", result);
    }
}

int main() {
    char A[20], B[20];
    printf("Enter the first number: ");
    scanf("%s", A);
    printf("Enter the second number: ");
    scanf("%s", B);

    double a = parseDecimal(A);
    double b = parseDecimal(B);
    double sum = a + b;

    formatResult(sum);

    return 0;
}