//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>

typedef struct {
    char binary[10];
    char hex[3];
    char dec[3];
} converter;

void binary_to_hex(char binary[8], char hex[4]) {
    int decimal = 0;
    for (int i = 0; i < 4; i++) {
        if (binary[i] == '0') {
            decimal += 0;
        } else if (binary[i] == '1') {
            decimal += 1 * (1 << (3 - i));
        } else {
            printf("Invalid binary digit %c at position %d\n", binary[i], i);
            exit(EXIT_FAILURE);
        }
    }
    sprintf(hex, "%x", decimal);
    if (hex[0] == '0' && hex[1] == 'x') {
        hex[0] = '0';
    }
}

void binary_to_decimal(char binary[8], char dec[3]) {
    int decimal = 0;
    for (int i = 0; i < 8; i++) {
        if (binary[i] == '0') {
            decimal += 0;
        } else if (binary[i] == '1') {
            decimal += 1 << (7 - i);
        } else {
            printf("Invalid binary digit %c at position %d\n", binary[i], i);
            exit(EXIT_FAILURE);
        }
    }
    sprintf(dec, "%d", decimal);
}

converter binary_input(char* binary_string) {
    converter binary_converter;
    strncpy(binary_converter.binary, binary_string, 10);

    binary_to_hex(binary_converter.binary, binary_converter.hex);
    binary_to_decimal(binary_converter.binary, binary_converter.dec);

    return binary_converter;
}

void print_converter(converter binary_converter) {
    printf("Binary: %s\n", binary_converter.binary);
    printf("Hex: %s\n", binary_converter.hex);
    printf("Decimal: %s\n", binary_converter.dec);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    converter binary_converter = binary_input(argv[1]);
    print_converter(binary_converter);

    return EXIT_SUCCESS;
}