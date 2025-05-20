//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

void print_hex_bytes(const unsigned char *bytes, size_t length) {
    size_t i;
    for (i = 0; i < length; i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    unsigned char hex_digits[33] = {0};
    int base, i, j;
    size_t hex_length = 0;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    for (i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            hex_digits[hex_length++] = input[i] - '0';
        } else if (isalpha(input[i]) && isupper(input[i])) {
            hex_digits[hex_length++] = input[i] - 'A' + 10;
        } else if (isalpha(input[i]) && islower(input[i])) {
            hex_digits[hex_length++] = input[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character '%c' in string.\n", input[i]);
            return 1;
        }
    }

    if (hex_length % 2 != 0) {
        printf("Hexadecimal string must have an even number of digits.\n");
        return 1;
    }

    base = hex_length / 2;
    unsigned char *output = (unsigned char *)calloc(base, sizeof(unsigned char));

    for (i = 0, j = 0; i < base; i++) {
        output[i] = (hex_digits[j] << 4) | hex_digits[j+1];
        j += 2;
    }

    print_hex_bytes(output, base);

    free(output);

    return 0;
}