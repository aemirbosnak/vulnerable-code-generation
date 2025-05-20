//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define HEX_TO_BIN_LENGTH 2
#define MAX_HEX_STRING_LENGTH 16

void print_binary(char *binary) {
    int i;
    for (i = 0; i < strlen(binary); i++) {
        putchar(binary[i] == '0' ? '0' : '1');
    }
    putchar('\n');
}

int hex_char_to_decimal(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

void hex_string_to_binary(char *hex_string, char *binary) {
    int i = 0;
    int j = 0;
    int value;
    while (hex_string[i] != '\0') {
        value = hex_char_to_decimal(hex_string[i]) << 4;
        if (i + 1 < strlen(hex_string) && hex_char_to_decimal(hex_string[i + 1]) >= 0) {
            value += hex_char_to_decimal(hex_string[i + 1]);
            i++;
        }
        binary[j++] = value & 0x0F;
        binary[j++] = (value >> 4) & 0x0F;
        i++;
    }
}

int main(int argc, char *argv[]) {
    char input_hex[MAX_HEX_STRING_LENGTH];
    char output_binary[HEX_TO_BIN_LENGTH * strlen(input_hex)];

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    strcpy(input_hex, argv[1]);
    hex_string_to_binary(input_hex, output_binary);
    printf("The binary representation of the hexadecimal string \"%s\" is:\n", input_hex);
    print_binary(output_binary);

    return 0;
}