//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert hexadecimal string to binary
char* hexToBin(char* hex) {
    int len = strlen(hex);
    char* bin = (char*) calloc(len * 4 + 1, sizeof(char));
    int i, j;

    for (i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            bin[i * 4] = '0' + (hex[i] - '0') << 4;
            bin[i * 4 + 1] = '0' + (hex[i] - '0') << 2;
            bin[i * 4 + 2] = '0' + (hex[i] - '0') << 0;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            bin[i * 4] = '0' + ((hex[i] - 'A' + 10) << 4);
            bin[i * 4 + 1] = '0' + ((hex[i] - 'A' + 10) << 2);
            bin[i * 4 + 2] = '0' + ((hex[i] - 'A' + 10) << 0);
        }
    }

    for (i = len * 4, j = 0; i-- > 0; j++)
        bin[j] = (bin[i] != 0) ? '1' : '0';

    bin[len * 4 + 1] = '\0';
    return bin;
}

// Function to print binary number
void printBin(char* bin) {
    int i = 0;

    while (bin[i] != '\0') {
        printf("%c", bin[i]);
        i++;
    }
}

// Function to check if the given character is valid hexadecimal character
int isHex(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
        return 1;
    return 0;
}

// Function to convert hexadecimal string to binary and print it
void hexToBinPrint(char* hex) {
    char* bin = hexToBin(hex);

    printf("The binary representation of hexadecimal number '%s' is:\n", hex);
    printBin(bin);
    free(bin);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    // Check if all characters in the string are valid hexadecimal characters
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isHex(argv[1][i])) {
            printf("Error: Invalid hexadecimal character '%c'\n", argv[1][i]);
            return 1;
        }
    }

    hexToBinPrint(argv[1]);
    return 0;
}