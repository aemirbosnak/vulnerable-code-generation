//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
// C Binary Converter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void binaryToDecimal();
void decimalToBinary();

// Protected function declaration
char* getPassword();

// Main function
int main() {
    int choice;
    char* password;

    printf("Welcome to C Binary Converter!\n");

    // Prompt user for password
    password = getPassword();

    // Check if password is correct
    if (strcmp(password, "abc123") != 0) {
        printf("Incorrect password. Exiting program.\n");
        exit(0);
    }

    // Free memory used by password string
    free(password);

    // Print menu options
    printf("\nMenu:\n1. Binary to Decimal conversion\n2. Decimal to Binary conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            binaryToDecimal();
            break;
        case 2:
            decimalToBinary();
            break;
        default:
            printf("Invalid choice. Exiting program.\n");
            break;
    }

    return 0;
}

// Function that converts binary to decimal
void binaryToDecimal() {
    char binary[32];
    int decimal = 0, i, power = 1, len;

    // Prompt user for binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Calculate length of binary number
    len = strlen(binary);

    // Convert binary to decimal
    for (i = len-1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    // Print decimal equivalent
    printf("Decimal Equivalent: %d\n", decimal);
}

// Function that converts decimal to binary
void decimalToBinary() {
    int decimal, binary[32], i = 0;

    // Prompt user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    // Print binary equivalent
    printf("Binary Equivalent: ");
    while (i > 0) {
        printf("%d", binary[--i]);
    }
    printf("\n");
}

// Protected function that prompts user for password
char* getPassword() {
    char* password = (char*)malloc(20);
    printf("Enter password: ");
    scanf("%s", password);
    return password;
}