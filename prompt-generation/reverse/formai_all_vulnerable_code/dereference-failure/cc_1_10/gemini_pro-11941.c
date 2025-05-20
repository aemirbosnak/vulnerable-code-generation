//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: unmistakable
// Binary Converter by XYZ Hackers

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum length of the input number
#define MAX_LENGTH 100

// Function to convert a decimal number to binary
char* decimalToBinary(int decimal) {
    char* binary = (char*)malloc(MAX_LENGTH * sizeof(char));

    int index = 0;
    while (decimal > 0) {
        // Get the remainder of the division by 2
        int remainder = decimal % 2;

        // Append the remainder to the binary string
        binary[index] = remainder + '0';
        index++;

        // Divide the decimal number by 2
        decimal /= 2;
    }

    // Reverse the binary string
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = binary[start];
        binary[start] = binary[end];
        binary[end] = temp;
        start++;
        end--;
    }

    // Add the null-terminator to the binary string
    binary[index] = '\0';

    return binary;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--) {
        // Get the digit at the current position
        int digit = binary[i] - '0';

        // Calculate the power of 2 for the current position
        int power = 1 << (length - 1 - i);

        // Add the product of the digit and the power to the decimal number
        decimal += digit * power;
    }

    return decimal;
}

// Function to print the binary representation of a number
void printBinary(int number) {
    char* binary = decimalToBinary(number);
    printf("%s", binary);
    free(binary);
}

// Function to check if a number is a valid binary number
bool isValidBinary(char* binary) {
    int length = strlen(binary);

    for (int i = 0; i < length; i++) {
        // Check if the current character is a valid binary digit
        if (binary[i] != '0' && binary[i] != '1') {
            return false;
        }
    }

    return true;
}

// Main function
int main() {
    // Define the user input
    int choice;
    char number[MAX_LENGTH];

    // Print the menu
    printf("\nBinary Converter\n");
    printf("--------------------\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("3. Quit\n");
    printf("--------------------\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            // Get the decimal number from the user
            printf("Enter a decimal number: ");
            scanf("%d", &number);

            // Convert the decimal number to binary
            char* binary = decimalToBinary(number);

            // Print the binary representation of the number
            printf("Binary representation: %s\n", binary);

            // Free the memory allocated for the binary number
            free(binary);
            break;
        case 2:
            // Get the binary number from the user
            printf("Enter a binary number: ");
            scanf("%s", number);

            // Check if the binary number is valid
            if (!isValidBinary(number)) {
                printf("Invalid binary number. Please enter a valid binary number.\n");
            } else {
                // Convert the binary number to decimal
                int decimal = binaryToDecimal(number);

                // Print the decimal representation of the number
                printf("Decimal representation: %d\n", decimal);
            }
            break;
        case 3:
            // Quit the program
            printf("Thank you for using the Binary Converter. Goodbye!\n");
            return 0;
        default:
            // Invalid choice
            printf("Invalid choice. Please enter a valid choice.\n");
            break;
    }

    // Go back to the beginning of the main function
    main();

    return 0;
}