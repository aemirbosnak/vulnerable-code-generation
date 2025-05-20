//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define HEX_STRING_SIZE 2

void convertToHex(unsigned int num, char* hexStr) {
    sprintf(hexStr, "%X", num);
}

void printHeader() {
    printf("====================================\n");
    printf("   Hexadecimal Converter Program     \n");
    printf("====================================\n");
    printf("Enter a decimal number to convert it to hexadecimal.\n");
    printf("Type 'exit' to quit the program.\n");
    printf("\n");
}

void printFooter() {
    printf("====================================\n");
    printf("  Thank you for using the converter! \n");
    printf("====================================\n");
}

int main() {
    printHeader();
    
    char input[MAX_INPUT_SIZE];
    unsigned int decimalNumber;
    char hexString[HEX_STRING_SIZE + 1]; // +1 for null terminator

    while (1) {
        printf("Enter a decimal number: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Convert to an integer and handle errors
        char* endPtr;
        decimalNumber = strtoul(input, &endPtr, 10);

        if (*endPtr != '\0') {
            printf("Error: That's not a valid decimal number.\n");
            continue;
        }
        
        convertToHex(decimalNumber, hexString);
        printf("Decimal: %u = Hexadecimal: %s\n", decimalNumber, hexString);
    }
    
    printFooter();
    return 0;
}