//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void printHex(int num);
int isValidDecimal(const char* str);
void convertAndPrintHex(const char* decimalStr);

// Main Function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    convertAndPrintHex(argv[1]);
    return EXIT_SUCCESS;
}

// Print Hexadecimal Representation
void printHex(int num) {
    printf("Hexadecimal: %X\n", num);
}

// Validate if the input string is a valid decimal number
int isValidDecimal(const char* str) {
    // Check for empty string
    if (str == NULL || *str == '\0') {
        return 0;
    }

    // Loop through each character in the string
    for (size_t i = 0; str[i] != '\0'; ++i) {
        // If a character is not a digit, return false
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

// Convert and Print Hexadecimal
void convertAndPrintHex(const char* decimalStr) {
    if (!isValidDecimal(decimalStr)) {
        printf("Error: Invalid decimal number '%s'.\n", decimalStr);
        return;
    }

    // Convert string to integer
    int decimalNum = atoi(decimalStr);
    
    // Both print and validation mechanics here
    if (decimalNum < 0) {
        printf("Error: Negative numbers are not supported.\n");
        return;
    }

    printf("Decimal: %d\n", decimalNum);
    printHex(decimalNum);
}