//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BITS 32
#define MAX_VAL 2147483647

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    for (int i = 0; i < strlen(binary); i++) {
        decimal += (binary[i] - '0') * pow(2, i);
    }
    return decimal;
}

// Function to convert decimal to binary
char *decimal_to_binary(int decimal) {
    char *binary = malloc(sizeof(char) * (log10(decimal) + 1));
    int i = 0;
    while (decimal != 0) {
        binary[i] = decimal % 2 == 0 ? '0' : '1';
        decimal /= 2;
        i++;
    }
    return binary;
}

int main() {
    srand(time(NULL));

    // Generate a random decimal number
    int decimal = rand() % MAX_VAL;

    // Convert decimal to binary
    char *binary = decimal_to_binary(decimal);

    // Print the binary representation
    printf("The binary representation of %d is: %s\n", decimal, binary);

    // Ask the user for a binary string
    char *user_binary = malloc(sizeof(char) * 10);
    printf("Enter a binary string (max 10 digits): ");
    fgets(user_binary, 10, stdin);

    // Convert the user-input binary string to decimal
    int user_decimal = binary_to_decimal(user_binary);

    // Print the decimal representation
    printf("The decimal representation of %s is %d\n", user_binary, user_decimal);

    free(binary);
    free(user_binary);

    return 0;
}