#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char Tr[20];
    scanf("%s", Tr);

    int len = strlen(Tr);
    long long decimalNum = 0;

    for (int i = 0; i < len; i++) 
        decimalNum = decimalNum * 3 + (Tr[i] - '0');

    printf("%lld\n", decimalNum);

    return 0;
}