//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_LENGTH 32
#define HEX_DIGITS "0123456789ABCDEF"

void decimalToBinary(int decimalNumber, char binaryNumber[MAX_NUM_LENGTH]) {
    int i = 0;
    for (; decimalNumber > 0; decimalNumber /= 2, i++) {
        binaryNumber[i] = decimalNumber % 2 + '0';
    }

    binaryNumber[i + 1] = '\0';
    while (i > 0 && binaryNumber[0] == '0') {
        memmove(binaryNumber, binaryNumber + 1, sizeof(char) * (i-- + 1));
    }
}

void decimalToHexadecimal(int decimalNumber, char hexadecimalNumber[MAX_NUM_LENGTH]) {
    int i;
    for (i = 0; decimalNumber > 0; i++) {
        int digit = decimalNumber % 16;
        hexadecimalNumber[i] = HEX_DIGITS[digit];
        decimalNumber /= 16;
    }

    hexadecimalNumber[i + 1] = '\0';
    if (decimalNumber > 0) {
        hexadecimalNumber[0] = HEX_DIGITS[decimalNumber];
        i++;
    }
}

void printOutput(char *outputFormat, int decimalNumber, char binaryNumber[MAX_NUM_LENGTH], char hexadecimalNumber[MAX_NUM_LENGTH]) {
    printf("Decimal number: %d\n", decimalNumber);

    if (strcmp(outputFormat, "bin") == 0) {
        printf("Binary representation: %s\n", binaryNumber);
    } else if (strcmp(outputFormat, "hex") == 0) {
        printf("Hexadecimal representation: %s\n", hexadecimalNumber);
    } else if (strcmp(outputFormat, "both") == 0) {
        printf("Binary representation: %s\n", binaryNumber);
        printf("Hexadecimal representation: %s\n", hexadecimalNumber);
    } else {
        printf("Invalid output format.\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <decimal number> <output format>\n", argv[0]);
        return 1;
    }

    int decimalNumber = atoi(argv[1]);
    char outputFormat[10];
    strcpy(outputFormat, argv[2]);

    char binaryNumber[MAX_NUM_LENGTH];
    char hexadecimalNumber[MAX_NUM_LENGTH];

    decimalToBinary(decimalNumber, binaryNumber);
    decimalToHexadecimal(decimalNumber, hexadecimalNumber);

    printOutput(outputFormat, decimalNumber, binaryNumber, hexadecimalNumber);

    return 0;
}