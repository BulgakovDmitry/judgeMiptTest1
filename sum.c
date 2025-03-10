#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SYNTAX_ERROR(errorMessage, output)                                         \
    do                                                                             \
    {                                                                              \
        fprintf(output, "Syntax Error: file %s, line %d \n", __FILE__, __LINE__);  \
        fprintf(output, errorMessage "\nexit with 1 status\n");                    \
        exit(1);                                                                   \
    }                                                                              \
    while (0)

int main(int argc, char *argv[]) 
{
    if (argc != 2)
        SYNTAX_ERROR("expected <2>\n", stderr);

    char* endPtr;

    long long z = strtoll(argv[1], &endPtr, 27);

    if (*endPtr != '\0') 
        SYNTAX_ERROR("invalid argument\n", stderr);

    double x;
    int y;

    if (scanf("%lf %x", &x, &y) != 2) 
        SYNTAX_ERROR("invalid input\n", stderr);

    double sum = x + y + z;

    printf("%.3f\n", sum);

    #undef SYNTAX_ERROR
    return 0;
}
