//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

// Function to convert decimal number to binary string
char *decimal_to_binary(unsigned long decimal) {
    static char binary[32] = {0};
    int i = 0;

    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Add leading zeros if necessary
    for (int j = 0; j < 32 - i; j++) {
        binary[31 - j] = '0';
    }

    binary[32] = '\0';
    return &binary[31];
}

// Function to convert binary string to decimal number
unsigned long binary_to_decimal(const char *binary) {
    unsigned long decimal = 0;
    int base = 1;

    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (isdigit(binary[i])) {
            decimal += (binary[i] - '0') * base;
            base *= 2;
        }
    }

    return decimal;
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_LENGTH] = {0};
    char output[MAX_OUTPUT_LENGTH] = {0};

    if (argc != 3) {
        printf("Usage: %s <decimal|binary> <number>\n", argv[0]);
        return 1;
    }

    // Convert input argument to binary or decimal based on the first character
    if (isdigit(argv[1][0])) {
        unsigned long decimal = strtoul(argv[1], NULL, 10);
        char *binary = decimal_to_binary(decimal);

        // Convert binary string to decimal number and store it in output
        unsigned long output_decimal = binary_to_decimal(binary);
        sprintf(output, "%lu\n", output_decimal);
    } else {
        strcpy(output, argv[1]);

        // Convert binary string to decimal number and then to textual representation
        unsigned long decimal = binary_to_decimal(argv[1]);
        char *binary = decimal_to_binary(decimal);

        sprintf(output, "%s (%lu)\n", argv[1], decimal);
        strcat(output, " = ");
        strcat(output, binary);
    }

    printf("%s\n", output);

    return 0;
}