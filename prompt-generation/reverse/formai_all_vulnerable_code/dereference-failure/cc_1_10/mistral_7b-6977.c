//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

void hexToBin(char hex[], int *bin, int length) {
    int i, j, temp;
    for (i = 0; i < length; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            bin[i / 2] <<= 4;
            bin[i / 2] |= (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            bin[i / 2] <<= 4;
            temp = hex[i] - 'A' + 10;
            bin[i / 2] |= temp;
        }
    }
}

void binToHex(int bin[], char hex[], int length) {
    int i, j, temp;
    for (i = length - 1; i >= 0; i--) {
        temp = bin[i] >> 4;
        hex[i] = (temp > 9) ? (char)('A' + temp - 10) : (char)(bin[i] >> 4) + '0';
        temp = bin[i] & 0xF;
        hex[--i] = (temp > 9) ? (char)('A' + temp - 10) : (char)bin[i] & 0xF + '0';
    }
}

void printHex(char hex[]) {
    printf("The hexadecimal value is : ");
    for (int i = 0; hex[i]; i++)
        printf("%c", hex[i]);
    printf("\n");
}

void printBin(int bin[], int length) {
    printf("The binary value is : ");
    for (int i = length - 1; i >= 0; i--)
        printf("%d", bin[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage : %s <hexadecimal value> <output format (h/b)>\n", argv[0]);
        return -1;
    }

    char hex[MAX];
    int bin[MAX / 2];
    int length = strlen(argv[1]);

    strcpy(hex, argv[1]);

    if (argv[2][0] == 'h') {
        if (length % 2 != 0) {
            printf("Error! Hexadecimal value should be even.\n");
            return -1;
        }
        hexToBin(hex, bin, length / 2);
        printBin(bin, length / 2);
    } else if (argv[2][0] == 'b') {
        if (length % 2 == 0) {
            printf("Error! Binary value should be odd.\n");
            return -1;
        }
        int tempLength = length / 2;
        binToHex(bin, hex, tempLength);
        printHex(hex);
    } else {
        printf("Error! Invalid output format.\n");
        return -1;
    }

    return 0;
}

// We are not sorry for the lack of apologies, only for the zestless code.