#include <stdio.h>
#include <string.h>

#define MAX_LEN 1001

void balancedTernaryAddition(char *a, char *b, char *result) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    int carry = 0;
    int index = 0;

    char paddedA[MAX_LEN] = {0};
    char paddedB[MAX_LEN] = {0};
    for (int i = 0; i < maxLen - lenA; i++) paddedA[i] = '0';
    for (int i = 0; i < maxLen - lenB; i++) paddedB[i] = '0';
    strcat(paddedA, a);
    strcat(paddedB, b);

    for (int i = maxLen - 1; i >= 0; i--) {
        int digitA = paddedA[i] == '$' ? -1 : paddedA[i] - '0';
        int digitB = paddedB[i] == '$' ? -1 : paddedB[i] - '0';
        int sum = digitA + digitB + carry;

        if (sum < -1) {
            result[index++] = '$';
            carry = -1;
        } else if (sum == -1) {
            result[index++] = '$';
            carry = 0;
        } else if (sum == 0) {
            result[index++] = '0';
            carry = 0;
        } else if (sum == 1) {
            result[index++] = '1';
            carry = 0;
        } else if (sum == 2) {
            result[index++] = '$';
            carry = 1;
        } else if (sum == 3) {
            result[index++] = '0';
            carry = 1;
        }
    }

    if (carry == -1) {
        result[index++] = '$';
    } else if (carry == 1) {
        result[index++] = '1';
    }

    result[index] = '\0';
    int start = index - 1;
    while (start >= 0 && result[start] == '0') {
        result[start] = '\0';
        start--;
    }

    for (int i = 0; i < (index / 2); i++) {
        char temp = result[i];
        result[i] = result[index - 1 - i];
        result[index - 1 - i] = temp;
    }
}

int main() {
    char a[MAX_LEN], b[MAX_LEN], result[MAX_LEN * 2] = {0};
    scanf("%s", a);
    scanf("%s", b);

    balancedTernaryAddition(a, b, result);

    printf("%s\n", result);

    return 0;
}