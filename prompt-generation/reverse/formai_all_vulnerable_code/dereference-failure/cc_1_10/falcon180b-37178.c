//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Iterate through the binary string in reverse order
    for (int i = length - 1; i >= 0; i--) {
        // Check if the current character is a 1
        if (binary[i] == '1') {
            // Calculate the value of the current bit
            decimal += pow(2, power);
        }
        // Increment the power for the next bit
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
char* decimal_to_binary(int decimal) {
    char* binary = malloc(33 * sizeof(char));
    int quotient, remainder;

    // Initialize the binary string with leading zeros
    strcpy(binary, "00000000000000000000000000000000");

    // Iterate through the binary string in reverse order
    for (int i = 0; i < 32; i++) {
        // Divide the decimal number by 2
        quotient = decimal / 2;
        // Get the remainder of the division
        remainder = decimal % 2;
        // Replace the leading zero with the remainder
        if (remainder == 1) {
            binary[i] = '1';
        }
        // Update the decimal number for the next iteration
        decimal = quotient;
    }

    return binary;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <binary> <decimal>\n", argv[0]);
        return 1;
    }

    char* binary = argv[1];
    int decimal = binary_to_decimal(binary);
    char* binary_str = decimal_to_binary(decimal);

    printf("Binary: %s\n", binary);
    printf("Decimal: %d\n", decimal);
    printf("Binary (string): %s\n", binary_str);

    free(binary_str);

    return 0;
}