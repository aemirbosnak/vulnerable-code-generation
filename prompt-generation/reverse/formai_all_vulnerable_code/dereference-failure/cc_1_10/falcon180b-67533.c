//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 32
#define HEX_CHARS "0123456789abcdef"

void hex_to_dec(char* hex, int* decimal) {
    int i = 0;
    int value = 0;
    while (i < strlen(hex)) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                value = value * 16 + hex[i] - '0';
            } else {
                value = value * 16 + hex[i] - 'a' + 10;
            }
        } else {
            printf("Invalid hexadecimal character found.\n");
            exit(1);
        }
        i++;
    }
    *decimal = value;
}

void dec_to_hex(int decimal, char* hex) {
    char buffer[MAX_HEX_LENGTH];
    int i = 0;
    int j = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            buffer[i++] = remainder + '0';
        } else {
            buffer[i++] = remainder + 'a' - 10;
        }
        decimal /= 16;
    }
    for (i = strlen(buffer) - 1; i >= 0; i--) {
        hex[j++] = buffer[i];
    }
    hex[j] = '\0';
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <hexadecimal_number>\n", argv[0]);
        return 1;
    }
    char input[MAX_HEX_LENGTH];
    strcpy(input, argv[1]);
    int decimal = 0;
    hex_to_dec(input, &decimal);
    char output[MAX_HEX_LENGTH];
    dec_to_hex(decimal, output);
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %s\n", output);
    return 0;
}