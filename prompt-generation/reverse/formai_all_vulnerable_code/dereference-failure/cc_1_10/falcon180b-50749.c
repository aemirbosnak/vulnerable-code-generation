//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of input line

typedef struct {
    char *hex; // Pointer to hexadecimal string
    char *bin; // Pointer to binary string
} ConversionResult;

ConversionResult convertToHex(char *input) {
    ConversionResult result;
    int i = 0;
    int j = 0;
    int inputLength = strlen(input);
    result.hex = malloc(inputLength * 3 + 1); // Allocate memory for hexadecimal string
    result.bin = malloc(inputLength * 8 + 1); // Allocate memory for binary string

    while (i < inputLength) {
        if (isxdigit(input[i])) { // If input character is hexadecimal
            result.hex[j++] = input[i]; // Add character to hexadecimal string
        } else {
            result.hex[j++] = '0'; // Add leading zero for non-hexadecimal input
        }
        if (i % 2 == 0 && isxdigit(input[i])) { // If input character is hexadecimal and even position
            result.bin[j / 2] = (input[i] - '0') << 4; // Add 4 bits to binary string
        } else {
            result.bin[j / 2] += (input[i] - '0'); // Add 1 bit to binary string
        }
        i++;
    }

    result.hex[j] = '\0'; // Add null terminator to hexadecimal string
    result.bin[j / 2] = '\0'; // Add null terminator to binary string

    return result;
}

void printConversionResult(ConversionResult result) {
    printf("Hexadecimal: %s\n", result.hex); // Print hexadecimal string
    printf("Binary:     %s\n", result.bin); // Print binary string
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter a string to convert to hexadecimal and binary: ");
    fgets(input, MAX_LINE_LENGTH, stdin); // Read input from user

    ConversionResult result = convertToHex(input); // Convert input string to hexadecimal and binary
    printConversionResult(result); // Print conversion result

    free(result.hex); // Free memory allocated for hexadecimal string
    free(result.bin); // Free memory allocated for binary string

    return 0;
}