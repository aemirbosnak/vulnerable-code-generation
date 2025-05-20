//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Reverse the binary string
    char* reversed_binary = malloc(length + 1);
    strcpy(reversed_binary, binary);
    for (int i = 0; i < length / 2; i++) {
        char temp = reversed_binary[i];
        reversed_binary[i] = reversed_binary[length - 1 - i];
        reversed_binary[length - 1 - i] = temp;
    }

    // Convert binary to decimal
    for (int i = 0; i < length; i++) {
        if (reversed_binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    free(reversed_binary);
    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char* binary) {
    int power = 0;
    int remainder;

    // Convert decimal to binary
    while (decimal > 0) {
        remainder = decimal % 2;
        binary[power] = remainder + '0';
        decimal /= 2;
        power++;
    }
    binary[power] = '\0';

    // Reverse the binary string
    int length = strlen(binary);
    for (int i = 0; i < length / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[length - 1 - i];
        binary[length - 1 - i] = temp;
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char binary[MAX_INPUT_LENGTH];

    // Get user input
    printf("Enter a binary number: ");
    scanf("%s", input);

    // Convert binary to decimal
    int decimal = binary_to_decimal(input);

    // Convert decimal to binary
    decimal_to_binary(decimal, binary);

    // Print the result
    printf("Decimal: %d\n", decimal);
    printf("Binary: %s\n", binary);

    return 0;
}