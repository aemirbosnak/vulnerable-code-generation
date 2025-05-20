//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 100

void to_hex(unsigned char *input, char *output, int length) {
    for (int i = 0; i < length; ++i) {
        unsigned char byte = input[i];
        char hex[3];

        hex[0] = "0123456789ABCDEF"[byte >> 4];
        hex[1] = "0123456789ABCDEF"[byte & 0xF];
        output[i * 2] = hex[0];
        output[i * 2 + 1] = hex[1];
    }
    output[length * 2] = '\0';
}

void to_decimal(char *input, int *output, int base, int length) {
    int sum = 0;
    int power = 0;

    for (int i = length - 1; i >= 0; --i) {
        int digit = isdigit(input[i]) ? input[i] - '0' : toupper(input[i]) - 'A' + 10;
        sum += digit * pow(base, power);
        power++;
    }

    *output = sum;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <hex_string> <output_number>\n", argv[0]);
        return 1;
    }

    char hex_string[BUF_SIZE];
    strncpy(hex_string, argv[1], BUF_SIZE);

    int number;
    to_decimal(hex_string, &number, 16, strlen(hex_string));

    printf("Decimal representation of the hexadecimal string \"%s\": %d\n", argv[1], number);

    char hex[strlen(argv[1]) * 2 + 1];
    to_hex((unsigned char *)argv[1], hex, strlen(argv[1]));

    printf("Hexadecimal representation of the decimal number %d: %s\n", number, hex);

    return 0;
}