//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char *binary;
    char *octal;
    char *hexadecimal;
} ConversionResult;

void convertBinaryToOctal(char *binary, char *octal) {
    int i = 0, j = 0;
    while (binary[i]) {
        if (binary[i] == '1') {
            octal[j++] = '1';
        } else {
            octal[j++] = '0';
        }
        i++;
    }
    octal[j] = '\0';
}

void convertBinaryToHexadecimal(char *binary, char *hexadecimal) {
    int i = 0, j = 0;
    while (binary[i]) {
        int decimal = binary[i] - '0';
        if (decimal < 10) {
            hexadecimal[j++] = '0' + decimal;
        } else {
            hexadecimal[j++] = 'A' + (decimal - 10);
        }
        i++;
    }
    hexadecimal[j] = '\0';
}

ConversionResult *convertBinary(char *binary) {
    ConversionResult *result = (ConversionResult *) malloc(sizeof(ConversionResult));
    char octal[MAX_LENGTH], hexadecimal[MAX_LENGTH];
    result->binary = strdup(binary);
    convertBinaryToOctal(binary, octal);
    result->octal = strdup(octal);
    convertBinaryToHexadecimal(binary, hexadecimal);
    result->hexadecimal = strdup(hexadecimal);
    return result;
}

void printConversionResult(ConversionResult *result) {
    printf("Binary: %s\n", result->binary);
    printf("Octal: %s\n", result->octal);
    printf("Hexadecimal: %s\n", result->hexadecimal);
}

int main() {
    char binary[MAX_LENGTH];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    ConversionResult *result = convertBinary(binary);
    printConversionResult(result);
    free(result->binary);
    free(result->octal);
    free(result->hexadecimal);
    free(result);
    return 0;
}