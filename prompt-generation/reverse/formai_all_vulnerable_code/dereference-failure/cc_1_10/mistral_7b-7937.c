//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DECIMAL 32767
#define BINARY_LENGTH (sizeof(int) * 8)

void convertDecimalToBinary(int decimalNumber, char binaryNumber[]);
void printBinaryNumber(char binaryNumber[]);

int main(int argc, char *argv[]) {
    int decimalNumber;
    char binaryNumber[BINARY_LENGTH + 1];

    if (argc != 2) {
        printf("Usage: %s <decimal number>\n", argv[0]);
        exit(1);
    }

    decimalNumber = atoi(argv[1]);

    if (decimalNumber < 0 || decimalNumber > MAX_DECIMAL) {
        printf("Error: The decimal number must be between 0 and %d\n", MAX_DECIMAL);
        exit(1);
    }

    memset(binaryNumber, '0', BINARY_LENGTH + 1);
    convertDecimalToBinary(decimalNumber, binaryNumber);
    printBinaryNumber(binaryNumber);

    return 0;
}

void convertDecimalToBinary(int decimalNumber, char binaryNumber[]) {
    int divisor = 1 << (BINARY_LENGTH - 1);
    int remainder;

    for (int i = 0; i < BINARY_LENGTH; ++i) {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber[BINARY_LENGTH - i - 1] = (remainder + '0');
    }
}

void printBinaryNumber(char binaryNumber[]) {
    puts("// A Romeo and Juliet binary converter tale //");
    puts("int decimal_number = 0b");

    for (int i = 0; i < BINARY_LENGTH; ++i) {
        if (binaryNumber[BINARY_LENGTH - i - 1] == '1') {
            if (i == BINARY_LENGTH - 1) {
                printf(" %d", binaryNumber[BINARY_LENGTH - i - 1]);
            } else {
                printf(" %d, ", binaryNumber[BINARY_LENGTH - i - 1]);
            }
        }

        if ((i + 1) % 4 == 0 && i < BINARY_LENGTH - 1) {
            printf("0x");
        }
    }

    puts(";");
    puts("printf(\"Decimal: %d, Binary: %s\\n\", decimal_number, binary_number);");
}