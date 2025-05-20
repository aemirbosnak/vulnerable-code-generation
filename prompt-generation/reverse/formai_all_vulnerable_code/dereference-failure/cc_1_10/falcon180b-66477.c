//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 // maximum size of binary input

// function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int i = strlen(binary) - 1;
    while (i >= 0) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
        i--;
    }
    return decimal;
}

// function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int i = 0;
    while (decimal > 0) {
        if (decimal % 2 == 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
        i++;
        decimal /= 2;
    }
    binary[i] = '\0'; // add null terminator
}

int main() {
    char binary[MAX_SIZE];
    int decimal;

    printf("Enter a binary number: ");
    fgets(binary, MAX_SIZE, stdin); // read binary input from user

    // remove newline character from input
    int i = strlen(binary) - 1;
    while (i >= 0 && binary[i] == '\n') {
        binary[i] = '\0';
        i--;
    }

    // convert binary to decimal
    decimal = binaryToDecimal(binary);

    // convert decimal to binary
    char* result = malloc(MAX_SIZE * sizeof(char)); // allocate memory for result
    decimalToBinary(decimal, result);

    printf("Decimal equivalent: %s\n", result); // print decimal equivalent

    return 0;
}