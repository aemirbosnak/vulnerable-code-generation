//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char* decimalToBinary(int n)
{
    // Initialize the binary array with size 32
    char binary[32];

    // Index of current digit in binary array
    int i = 0;
    while (n > 0) {
        // Store the remainder of n divided by 2 at index 'i'
        binary[i++] = (n % 2) + '0';

        // Divide n by 2
        n /= 2;
    }

    // Terminate the binary array with a null character
    binary[i] = '\0';

    // Reverse the binary array
    int j = 0;
    int k = i - 1;
    while (j < k) {
        char temp = binary[j];
        binary[j++] = binary[k];
        binary[k--] = temp;
    }

    // Allocate memory for the binary string
    char* binaryString = malloc(sizeof(char) * (i + 1));

    // Copy the binary array to the binary string
    for (int l = 0; l < i; l++) {
        binaryString[l] = binary[l];
    }

    // Terminate the binary string with a null character
    binaryString[i] = '\0';

    // Return the binary string
    return binaryString;
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary)
{
    // Initialize the decimal value to 0
    int decimal = 0;

    // Index of current digit in binary string
    int i = 0;
    while (binary[i] != '\0') {
        // Multiply the decimal value by 2
        decimal *= 2;

        // Add the current digit to the decimal value
        decimal += binary[i++] - '0';
    }

    // Return the decimal value
    return decimal;
}

// Driver code to test the decimalToBinary and binaryToDecimal functions
int main()
{
    // Convert decimal to binary
    char* binaryString = decimalToBinary(123);
    printf("Decimal: 123, Binary: %s\n", binaryString);

    // Convert binary to decimal
    int decimalValue = binaryToDecimal(binaryString);
    printf("Binary: %s, Decimal: %d\n", binaryString, decimalValue);

    // Free the memory allocated for the binary string
    free(binaryString);

    return 0;
}