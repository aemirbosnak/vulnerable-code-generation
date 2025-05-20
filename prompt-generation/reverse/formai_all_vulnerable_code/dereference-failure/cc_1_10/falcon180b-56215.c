//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary
char* decimal_to_binary(int decimal) {
    char* binary = malloc(33 * sizeof(char)); // allocate memory for binary string
    sprintf(binary, "%b", decimal); // convert decimal to binary
    return binary;
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    return strtol(binary, NULL, 2);
}

// Function to convert decimal to hexadecimal
char* decimal_to_hexadecimal(int decimal) {
    char* hexadecimal = malloc(9 * sizeof(char)); // allocate memory for hexadecimal string
    sprintf(hexadecimal, "%X", decimal); // convert decimal to hexadecimal
    return hexadecimal;
}

// Function to convert hexadecimal to decimal
int hexadecimal_to_decimal(char* hexadecimal) {
    return strtol(hexadecimal, NULL, 16);
}

// Function to convert decimal to octal
char* decimal_to_octal(int decimal) {
    char* octal = malloc(12 * sizeof(char)); // allocate memory for octal string
    sprintf(octal, "%o", decimal); // convert decimal to octal
    return octal;
}

// Function to convert octal to decimal
int octal_to_decimal(char* octal) {
    return strtol(octal, NULL, 8);
}

int main() {
    int decimal = 42;
    char* binary = decimal_to_binary(decimal);
    printf("Binary: %s\n", binary);

    int binary_int = binary_to_decimal(binary);
    printf("Decimal: %d\n", binary_int);

    char* hexadecimal = decimal_to_hexadecimal(decimal);
    printf("Hexadecimal: %s\n", hexadecimal);

    int hexadecimal_int = hexadecimal_to_decimal(hexadecimal);
    printf("Decimal: %d\n", hexadecimal_int);

    char* octal = decimal_to_octal(decimal);
    printf("Octal: %s\n", octal);

    int octal_int = octal_to_decimal(octal);
    printf("Decimal: %d\n", octal_int);

    return 0;
}