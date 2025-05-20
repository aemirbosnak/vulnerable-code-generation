//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char* decToBinary(int n) {
    // Declare a string to store the binary number
    char* binary = malloc(sizeof(char) * 33);
    
    // Initialize the string with '0'
    for (int i = 0; i < 32; i++) {
        binary[i] = '0';
    }

    // Convert the decimal number to binary
    int i = 31;
    while (n > 0) {
        if (n % 2 == 1) {
            binary[i] = '1';
        }
        n /= 2;
        i--;
    }

    // Add the null terminator to the end of the string
    binary[32] = '\0';

    // Return the binary number
    return binary;
}

// Function to convert binary to decimal
int binaryToDec(char* binary) {
    // Initialize the decimal number to 0
    int dec = 0;

    // Convert the binary number to decimal
    for (int i = 0; i < 32; i++) {
        if (binary[i] == '1') {
            // Shift the decimal number left by one bit
            dec <<= 1;
            // Add 1 to the decimal number
            dec += 1;
        } else {
            // Shift the decimal number left by one bit
            dec <<= 1;
        }
    }

    // Return the decimal number
    return dec;
}

// Main function
int main() {
    // Get the decimal number from the user
    int dec;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    // Convert the decimal number to binary
    char* binary = decToBinary(dec);

    // Print the binary number
    printf("The binary number is: %s\n", binary);

    // Convert the binary number to decimal
    int dec2 = binaryToDec(binary);

    // Print the decimal number
    printf("The decimal number is: %d\n", dec2);

    // Free the memory allocated for the binary number
    free(binary);

    return 0;
}