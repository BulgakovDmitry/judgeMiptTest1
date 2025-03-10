#include <stdio.h>
#include <string.h>

#define MAX_LEN_OF_BIN_NUM 1000

void add(const char* num1, const char* num2, char* sumNum) 
{
    int lenNum1 = strlen(num1);
    int lenNum2 = strlen(num2);

    int maxLen = 0;
    if (lenNum1 > lenNum2)
        maxLen = lenNum1;
    else
        maxLen = lenNum2;

    int f = 0;
    int i = lenNum1 - 1, j = lenNum2 - 1, k = maxLen;

    sumNum[k + 1] = '\0';

    while (i >= 0 || j >= 0 || f) 
    {
        int binNum1 = i >= 0 ? num1[i--] - '0' : 0;
        int binNum2 = j >= 0 ? num2[j--] - '0' : 0;
        int sum = binNum1 + binNum2 + f;
        sumNum[k--] = (sum % 2) + '0';
        f = sum / 2;
    }

    while (sumNum[0] == '0' && sumNum[1] != '\0') 
        sumNum++;


    int checkingOnNull = 0;
    size_t lenSumNum = strlen(sumNum);

    if (sumNum[0] != '1')
        sumNum++;

    for (int q = 0; q < lenSumNum; q++)
    {
        if (sumNum[q] != '0')
        {
            printf("sumNum[q] = %c\n", sumNum[q]);
            checkingOnNull++;
        }
    } 
    printf("checkingOnNull = %d\n", checkingOnNull);

    
        printf("%s\n", sumNum + 1);
    else
        printf("%s\n", sumNum);
}

int main() 
{
    char firstBinNum[MAX_LEN_OF_BIN_NUM + 1];
    char secondBinNum[MAX_LEN_OF_BIN_NUM + 1];
    char sumBinNum[MAX_LEN_OF_BIN_NUM + 2];

    scanf("%s", firstBinNum);
    scanf("%s", secondBinNum);

    add(firstBinNum, secondBinNum, sumBinNum);

    return 0;
}