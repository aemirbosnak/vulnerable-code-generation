//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexToDecimal(char *hexStr) {
    char *hexChars = "0123456789ABCDEF"; // Hexadecimal characters
    
    int dec = 0;
    int len = strlen(hexStr);
    for (int i = 0; i < len; i++) {
        char c = hexStr[i];
        
        // Convert character to integer
        int val = 0;
        int index = 0;
        while (hexChars[index] != '\0') {
            if (c == hexChars[index]) {
                val = index;
                break;
            }
            index++;
        }
        
        dec += val << (4 * (len - i - 1)); // Add value to decimal number
    }
    
    printf("The decimal equivalent of %s is %d\n", hexStr, dec);
}

void decimalToHex(int decimal) {
    char *hexChars = "0123456789ABCDEF"; // Hexadecimal characters
    
    int len = 0;
    int tempDec = decimal;
    while (tempDec != 0) { // Find length of hexadecimal string
        len++;
        tempDec >>= 4;
    }
    
    char *hexStr = (char *) malloc(sizeof(char) * (len + 1)); // Allocate memory for hexadecimal string
    hexStr[len] = '\0';
    
    for (int i = len - 1; i >= 0; i--) { // Convert decimal to hexadecimal string
        int val = decimal & 0xF; // Get last four bits
        hexStr[i] = hexChars[val];
        decimal >>= 4; // Shift right by four bits
    }
    
    printf("The hexadecimal equivalent of %d is %s\n", decimal, hexStr);
    free(hexStr); // Deallocate memory
}

int main() {
    char choice;
    do {
        int decimal;
        char hexStr[20];
        printf("Enter 'h' for hexadecimal to decimal conversion, 'd' for decimal to hexadecimal conversion: ");
        scanf("%c", &choice);
        getchar(); // Remove newline character from input
        
        if (choice == 'h') {
            printf("Enter a hexadecimal number: ");
            fgets(hexStr, sizeof(hexStr), stdin);
            hexToDecimal(hexStr);
        } else if (choice == 'd') {
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            decimalToHex(decimal);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
        printf("Do you want to convert another number? (y/n): ");
        scanf("%c", &choice);
        getchar(); // Remove newline character from input
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("Thank you for using the hexadecimal converter!\n");
    return 0;
}