//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX 100

void hex_to_bin(unsigned char hex, unsigned char *bin, int *bin_len) {
    int i;
    static unsigned char bin_map[16] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    *bin_len = 4;

    for (i = 0; i < 4; i++) {
        bin[3 - i] = bin_map[hex & 0xF];
        hex >>= 4;
    }
}

void print_bin(unsigned char *bin, int bin_len) {
    int i;

    for (i = bin_len; i--; )
        printf("%c", bin[i] ? '1' : '0');

    printf("\n");
}

int main() {
    unsigned char hex[MAX_HEX / 2 + 1], *bin, i;
    int hex_len, bin_len;

    printf("Enter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);
    hex_len = strlen(hex);

    // remove whitespaces and convert to uppercase
    for (i = 0; i < hex_len; i++) {
        if (isdigit(hex[i]))
            continue;

        if (!isalnum(hex[i])) {
            printf("Invalid hexadecimal number.\n");
            return 1;
        }

        hex[i] = toupper(hex[i]);
    }

    bin = malloc(4 * (hex_len / 2 + 1));

    for (i = 0; i < hex_len / 2; i++) {
        hex_to_bin(hex[i * 2 + 1], bin + i * 4, &bin_len);
        hex_to_bin(hex[i * 2], bin + i * 4 + 3, &bin_len);
    }

    printf("Binary equivalent:\n");
    for (i = 0; i < bin_len; i++)
        print_bin(bin + i, 4);

    free(bin);

    return 0;
}