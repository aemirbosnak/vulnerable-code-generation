//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
char* decToBin(int num)
{
    // Allocate memory for the binary string
    char* binary = (char*)malloc(33 * sizeof(char));
    
    // Initialize the binary string to all zeros
    memset(binary, '0', 33);
    
    // Convert the decimal number to binary
    int index = 32;
    while (num > 0) {
        if (num % 2 == 1) {
            binary[index] = '1';
        }
        num /= 2;
        index--;
    }
    
    // Reverse the binary string
    int i, j;
    for (i = 0, j = 32; i < j; i++, j--) {
        char temp = binary[i];
        binary[i] = binary[j];
        binary[j] = temp;
    }
    
    // Return the binary string
    return binary;
}

// Function to convert binary to decimal
int binToDec(char* binary)
{
    int decimal = 0;
    int length = strlen(binary);
    
    // Convert each bit of the binary string to a decimal digit
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += (1 << (length - i - 1));
        }
    }
    
    // Return the decimal number
    return decimal;
}

// Main function
int main()
{
    // Get the decimal number from the user
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    
    // Convert the decimal number to binary
    char* binary = decToBin(num);
    
    // Print the binary number
    printf("The binary representation of %d is: %s\n", num, binary);
    
    // Free the memory allocated for the binary string
    free(binary);
    
    // Get the binary number from the user
    char* binary_input;
    printf("Enter a binary number: ");
    scanf("%s", binary_input);
    
    // Convert the binary number to decimal
    int decimal = binToDec(binary_input);
    
    // Print the decimal number
    printf("The decimal representation of %s is: %d\n", binary_input, decimal);
    
    return 0;
}