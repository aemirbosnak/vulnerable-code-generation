//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(int n) {
    if(n > 1)
        printBinary(n >> 1);
    printf("%d", n & 1);
}

void convertToHex(int n, char *hexStr) {
    sprintf(hexStr, "%X", n);
}

void convertToOctal(int n, char *octStr) {
    sprintf(octStr, "%o", n);
}

int isNumber(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;  // Not a digit
        }
    }
    return 1;  // Is a digit
}

void displayConversions(int number) {
    char hexStr[20], octStr[20];
    
    convertToHex(number, hexStr);
    convertToOctal(number, octStr);

    printf("The number %d in hexadecimal: %s\n", number, hexStr);
    printf("The number %d in octal: %s\n", number, octStr);
    printf("The number %d in binary: ", number);
    printBinary(number);
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <integer_number>\n", argv[0]);
        return 1;
    }

    if (!isNumber(argv[1])) {
        fprintf(stderr, "Error: Input must be a valid integer number.\n");
        return 1;
    }

    int number = atoi(argv[1]);

    if (number < 0) {
        fprintf(stderr, "Error: Please enter a non-negative integer.\n");
        return 1;
    }

    printf("You've entered the number: %d\n", number);
    
    displayConversions(number);

    return 0;
}