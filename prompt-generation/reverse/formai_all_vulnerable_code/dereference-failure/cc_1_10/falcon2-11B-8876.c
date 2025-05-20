//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hex_to_dec(char *hex) {
    // Initialize variables
    int decimal = 0;
    int power = 0;
    int index = 0;
    
    // Iterate through each character in the hexadecimal string
    while (hex[index]!= '\0') {
        // Convert each character to its decimal equivalent
        decimal += (hex[index] - '0') * pow(16, power);
        power++;
        index++;
    }
    
    // Return the final decimal value
    return decimal;
}

// Function to convert decimal to hexadecimal
char *dec_to_hex(int dec) {
    // Initialize variables
    char *hex = (char *)malloc(5 * sizeof(char));
    int index = 0;
    int remainder = dec;
    
    // Iterate through each character in the hexadecimal string
    while (remainder > 0) {
        // Convert the remainder to its hexadecimal equivalent
        hex[index] = (remainder % 16) + '0';
        remainder = remainder / 16;
        index++;
    }
    
    // Reverse the string
    for (int i = index - 1; i >= 0; i--) {
        hex[i] = hex[index - i];
    }
    
    // Return the final hexadecimal value
    return hex;
}

int main() {
    // Prompt the user for a hexadecimal number
    printf("Enter a hexadecimal number: ");
    char hex[5];
    fgets(hex, 5, stdin);
    
    // Remove any trailing newline characters
    hex[strcspn(hex, "\n")] = '\0';
    
    // Convert the hexadecimal number to decimal
    int dec = hex_to_dec(hex);
    
    // Convert the decimal number to hexadecimal
    char *hex_dec = dec_to_hex(dec);
    
    // Print the original hexadecimal number
    printf("Original hexadecimal number: %s\n", hex);
    
    // Print the decimal number
    printf("Decimal number: %d\n", dec);
    
    // Print the hexadecimal number
    printf("Hexadecimal number: %s\n", hex_dec);
    
    // Free the memory allocated for the hexadecimal string
    free(hex_dec);
    
    return 0;
}