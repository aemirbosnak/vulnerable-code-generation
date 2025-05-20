//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int decimal = 0, i = 0;
    while (hex[i]) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += hex[i] - 'a' + 10;
        } else {
            printf("Invalid character in hexadecimal number.\n");
            exit(1);
        }
        i++;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[]) {
    sprintf(hex, "%X", dec);
}

// Function to print usage instructions
void printUsage() {
    printf("Usage:./program [hexadecimal number]\n");
    printf("Example:./program 1A2B\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printUsage();
        exit(1);
    }
    
    char hex[100];
    strcpy(hex, argv[1]);

    // Convert hexadecimal to decimal
    int decimal = hexToDec(hex);

    // Convert decimal to hexadecimal
    char hexDecimal[100];
    decToHex(decimal, hexDecimal);

    // Print the result
    printf("The decimal equivalent of %s is %s.\n", hex, hexDecimal);

    return 0;
}