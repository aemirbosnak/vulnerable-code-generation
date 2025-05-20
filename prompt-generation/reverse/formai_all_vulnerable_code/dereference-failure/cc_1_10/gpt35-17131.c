//FormAI DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_DIGITS 32

// Function to convert decimal to binary.
char* decimalToBinary(int decimalValue)
{
    int binaryValue[MAX_BINARY_DIGITS] = {0};  // Initialize array to store binary digits.
    char* binaryString = malloc(MAX_BINARY_DIGITS * sizeof(char)); // Allocate memory for binary string.

    int index = 0;  // Initialize index for binaryValue array.

    while (decimalValue > 0)
    {
        binaryValue[index] = decimalValue % 2;  // Compute binary digit.
        decimalValue /= 2;
        index++;
    }

    // Reverse binaryValue array to get binary value in correct order.
    for (int i = index - 1, j = 0; i >= 0; i--, j++)
    {
        binaryString[j] = binaryValue[i] + '0';  // Convert binary digit to character.
    }

    binaryString[index] = '\0';  // Add null character to terminate string.

    return binaryString;
}

// Main function to run program.
int main()
{
    int decimalValue;
    char* binaryString;

    printf("Enter a decimal value to convert to binary: ");
    scanf("%d", &decimalValue);

    if (decimalValue < 0)
    {
        printf("Negative decimal values cannot be converted to binary.\n");
        return 1;   // Exit program with error code.
    }

    binaryString = decimalToBinary(decimalValue);  // Convert decimal value to binary.

    printf("Binary value of decimal %d is: %s\n", decimalValue, binaryString);

    free(binaryString);  // Free memory allocated for binary string.

    return 0;  // Exit program with success code.
}