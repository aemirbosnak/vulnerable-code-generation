//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_HEX_VALUE 16

void convert_hex_to_binary(unsigned char hex_value, char binary[MAX_HEX_VALUE * 2 + 1]) {
    int i;
    for (i = MAX_HEX_VALUE * 2; i > 0; --i) {
        binary[i - 1] = "0123456789ABCDEF"[hex_value >> (i - 1) * 4 & 0x0F];
        hex_value <<= 4;
    }
    binary[MAX_HEX_VALUE * 2 + 1] = '\0';
}

void print_binary(char binary[MAX_HEX_VALUE * 2 + 1]) {
    int i;
    for (i = 0; i < MAX_HEX_VALUE * 2 + 1; ++i) {
        if (i > 0 && i % 4 == 0)
            printf("-");
        printf("%c", binary[i]);
    }
    printf("\n");
}

int hex_string_to_binary_array(char hex_string[MAX_INPUT_LENGTH], unsigned char binary_array[MAX_INPUT_LENGTH / 2 + 1]) {
    int i = 0, j = 0;
    unsigned char hex_value;

    for (; hex_string[i] != '\0'; ++i) {
        if (isxdigit(hex_string[i]) && (isdigit(hex_string[i]) || (hex_string[i] >= 'A' && hex_string[i] <= 'F'))) {
            if (sscanf(&hex_string[i], "%2hhx", &hex_value) != 1) {
                printf("Error: Invalid hexadecimal value at position %d: %c\n", i, hex_string[i]);
                return -1;
            }
            convert_hex_to_binary(hex_value, binary_array + j);
            j += MAX_HEX_VALUE;
        } else {
            printf("Error: Invalid character at position %d: %c\n", i, hex_string[i]);
            return -1;
        }
    }

    binary_array[MAX_INPUT_LENGTH / 2 + 1] = '\0';
    return 0;
}

int main() {
    char hex_string[MAX_INPUT_LENGTH];
    unsigned char binary_array[MAX_INPUT_LENGTH / 2 + 1];

    printf("Enter hexadecimal string: ");
    fgets(hex_string, MAX_INPUT_LENGTH, stdin);
    hex_string[strcspn(hex_string, "\n")] = '\0';

    if (hex_string_to_binary_array(hex_string, binary_array) == -1)
        return -1;

    printf("Binary representation of hexadecimal string:\n");
    print_binary(binary_array);

    return 0;
}