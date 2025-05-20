//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

// Function to convert a single hexadecimal digit to its decimal equivalent
int hex_to_decimal(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

// Function to convert a hexadecimal string to a binary string
void hex_to_binary(char *hex, char *binary) {
    int i, j;
    int num;

    for (i = 0; i < strlen(hex) && i < MAX_INPUT_SIZE / 4; i++) {
        num = hex_to_decimal(hex[i]);

        for (j = 0; j < 4; j++) {
            binary[i * 4 + j] = (num >> (3 - j) & 1) + '0';
        }
    }

    binary[i * 4 + j] = '\0';
}

// Function to print a binary string
void print_binary(char *binary) {
    int i;

    printf("Binary equivalent: ");

    for (i = 0; binary[i] != '\0'; i++) {
        printf("%c", binary[i]);
    }

    printf("\n");
}

// Function to convert a hexadecimal string to binary
void hex_to_bin(char *input) {
    char hex[MAX_INPUT_SIZE];
    char binary[MAX_INPUT_SIZE * 4];

    strcpy(hex, input);

    hex_to_binary(hex, binary);

    print_binary(binary);
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter a hexadecimal string: ");
    scanf("%s", input);

    hex_to_bin(input);

    return 0;
}