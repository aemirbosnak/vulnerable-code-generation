//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void decimalToBinary(int n, char *binaryStr) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        binaryStr[i] = (n % 2) + '0'; // Get the least significant bit
        n /= 2; // Shift right
    }
    binaryStr[MAX_BITS] = '\0'; // Null-terminate the string
}

void printBinary(char *binaryStr) {
    int leadingZero = 1; // Flag to skip leading zeros
    for (int i = 0; i < MAX_BITS; i++) {
        if (binaryStr[i] == '1') {
            leadingZero = 0; // We found the first '1'
        }
        if (!leadingZero) {
            putchar(binaryStr[i]); // Print binary bit
        }
    }
    if (leadingZero) {
        putchar('0'); // If all bits were zero
    }
    putchar('\n'); // Newline after the number
}

void convertAndPrint(int n) {
    char binaryStr[MAX_BITS + 1];
    decimalToBinary(n, binaryStr);
    printf("Decimal: %d\nBinary: ", n);
    printBinary(binaryStr);
}

void convertArrayToBinary(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        convertAndPrint(array[i]);
    }
}

void fillArrayWithRandomInts(int *array, size_t size, int maxValue) {
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % (maxValue + 1);
    }
}

void menu() {
    printf("Binary Converter Menu\n");
    printf("======================\n");
    printf("1. Convert a single integer\n");
    printf("2. Convert an array of random integers\n");
    printf("3. Exit\n");
    printf("======================\n");
}

int main() {
    srand((unsigned int)time(NULL)); // Seed for random number generation
    while (1) {
        menu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int number;
            printf("Enter an integer: ");
            scanf("%d", &number);
            convertAndPrint(number);
        } else if (choice == 2) {
            size_t size;
            int maxValue;
            printf("Enter the number of integers to generate: ");
            scanf("%zu", &size);
            printf("Enter the maximum value for generated integers: ");
            scanf("%d", &maxValue);
            int *array = (int *)malloc(size * sizeof(int));
            if (array == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            fillArrayWithRandomInts(array, size, maxValue);
            convertArrayToBinary(array, size);
            free(array);
        } else if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}