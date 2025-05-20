//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Define the hexadecimal digits
char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

// Function to convert a decimal number to hexadecimal
char* toHex(int num) {
    char* hexString = (char*) malloc(sizeof(char) * 100); // Allocate memory for the hexadecimal string
    int i = 0;
    while (num > 0) {
        hexString[i++] = hexDigits[num % 16]; // Append the hexadecimal digit to the string
        num /= 16; // Divide the number by 16 to get the next hexadecimal digit
    }
    hexString[i] = '\0'; // Add the null terminator
    
    // Reverse the string to get the correct hexadecimal representation
    int len = strlen(hexString);
    for (int j = 0; j < len / 2; j++) {
        char temp = hexString[j];
        hexString[j] = hexString[len - 1 - j];
        hexString[len - 1 - j] = temp;
    }
    
    return hexString; // Return the hexadecimal string
}

// Function to convert a hexadecimal number to decimal
int fromHex(char* hexString) {
    int decimal = 0;
    int len = strlen(hexString);
    for (int i = 0; i < len; i++) {
        int digit;
        if (hexString[i] >= '0' && hexString[i] <= '9') {
            digit = hexString[i] - '0';
        } else if (hexString[i] >= 'A' && hexString[i] <= 'F') {
            digit = hexString[i] - 'A' + 10;
        } else if (hexString[i] >= 'a' && hexString[i] <= 'f') {
            digit = hexString[i] - 'a' + 10;
        }
        decimal = decimal * 16 + digit;
    }
    return decimal;
}

// Main function
int main() {
    // Welcome message
    printf("Welcome to the Hexadecimal Converter! Prepare to be amazed!\n");
    
    // Get the user input
    char choice;
    int num;
    char hexString[100];
    printf("Enter 't' to convert a decimal number to hexadecimal or 'f' to convert a hexadecimal number to decimal: ");
    scanf(" %c", &choice);
    
    switch (choice) {
        case 't':
            // Convert decimal to hexadecimal
            printf("Enter a decimal number: ");
            scanf(" %d", &num);
            printf("The hexadecimal representation of %d is: %s\n", num, toHex(num));
            break;
        case 'f':
            // Convert hexadecimal to decimal
            printf("Enter a hexadecimal number: ");
            scanf(" %s", hexString);
            printf("The decimal representation of %s is: %d\n", hexString, fromHex(hexString));
            break;
        default:
            // Invalid input
            printf("Invalid choice. Please enter 't' or 'f'.\n");
    }
    
    // Farewell message
    printf("Thank you for using the Hexadecimal Converter! May your coding adventures be filled with hexadecimal splendor!\n");
    
    return 0;
}