//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decToBinary(int n) {
    // Check if the number is non-negative
    if (n < 0) {
        printf("Error: The number must be non-negative.\n");
        return NULL;
    }

    // Initialize the binary string
    int binarySize = 32;
    char* binary = malloc(binarySize);
    binary[0] = '\0';

    // Convert the number to binary
    int index = 0;
    while (n > 0) {
        // Get the least significant bit
        int bit = n % 2;

        // Append the bit to the binary string
        binary[index++] = bit + '0';

        // Divide the number by 2
        n /= 2;
    }

    // Reverse the binary string
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }

    // Return the binary string
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDec(char* binary) {
    // Check if the string is a valid binary number
    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Error: The string is not a valid binary number.\n");
            return -1;
        }
    }

    // Convert the binary number to decimal
    int dec = 0;
    int len = strlen(binary);
    for (int i = 0; i < len; i++) {
        dec += (binary[i] - '0') * (1 << (len - i - 1));
    }

    // Return the decimal number
    return dec;
}

// Main function
int main() {
    // Get the decimal number from the user
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    // Convert the decimal number to binary
    char* binary = decToBinary(n);

    // Print the binary number
    printf("The binary representation of %d is %s\n", n, binary);

    // Convert the binary number to decimal
    int dec = binaryToDec(binary);

    // Print the decimal number
    printf("The decimal representation of %s is %d\n", binary, dec);

    // Free the allocated memory
    free(binary);

    return 0;
}