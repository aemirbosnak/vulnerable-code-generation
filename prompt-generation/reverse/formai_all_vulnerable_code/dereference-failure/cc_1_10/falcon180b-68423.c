//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to convert hexadecimal to decimal
int hexToDec(char hex[MAX_INPUT_SIZE]) {
    int dec = 0;
    int len = strlen(hex);
    int i = 0;

    // Loop through each character in the hexadecimal string
    while (i < len) {
        char c = tolower(hex[i]);
        if (c >= '0' && c <= '9') {
            dec = dec * 16 + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            dec = dec * 16 + c - 'a' + 10;
        } else {
            printf("Invalid character '%c' in hexadecimal string.\n", c);
            return -1;
        }
        i++;
    }

    return dec;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[MAX_INPUT_SIZE]) {
    int len = 0;
    char hexDigit[MAX_INPUT_SIZE];

    // Loop until we have a valid hexadecimal string
    do {
        // Convert decimal to hexadecimal
        sprintf(hexDigit, "%x", dec);
        // Reverse the hexadecimal string
        for (int i = strlen(hexDigit) - 1; i >= 0; i--) {
            strcat(hex, hexDigit[i]);
        }
        // Remove leading zeros
        len = strlen(hex);
        while (len > 0 && hex[len - 1] == '0') {
            hex[--len] = '\0';
        }
        len++;
    } while (len == 0);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char hex[MAX_INPUT_SIZE];
    int dec;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Convert hexadecimal to decimal
    dec = hexToDec(input);

    // Convert decimal to hexadecimal
    decToHex(dec, hex);

    // Print results
    printf("Hexadecimal: %s\n", input);
    printf("Decimal: %d\n", dec);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}