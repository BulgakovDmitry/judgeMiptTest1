#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int total = 0;
    int length = strlen(s);
    int values[length];

    for (int i = 0; i < length; i++) {
        switch(s[i]) {
            case 'I': values[i] = 1; break;
            case 'V': values[i] = 5; break;
            case 'X': values[i] = 10; break;
            case 'L': values[i] = 50; break;
            case 'C': values[i] = 100; break;
            case 'D': values[i] = 500; break;
            case 'M': values[i] = 1000; break;
            default: return -1; 
        }
    }

    for (int i = 0; i < length; i++) {
        if (i + 1 < length && values[i] < values[i + 1]) {
            total += values[i + 1] - values[i];
            i++;
        } else {
            total += values[i];
        }
    }

    return total;
}

int main() {
    char romanNumber[20];
    scanf("%s", romanNumber);

    int arabicNumber = romanToInt(romanNumber);
    printf("%d\n", arabicNumber);
    return 0;
}