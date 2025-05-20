//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BITS 32

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        putchar((num & (1U << i)) ? '1' : '0');
    }
    printf("\n");
}

// Function to perform bitwise operation on two numbers and display results
void bitwiseOperation(unsigned int a, unsigned int b) {
    unsigned int andResult = a & b;
    unsigned int orResult = a | b;
    unsigned int xorResult = a ^ b;
    unsigned int notA = ~a;
    unsigned int notB = ~b;
    unsigned int leftShiftA = a << 1; // Left shift a by 1
    unsigned int rightShiftA = a >> 1; // Right shift a by 1
    unsigned int leftShiftB = b << 1; // Left shift b by 1
    unsigned int rightShiftB = b >> 1; // Right shift b by 1

    printf("Input A: ");
    printBinary(a);
    printf("Input B: ");
    printBinary(b);

    printf("A & B:   ");
    printBinary(andResult);
    printf("A | B:   ");
    printBinary(orResult);
    printf("A ^ B:   ");
    printBinary(xorResult);
    printf("~A:      ");
    printBinary(notA);
    printf("~B:      ");
    printBinary(notB);
    printf("A << 1:  ");
    printBinary(leftShiftA);
    printf("A >> 1:  ");
    printBinary(rightShiftA);
    printf("B << 1:  ");
    printBinary(leftShiftB);
    printf("B >> 1:  ");
    printBinary(rightShiftB);
}

// Function to generate random numbers
unsigned int generateRandomNumber() {
    return rand() % (1 << MAX_BITS); // Limit the number to MAX_BITS bits
}

// Main function to bring the bit manipulation wonder to life
int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to the Bitwise Operations Odyssey!\n");
    printf("In this journey, we will explore some mysterious realms of numbers.\n");
    
    for (int i = 0; i < 3; i++) {
        printf("\nIteration %d:\n", i + 1);
        unsigned int a = generateRandomNumber();
        unsigned int b = generateRandomNumber();
        
        printf("Two magical numbers generated:\n");
        printf("Number A: %u\n", a);
        printf("Number B: %u\n", b);
        
        bitwiseOperation(a, b);
    }

    printf("The journey has come to an end.\n");
    printf("Remember: In the world of bits, every binary digit has a story to tell!\n");
    
    return 0;
}