//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_LENGTH 33  // Max length for binary representation + null terminator

// Function to convert integer to binary string
void intToBinary(int n, char *binaryStr) {
    for (int i = 0; i < 32; i++) {
        binaryStr[31 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[32] = '\0'; // Null-terminate the string
}

// Function to perform bitwise AND operation
void bitwiseAnd(int a, int b) {
    int result = a & b;
    char binaryA[BINARY_LENGTH], binaryB[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(b, binaryB);
    intToBinary(result, binaryResult);
    printf("AND Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("B: %s (%d)\n", binaryB, b);
    printf("Result: %s (%d)\n\n", binaryResult, result);
}

// Function to perform bitwise OR operation
void bitwiseOr(int a, int b) {
    int result = a | b;
    char binaryA[BINARY_LENGTH], binaryB[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(b, binaryB);
    intToBinary(result, binaryResult);
    printf("OR Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("B: %s (%d)\n", binaryB, b);
    printf("Result: %s (%d)\n\n", binaryResult, result);
}

// Function to perform bitwise XOR operation
void bitwiseXor(int a, int b) {
    int result = a ^ b;
    char binaryA[BINARY_LENGTH], binaryB[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(b, binaryB);
    intToBinary(result, binaryResult);
    printf("XOR Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("B: %s (%d)\n", binaryB, b);
    printf("Result: %s (%d)\n\n", binaryResult, result);
}

// Function to perform bitwise NOT operation
void bitwiseNot(int a) {
    int result = ~a;
    char binaryA[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(result, binaryResult);
    printf("NOT Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("Result: %s (%d)\n\n", binaryResult, result);
}

// Function for left shift operation
void leftShift(int a, int shift) {
    int result = a << shift;
    char binaryA[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(result, binaryResult);
    printf("Left Shift Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("Result (A << %d): %s (%d)\n\n", shift, binaryResult, result);
}

// Function for right shift operation
void rightShift(int a, int shift) {
    int result = a >> shift;
    char binaryA[BINARY_LENGTH], binaryResult[BINARY_LENGTH];
    intToBinary(a, binaryA);
    intToBinary(result, binaryResult);
    printf("Right Shift Operation:\n");
    printf("A: %s (%d)\n", binaryA, a);
    printf("Result (A >> %d): %s (%d)\n\n", shift, binaryResult, result);
}

// Main function to execute the program
int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <operation> <number1> <number2/shift>\n", argv[0]);
        printf("Operations: AND | OR | XOR | NOT | LSHIFT | RSHIFT\n");
        return 1;
    }

    char *operation = argv[1];
    int num1 = atoi(argv[2]);
    int num2 = (argc > 3) ? atoi(argv[3]) : 0; // Use second number or default to 0

    if (strcmp(operation, "AND") == 0) {
        bitwiseAnd(num1, num2);
    } else if (strcmp(operation, "OR") == 0) {
        bitwiseOr(num1, num2);
    } else if (strcmp(operation, "XOR") == 0) {
        bitwiseXor(num1, num2);
    } else if (strcmp(operation, "NOT") == 0) {
        bitwiseNot(num1);
    } else if (strcmp(operation, "LSHIFT") == 0) {
        leftShift(num1, num2);
    } else if (strcmp(operation, "RSHIFT") == 0) {
        rightShift(num1, num2);
    } else {
        printf("Invalid operation!\n");
        return 1;
    }

    return 0;
}