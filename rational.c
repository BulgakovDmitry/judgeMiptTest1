#include <stdio.h>
#include <string.h>
#include <math.h>

double binaryToDouble(const char *binary) {
    double result = 0.0;
    int pointIndex = -1;
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        if (binary[i] == '.') {
            pointIndex = i;
            break;
        }
    }

    if (pointIndex == -1) {
        pointIndex = length;
    }

    for (int i = 0; i < pointIndex; i++) {
        if (binary[i] == '1') {
            result += pow(2, pointIndex - i - 1);
        }
    }

    for (int i = pointIndex + 1; i < length; i++) {
        if (binary[i] == '1') {
            result += pow(2, pointIndex - i);
        }
    }

    return result;
}

int main() {
    char binary[31];
    scanf("%30s", binary);

    double decimal = binaryToDouble(binary);
    printf("%.12f\n", decimal);

    return 0;
}