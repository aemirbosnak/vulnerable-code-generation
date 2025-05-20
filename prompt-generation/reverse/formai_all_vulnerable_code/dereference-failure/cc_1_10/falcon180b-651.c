//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 100

// Function to convert a hexadecimal string to an integer
int hex_to_int(char *hex) {
    int value = 0;
    int i = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            value = value * 16 + hex[i] - '0';
        } else if (isupper(hex[i])) {
            value = value * 16 + hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            value = value * 16 + hex[i] - 'a' + 10;
        } else {
            return -1;
        }
        i++;
    }
    return value;
}

// Function to convert an integer to a hexadecimal string
void int_to_hex(int value, char *hex) {
    sprintf(hex, "%X", value);
}

// Function to convert a binary string to a hexadecimal string
void bin_to_hex(char *bin, char *hex) {
    int i = 0;
    int j = 0;
    while (bin[i]) {
        if (bin[i] == '1') {
            hex[j] = '1';
            j++;
        } else {
            hex[j] = '0';
            j++;
        }
        i++;
    }
    hex[j] = '\0';
}

// Function to convert a hexadecimal string to a binary string
void hex_to_bin(char *hex, char *bin) {
    int i = 0;
    int j = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            bin[j] = hex[i] - '0';
        } else if (isupper(hex[i])) {
            bin[j] = hex[i] - 'A' + 10;
        } else if (islower(hex[i])) {
            bin[j] = hex[i] - 'a' + 10;
        } else {
            bin[j] = '0';
        }
        i++;
        j++;
    }
    bin[j] = '\0';
}

int main() {
    char hex[MAX_HEX_LENGTH];
    char bin[MAX_HEX_LENGTH];
    char input[MAX_HEX_LENGTH];
    int value;

    // Prompt user for input
    printf("Enter a hexadecimal string: ");
    scanf("%s", input);

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Convert hexadecimal string to integer
    value = hex_to_int(input);

    // Convert integer to hexadecimal string
    int_to_hex(value, hex);

    // Convert integer to binary string
    char *binary_string = malloc(MAX_HEX_LENGTH * 4);
    sprintf(binary_string, "%d", value);
    strcat(bin, binary_string);

    // Output results
    printf("Hexadecimal: %s\n", hex);
    printf("Binary: %s\n", bin);

    // Free memory
    free(binary_string);

    return 0;
}