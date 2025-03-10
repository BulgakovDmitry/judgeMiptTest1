#include <stdio.h>

void convert_hex_to_bin(const char *hex_input, char *binary_output) 
{
    const char binary_map[16][5] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };

    char *current_pos = binary_output;

    for (int index = 0; hex_input[index] != '\0'; index++) 
    {
        unsigned char hex_digit = hex_input[index];
        if (hex_digit >= '0' && hex_digit <= '9') 
            hex_digit -= '0'; 
        else if (hex_digit >= 'A' && hex_digit <= 'F') 
            hex_digit -= 'A' - 10; 
        else 
            continue; 

        for (int j = 0; j < 4; j++) 
            *current_pos++ = binary_map[hex_digit][j];
    }
    *current_pos = '\0';
}

int main() 
{
    char hex_input[1000001];
    char binary_output[4000001];

    scanf("%1000000s", hex_input);

    convert_hex_to_bin(hex_input, binary_output);

    char *trimmed_result = binary_output;
    while (*trimmed_result == '0') 
    {
        trimmed_result++;
    }

    if (*trimmed_result == '\0') 
    {
        trimmed_result = "0";
    }

    printf("%s\n", trimmed_result);

    return 0;
}
