//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20

void printUsage() {
    printf("Usage: hex_converter <number|hex_string>\n");
    printf("This program converts numbers to hexadecimal and vice versa.\n");
    printf("If a number is provided, it is converted to hexadecimal.\n");
    printf("If a hexadecimal string is provided, it is converted to decimal.\n");
}

int isHex(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= '0' && str[i] <= '9') || 
               (str[i] >= 'a' && str[i] <= 'f') || 
               (str[i] >= 'A' && str[i] <= 'F'))) {
            return 0;
        }
    }
    return 1;
}

void convertNumberToHex(long long num) {
    printf("Decimal: %lld\n", num);
    printf("Hexadecimal: %llX\n", num);
}

void convertHexToNumber(const char *hex) {
    long long num;
    sscanf(hex, "%llx", &num);
    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %lld\n", num);
}

void readInput(char *buffer, size_t length) {
    printf("Enter a number or hexadecimal string: ");
    if (fgets(buffer, length, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH];

    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    // Copy the input parameter for further processing
    strncpy(input, argv[1], MAX_INPUT_LENGTH);

    // Check if the input is a hexadecimal string or a decimal number
    if (isHex(input)) {
        convertHexToNumber(input);
    } else {
        char *endptr;
        long long num = strtoll(input, &endptr, 10);
        if (*endptr == '\0') {
            convertNumberToHex(num);
        } else {
            printf("Invalid input provided. Please enter a valid number or hexadecimal string.\n");
            printUsage();
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}