//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise AND operation
int bitwise_and(int a, int b) {
    return a & b;
}

// Function to perform bitwise OR operation
int bitwise_or(int a, int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
int bitwise_xor(int a, int b) {
    return a ^ b;
}

// Function to perform bitwise NOT operation
int bitwise_not(int a) {
    return ~a;
}

// Function to perform left shift
int left_shift(int a, int positions) {
    return a << positions;
}

// Function to perform right shift
int right_shift(int a, int positions) {
    return a >> positions;
}

// Function to print binary representation of an integer
void print_binary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; --i) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to demonstrate all operations
void demonstrate_operations(int a, int b) {
    printf("Input A: %d, Input B: %d\n", a, b);
    
    printf("Bitwise AND: ");
    print_binary(bitwise_and(a, b));
    
    printf("Bitwise OR: ");
    print_binary(bitwise_or(a, b));
    
    printf("Bitwise XOR: ");
    print_binary(bitwise_xor(a, b));
    
    printf("Bitwise NOT A: ");
    print_binary(bitwise_not(a));
    
    printf("Left Shift A by 1: ");
    print_binary(left_shift(a, 1));
    
    printf("Right Shift A by 1: ");
    print_binary(right_shift(a, 1));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <integer A> <integer B>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    demonstrate_operations(a, b);
    
    return 0;
}