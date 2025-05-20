//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define TRUE 1
#define FALSE 0

// Function to check if a string is a valid binary number
int isBinary(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i]) && str[i]!= '0' && str[i]!= '1') {
            return FALSE;
        }
    }
    return TRUE;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Iterate through the binary number from right to left
    for (int i = length - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}

// Function to convert a decimal number to binary
char* decimalToBinary(int decimal) {
    char* binary = malloc(MAX_LENGTH * sizeof(char));
    int length = 0;
    int temp = decimal;

    // Iterate through the decimal number until it becomes zero
    while (temp > 0) {
        if (temp % 2 == 0) {
            strcat(binary, "0");
        } else {
            strcat(binary, "1");
        }
        temp /= 2;
        length++;
    }

    // Reverse the binary number and add leading zeros if necessary
    int i = 0;
    int j = length - 1;
    while (i < j) {
        char tempChar = binary[i];
        binary[i] = binary[j];
        binary[j] = tempChar;
        i++;
        j--;
    }
    while (strlen(binary) < MAX_LENGTH) {
        strcat(binary, "0");
    }

    return binary;
}

int main() {
    char input[MAX_LENGTH];
    int choice;

    do {
        printf("Enter a binary number: ");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (isBinary(input)) {
            int decimal = binaryToDecimal(input);
            char* binaryStr = decimalToBinary(decimal);
            printf("Decimal equivalent: %d\n", decimal);
            printf("Binary equivalent: %s\n", binaryStr);
        } else {
            printf("Invalid binary number.\n");
        }

        printf("Do you want to try again? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}