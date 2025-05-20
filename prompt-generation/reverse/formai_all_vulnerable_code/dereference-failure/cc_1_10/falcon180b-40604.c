//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_CHARS "0123456789ABCDEF"

int main(void) {
    char *input_str;
    char *output_str;
    char hex_char;
    int input_len, output_len;
    int i, j;

    printf("Enter a string to convert to hexadecimal: ");
    fgets(input_str, 100, stdin);
    input_len = strlen(input_str);

    output_len = input_len * 2;
    output_str = malloc(output_len + 1);
    if (output_str == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0, j = 0; i < input_len; i++) {
        if (isprint(input_str[i])) {
            output_str[j++] = input_str[i];
        } else {
            printf("Invalid character '%c' encountered.\n", input_str[i]);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < output_len; i += 2) {
        hex_char = (int)output_str[i] & 0x7F;
        if (isprint(hex_char)) {
            printf("%c", hex_char);
        } else {
            printf(".");
        }
        hex_char = (int)output_str[i + 1] & 0x7F;
        if (isprint(hex_char)) {
            printf("%c", hex_char);
        } else {
            printf(". ");
        }
    }

    printf("\n");
    free(output_str);
    return 0;
}