//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BITS 32
#define DEFAULT_BASE 10

int power(int base, int exponent) {
    int result = 1;
    while (exponent--) {
        result *= base;
    }
    return result;
}
//helper function to convert a decimal number to binary format
unsigned int decimalToBinary(int decimalNumber) {
    int currentPowerOfTwo = MAX_BITS - 1;
    unsigned int result = 0;
    while (currentPowerOfTwo >= 0) {
        int currentPowerValue = power(2, currentPowerOfTwo);
        if (decimalNumber >= currentPowerValue) {
            decimalNumber -= currentPowerValue;
            result |= (1 << currentPowerOfTwo);
        }
        currentPowerOfTwo--;
    }
    return result;
}

//helper function to convert a binary number to decimal format
int binaryToDecimal(unsigned int binaryNumber) {
    int result = 0;
    int currentBitPosition = 0;
    while (binaryNumber > 0) {
        int currentBit = binaryNumber % 10;
        result += currentBit * power(2, currentBitPosition);
        currentBitPosition++;
        binaryNumber /= 10;
    }
    return result;
}

int main(int argc, char** argv) {
    int inputNumber;
    int inputBase = DEFAULT_BASE;
    if (argc == 2) {
        inputNumber = atoi(argv[1]);
    } else if (argc == 3) {
        inputNumber = atoi(argv[1]);
        inputBase = atoi(argv[2]);
    } else {
        printf("Usage: %s <number> [input base]\n", argv[0]);
        return 1;
    }
    if (inputBase != 10) {
        //first convert from input base to decimal
        int decimalValue = 0;
        int currentPowerOfInputBase = 0;
        char* inputNumberStr = malloc(strlen(argv[1]) * sizeof(char));
        strcpy(inputNumberStr, argv[1]);
        for (int i = strlen(inputNumberStr) - 1; i >= 0; i--) {
            char currentChar = inputNumberStr[i];
            int currentValue = 0;
            if (currentChar >= '0' && currentChar <= '9') {
                currentValue = currentChar - '0';
            } else {
                currentValue = currentChar - 'A' + 10;
            }
            decimalValue += currentValue * power(inputBase, currentPowerOfInputBase);
            currentPowerOfInputBase++;
        }
        inputNumber = decimalValue;
    }
    //now we have a decimal number, let's convert to binary
    unsigned int result = decimalToBinary(inputNumber);
    printf("Result in binary: %u\n", result);
    return 0;
}