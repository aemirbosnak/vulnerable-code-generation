//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void hex_string_to_binary(char hex[], unsigned char binary[16]) {
    int i;
    for (i = 0; i < 16; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            binary[i / 2] <<= 4;
            binary[i / 2] |= (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            binary[i / 2] <<= 4;
            binary[i / 2] |= (hex[i] - 'A' + 10);
        }
    }
}

void binary_to_decimal(unsigned char binary[16], int decimal[4]) {
    int i, j, temp;
    for (i = 0, j = 0; i < 4; i++) {
        temp = 0;
        for (int bit = 0; bit < 4; bit++) {
            temp = (temp << 1) | binary[j++];
        }
        decimal[i] = temp;
    }
}

void print_decimal(int decimal[4]) {
    for (int i = 3; i >= 0; i--) {
        printf("%d", decimal[i]);
        if (i != 0)
            printf(" ");
    }
    printf(" : ");
    for (int i = 15; i >= 0; i--) {
        printf("%02X", (unsigned char)(decimal[3] >> (8 * (3 - i)) & 0xFF));
        if (i != 0)
            printf(" ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage : %s <hexadecimal string>\n", argv[0]);
        exit(1);
    }

    unsigned char binary[16];
    char hex[33] = {0};
    strcpy(hex, argv[1]);

    // remove leading 0x if present
    if (hex[0] == '0' && hex[1] == 'x') {
        memmove(hex, hex + 2, strlen(hex + 2));
    }

    hex_string_to_binary(hex, binary);

    int decimal[4];
    binary_to_decimal(binary, decimal);

    print_decimal(decimal);

    return 0;
}