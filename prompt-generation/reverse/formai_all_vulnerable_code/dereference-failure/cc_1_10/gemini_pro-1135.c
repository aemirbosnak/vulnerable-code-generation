//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char* decToBinary(int n)
{
    // Check if the number is negative
    if (n < 0) {
        return "Invalid input: negative numbers are not supported";
    }

    // Initialize the binary string
    char* binary = malloc(sizeof(char) * 33);
    memset(binary, '0', 32);
    binary[32] = '\0';

    // Convert the decimal number to binary
    int i = 0;
    while (n > 0) {
        binary[31 - i] = (n % 2) + '0';
        n /= 2;
        i++;
    }

    // Return the binary string
    return binary;
}

// Function to convert a binary number to decimal
int binaryToDec(char* binary)
{
    // Check if the binary string is valid
    if (!binary) {
        return -1;
    }

    // Validate the binary string
    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            return -1;
        }
    }

    // Convert the binary number to decimal
    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += (1 << (length - i - 1));
        }
    }

    // Return the decimal number
    return decimal;
}

int main()
{
    // Get the input from the user
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 3);

    // Perform the conversion
    switch (choice) {
        case 1:
        {
            int decimal;
            printf("Enter a decimal number: ");
            scanf("%d", &decimal);
            char* binary = decToBinary(decimal);
            printf("Binary representation: %s\n", binary);
            free(binary);
            break;
        }
        case 2:
        {
            char binary[33];
            printf("Enter a binary number: ");
            scanf("%s", binary);
            int decimal = binaryToDec(binary);
            if (decimal == -1) {
                printf("Invalid binary number\n");
            } else {
                printf("Decimal representation: %d\n", decimal);
            }
            break;
        }
        case 3:
            printf("Exiting...\n");
            break;
    }

    return 0;
}