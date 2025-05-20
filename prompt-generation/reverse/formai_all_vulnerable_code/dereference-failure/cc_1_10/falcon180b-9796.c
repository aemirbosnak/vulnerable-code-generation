//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LEN 32

int main(int argc, char *argv[]) {
    char input[MAX_HEX_LEN];
    char hex_output[MAX_HEX_LEN * 2 + 1];
    int i = 0;
    int hex_index = 0;
    int decimal_value = 0;
    int input_len = strlen(argv[1]);
    int hex_output_len = 0;

    if (input_len == 0) {
        printf("Error: input is empty\n");
        return -1;
    }

    if (input_len > MAX_HEX_LEN) {
        printf("Error: input is too long\n");
        return -1;
    }

    strcpy(input, argv[1]);

    for (i = 0; i < input_len; i++) {
        if (!isxdigit(input[i])) {
            printf("Error: input contains non-hexadecimal characters\n");
            return -1;
        }
    }

    for (i = 0; i < input_len; i++) {
        if (isdigit(input[i])) {
            decimal_value = decimal_value * 16 + input[i] - '0';
        } else {
            decimal_value = decimal_value * 16 + tolower(input[i]) - 'a' + 10;
        }
    }

    hex_output[hex_index++] = '0';
    hex_output[hex_index++] = 'x';

    while (decimal_value > 0) {
        char hex_char = (char) ('0' + (decimal_value & 0xF));
        hex_output[hex_index++] = hex_char;
        decimal_value >>= 4;
    }

    if (hex_index == 0) {
        printf("Error: input is not a valid hexadecimal number\n");
        return -1;
    }

    hex_output[hex_index] = '\0';
    printf("Hexadecimal representation: %s\n", hex_output);

    return 0;
}