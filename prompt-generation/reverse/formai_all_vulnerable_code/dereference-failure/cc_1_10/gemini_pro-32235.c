//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int base = 1;
    int len = strlen(binary);
    
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    
    return decimal;
}

// Function to convert decimal to binary
char* decimalToBinary(int decimal) {
    char* binary = (char*)malloc(33);
    int index = 0;
    
    while (decimal > 0) {
        if (decimal % 2 == 0) {
            binary[index++] = '0';
        } else {
            binary[index++] = '1';
        }
        
        decimal /= 2;
    }
    
    binary[index] = '\0';
    
    // Reverse the binary string
    int len = strlen(binary);
    for (int i = 0; i < len / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }
    
    return binary;
}

// Main function
int main() {
    // Get the binary number from the user
    char binary[33];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    
    // Convert the binary number to decimal
    int decimal = binaryToDecimal(binary);
    
    // Print the decimal number
    printf("The decimal equivalent of %s is %d\n", binary, decimal);
    
    // Convert the decimal number back to binary
    char* newBinary = decimalToBinary(decimal);
    
    // Print the new binary number
    printf("The binary equivalent of %d is %s\n", decimal, newBinary);
    
    return 0;
}