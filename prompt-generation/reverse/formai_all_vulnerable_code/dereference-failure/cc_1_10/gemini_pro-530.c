//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
char* decimalToBinary(int n)
{
    // Initialize the binary string as empty
    char* binary = malloc(33);
    int i = 0;

    // Convert the decimal number to binary by dividing it by 2 and storing the remainder in the binary string
    while (n > 0)
    {
        binary[i] = n % 2 + '0';
        n /= 2;
        i++;
    }

    // Reverse the binary string
    int j = 0;
    int temp;
    while (j < i / 2)
    {
        temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
        j++;
    }

    // Add the null terminator to the end of the binary string
    binary[i] = '\0';

    // Return the binary string
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char* binary)
{
    // Initialize the decimal number to 0
    int decimal = 0;

    // Convert the binary number to decimal by multiplying each bit by the corresponding power of 2
    int i = 0;
    int j = 0;
    while (binary[i] != '\0')
    {
        if (binary[i] == '1')
        {
            decimal += 1 << j;
        }
        i++;
        j++;
    }

    // Return the decimal number
    return decimal;
}

// Main function
int main()
{
    // Get the decimal number from the user
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert the decimal number to binary
    char* binary = decimalToBinary(decimal);

    // Print the binary representation of the decimal number
    printf("Binary representation of %d: %s\n", decimal, binary);

    // Convert the binary number back to decimal
    int decimal2 = binaryToDecimal(binary);

    // Print the decimal representation of the binary number
    printf("Decimal representation of %s: %d\n", binary, decimal2);

    // Free the memory allocated for the binary string
    free(binary);

    return 0;
}