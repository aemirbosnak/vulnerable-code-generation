//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HEX_TABLE_SIZE 256

// Hexadecimal table
static char hex_table[HEX_TABLE_SIZE];

// Initialize hexadecimal table
static void init_hex_table() {
    int i;
    for (i = 0; i < HEX_TABLE_SIZE; i++) {
        if (isdigit(i))
            hex_table[i] = i + '0';
        else if (isalpha(i))
            hex_table[i] = i - 'A' + 10;
        else
            hex_table[i] = '?';
    }
}

// Convert hexadecimal string to binary
void hex_to_bin(const char *hex, char *bin, int *len) {
    int i, j, hex_len;

    init_hex_table();

    hex_len = strlen(hex);
    bin[*len++] = '0';
    bin[*len++] = '1';

    for (i = hex_len - 1, j = *len - 2; i >= 0; i--) {
        bin[*len++] = hex_table[hex[i]];
        if (i != 0) {
            for (int k = 0; k < 4; k++) {
                bin[*len++] = bin[*len - 1] ^ bin[*len - 2];
                bin[*len++] = bin[*len - 1];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    char hex[17] = "0XA1B2C3";
    char bin[1024] = {0};
    int len;

    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    strcpy(hex, argv[1]);

    hex_to_bin(hex, bin, &len);

    printf("Hexadecimal: %s\n", hex);
    printf("Binary: ");
    for (int i = len - 1; i >= 0; i--)
        putchar(bin[i]);
    putchar('\n');

    return 0;
}