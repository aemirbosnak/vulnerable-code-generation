//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

void print_hex(unsigned char hex) {
    if (hex >= 0 && hex <= 9) {
        printf("%d", hex);
    } else {
        printf("%c", hex + 55);
    }
}

void hex_string_to_binary(char *hex_string, unsigned char *binary) {
    int i, j, length;
    length = strlen(hex_string);

    for (i = 0, j = 0; i < length; i += 2, j += 4) {
        unsigned char nibble_1 = hex_string[i] < 'A' ? (hex_string[i] - '0') : (hex_string[i] - 'A' + 10);
        unsigned char nibble_2 = hex_string[i + 1] < 'A' ? (hex_string[i + 1] - '0') : (hex_string[i + 1] - 'A' + 10);

        binary[j] = nibble_1 << 4;
        binary[j] |= nibble_2;
    }
}

void print_binary(unsigned char binary[]) {
    int i;

    printf("Binary: ");

    for (i = 7; i >= 0; i--) {
        print_hex(binary[i / 8] >> (7 - i % 8) & 0x01);
    }

    printf("\n");
}

int main() {
    char input_hex[MAX_INPUT_LENGTH];
    unsigned char binary[MAX_INPUT_LENGTH / 8 + 1];

    printf("Enter a hexadecimal string: ");
    fgets(input_hex, MAX_INPUT_LENGTH, stdin);
    input_hex[strcspn(input_hex, "\n")] = '\0';

    hex_string_to_binary(input_hex, binary);
    print_binary(binary);

    return 0;
}