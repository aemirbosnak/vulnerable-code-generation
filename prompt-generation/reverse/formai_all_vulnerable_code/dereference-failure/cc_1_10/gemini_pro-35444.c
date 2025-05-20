//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0, i, weight = 1;

    // Iterate through the binary string from right to left
    for (i = strlen(binary) - 1; i >= 0; i--) {
        // If the current bit is 1, add the corresponding weight to the decimal value
        if (binary[i] == '1') {
            decimal += weight;
        }

        // Double the weight for the next bit
        weight *= 2;
    }

    return decimal;
}

// Function to convert decimal to binary
char *decimalToBinary(int decimal) {
    char *binary = malloc(sizeof(char) * 33);
    int i = 0;

    // Iterate through the decimal value until it is 0
    while (decimal > 0) {
        // If the decimal value is odd, the current bit is 1
        if (decimal % 2 == 1) {
            binary[i] = '1';
        }
        // Otherwise, the current bit is 0
        else {
            binary[i] = '0';
        }

        // Divide the decimal value by 2 to get the next bit
        decimal /= 2;
        i++;
    }

    // Reverse the binary string
    char temp;
    for (i = 0; i < strlen(binary) / 2; i++) {
        temp = binary[i];
        binary[i] = binary[strlen(binary) - i - 1];
        binary[strlen(binary) - i - 1] = temp;
    }

    return binary;
}

int main() {
    // Get the binary string from the user
    char binary[33];
    printf("Enter a binary string: ");
    scanf("%s", binary);

    // Convert the binary string to decimal
    int decimal = binaryToDecimal(binary);

    // Print the decimal value
    printf("The decimal equivalent of %s is %d\n", binary, decimal);

    // Convert the decimal value to binary
    char *newBinary = decimalToBinary(decimal);

    // Print the binary string
    printf("The binary equivalent of %d is %s\n", decimal, newBinary);

    return 0;
}