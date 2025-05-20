//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LENGTH 32 // Maximum length of input number

typedef struct {
    int decimal; // Decimal value of number
    char binary[MAX_NUM_LENGTH + 1]; // Binary representation of number
} Number;

// Function to convert decimal to binary
void decimalToBinary(Number* num) {
    char* binary = &num->binary[MAX_NUM_LENGTH - 1];
    *binary = '\0';
    while (num->decimal > 0) {
        int remainder = num->decimal % 2;
        num->decimal /= 2;
        *binary-- = remainder + '0';
    }
}

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    while (*binary!= '\0') {
        decimal *= 2;
        decimal += *binary - '0';
        binary++;
    }
    return decimal;
}

// Function to print usage instructions
void printUsage() {
    printf("Usage:./binary_converter [decimal_number] [operation]\n");
    printf("Operations:\n");
    printf("  d - Decimal to binary conversion\n");
    printf("  b - Binary to decimal conversion\n");
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printUsage();
        return 1;
    }

    Number num;
    strcpy(num.binary, argv[1]);
    num.decimal = binaryToDecimal(num.binary);

    if (strcmp(argv[2], "d") == 0) {
        decimalToBinary(&num);
        printf("Binary representation: %s\n", num.binary);
    } else if (strcmp(argv[2], "b") == 0) {
        printf("Decimal representation: %d\n", num.decimal);
    } else {
        printUsage();
        return 1;
    }

    return 0;
}