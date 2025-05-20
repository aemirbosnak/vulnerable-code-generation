//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define HEX_CHAR_SIZE 2

void hex_string_to_bin(char hex_string[], unsigned char *bin_array) {
    int i, j;
    unsigned char bin[2];

    for (i = 0; i < strlen(hex_string) / HEX_CHAR_SIZE; i++) {
        sscanf(&hex_string[i * HEX_CHAR_SIZE], "%2hhx", &bin[0]);
        for (j = 0; j < 4; j++) {
            bin_array[i * 4 + j] = (bin[0] >> (j * 1)) & 0x01;
        }
    }
}

void bin_to_hex_string(unsigned char bin_array[], char hex_string[]) {
    int i, j;
    char hex_char;

    for (i = 0; i < sizeof(bin_array) / 4; i++) {
        hex_string[i * 2] = (bin_array[i] >> 4) & 0x0F;
        hex_string[i * 2 + 1] = bin_array[i] & 0x0F;
        if (hex_string[i * 2] > 9)
            hex_string[i * 2] += 0x20;
        if (hex_string[i * 2 + 1] > 9)
            hex_string[i * 2 + 1] += 0x20;
    }
    hex_string[sizeof(bin_array) / 4 * 2] = '\0';
}

void print_hex_string(char hex_string[]) {
    int i;

    for (i = 0; hex_string[i] != '\0'; i++) {
        if (isalnum(hex_string[i]))
            printf("%c", hex_string[i]);
        else
            printf("??");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char input_hex[MAX_INPUT_SIZE];
    unsigned char bin_array[MAX_INPUT_SIZE / 4];

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    strcpy(input_hex, argv[1]);

    hex_string_to_bin(input_hex, bin_array);
    bin_to_hex_string(bin_array, input_hex);

    printf("Original Hexadecimal: %s\n", argv[1]);
    printf("Binary: ");
    for (int i = 0; i < sizeof(bin_array) / 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%u", bin_array[i] >> (j * 1) & 0x01);
        printf(" ");
    }
    printf("\nConverted Hexadecimal: %s\n", input_hex);

    print_hex_string(input_hex);

    return 0;
}