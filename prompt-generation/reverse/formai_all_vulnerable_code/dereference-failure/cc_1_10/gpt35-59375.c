//FormAI DATASET v1.0 Category: Bitwise operations ; Style: innovative
#include <stdio.h>

// A struct to hold an integer value and its corresponding binary representation
typedef struct BinaryNum {
    int value;
    char* binary;
} BinaryNum;

// Converts an integer to its corresponding binary representation
char* intToBinary(int num) {
    int i;
    char* binary = malloc(sizeof(char) * 33);
    for (i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        binary[31 - i] = (bit == 1) ? '1' : '0';
    }
    binary[32] = '\0';
    return binary;
}

// Performs the bitwise AND operation on two integers
BinaryNum bitwiseAND(int num1, int num2) {
    int result = num1 & num2;
    char* binary = intToBinary(result);
    BinaryNum binResult = {result, binary};
    return binResult;
}

// Performs the bitwise OR operation on two integers
BinaryNum bitwiseOR(int num1, int num2) {
    int result = num1 | num2;
    char* binary = intToBinary(result);
    BinaryNum binResult = {result, binary};
    return binResult;
}

// Performs the bitwise XOR operation on two integers
BinaryNum bitwiseXOR(int num1, int num2) {
    int result = num1 ^ num2;
    char* binary = intToBinary(result);
    BinaryNum binResult = {result, binary};
    return binResult;
}

// Shifts an integer to the left by a given number of bits
BinaryNum bitwiseLeftShift(int num, int shift) {
    int result = num << shift;
    char* binary = intToBinary(result);
    BinaryNum binResult = {result, binary};
    return binResult;
}

// Shifts an integer to the right by a given number of bits
BinaryNum bitwiseRightShift(int num, int shift) {
    int result = num >> shift;
    char* binary = intToBinary(result);
    BinaryNum binResult = {result, binary};
    return binResult;
}

int main() {
    int num1 = 42;
    int num2 = 27;

    // Perform bitwise AND on num1 and num2 and print the result in both decimal and binary formats
    BinaryNum resultAND = bitwiseAND(num1, num2);
    printf("%d & %d = %d (%s)\n", num1, num2, resultAND.value, resultAND.binary);

    // Perform bitwise OR on num1 and num2 and print the result in both decimal and binary formats
    BinaryNum resultOR = bitwiseOR(num1, num2);
    printf("%d | %d = %d (%s)\n", num1, num2, resultOR.value, resultOR.binary);

    // Perform bitwise XOR on num1 and num2 and print the result in both decimal and binary formats
    BinaryNum resultXOR = bitwiseXOR(num1, num2);
    printf("%d ^ %d = %d (%s)\n", num1, num2, resultXOR.value, resultXOR.binary);

    // Shift num1 to the left by 2 bits and print the result in both decimal and binary formats
    BinaryNum resultLeftShift = bitwiseLeftShift(num1, 2);
    printf("%d << 2 = %d (%s)\n", num1, resultLeftShift.value, resultLeftShift.binary);

    // Shift num1 to the right by 2 bits and print the result in both decimal and binary formats
    BinaryNum resultRightShift = bitwiseRightShift(num1, 2);
    printf("%d >> 2 = %d (%s)\n", num1, resultRightShift.value, resultRightShift.binary);

    return 0;
}