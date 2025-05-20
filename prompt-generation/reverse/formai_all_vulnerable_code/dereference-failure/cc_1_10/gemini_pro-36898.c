//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a function to convert a hexadecimal number to an integer.
int hexToDec(char *hex) {
    int len = strlen(hex);
    int i;
    int dec = 0;
    
    // Iterate over the hexadecimal number from right to left.
    for (i = len - 1; i >= 0; i--) {
        // Get the digit value of the current character.
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        } else {
            return -1; // Invalid hexadecimal digit.
        }
        
        // Add the digit value to the decimal number, weighted by its position.
        dec += digit * pow(16, len - i - 1);
    }
    
    return dec;
}

// Create a function to convert an integer to a hexadecimal number.
char *decToHex(int dec) {
    char *hex = malloc(100);
    int i = 0;
    
    // Iterate over the hexadecimal number from right to left.
    while (dec > 0) {
        // Get the remainder of the division by 16.
        int remainder = dec % 16;
        
        // Convert the remainder to a hexadecimal digit.
        char digit;
        if (remainder >= 0 && remainder <= 9) {
            digit = remainder + '0';
        } else if (remainder >= 10 && remainder <= 15) {
            digit = remainder - 10 + 'A';
        } else {
            return NULL; // Invalid decimal number.
        }
        
        // Add the digit to the hexadecimal number.
        hex[i] = digit;
        i++;
        
        // Divide the decimal number by 16.
        dec /= 16;
    }
    
    // Reverse the hexadecimal number.
    for (int j = 0; j < i / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[i - j - 1];
        hex[i - j - 1] = temp;
    }
    
    // Add the null terminator to the hexadecimal number.
    hex[i] = '\0';
    
    return hex;
}

int main() {
    // Get the hexadecimal number from the user.
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    
    // Convert the hexadecimal number to an integer.
    int dec = hexToDec(hex);
    if (dec == -1) {
        printf("Invalid hexadecimal number.\n");
        return 1;
    }
    
    // Print the integer representation of the hexadecimal number.
    printf("Decimal representation: %d\n", dec);
    
    // Convert the integer back to a hexadecimal number.
    char *newHex = decToHex(dec);
    if (newHex == NULL) {
        printf("Invalid decimal number.\n");
        return 1;
    }
    
    // Print the new hexadecimal number.
    printf("New hexadecimal representation: %s\n", newHex);
    
    return 0;
}