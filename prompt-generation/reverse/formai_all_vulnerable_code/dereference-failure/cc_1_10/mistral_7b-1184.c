//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void hex_to_bin(unsigned char hex, char bin[3]) {
    int dec = hex >> 4;
    int rem = hex & 0xF;

    if (dec > 0) {
        bin[0] = dec + '0';
        dec = hex & 0xF;
    } else {
        bin[0] = '0';
    }

    bin[1] = rem + '0';
}

void print_binary(char bin[3]) {
    if (bin[0] != '0' && bin[1] != '0')
        printf(" %s", bin);
}

void convert_hex_to_binary(char hex[MAX_LENGTH]) {
    int i, j = 0;
    char bin[MAX_LENGTH * 3];
    unsigned char byte;

    for (i = 0; i < strlen(hex) && i < MAX_LENGTH; i += 2) {
        sscanf(&hex[i], "%2hhx", &byte);
        hex_to_bin(byte, &bin[j]);
        j += 3;
        print_binary(bin + j - 3);
    }

    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage : %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
        argv[1][i] = toupper(argv[1][i]);

    convert_hex_to_binary(argv[1]);
    return 0;
}