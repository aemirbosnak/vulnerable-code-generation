//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Function to reverse a string using bitwise operations
char* reverseString(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    memset(reversed, 0, len + 1);
    for (int i = 0; i < len; i++) {
        reversed[len - 1 - i] = str[i];
    }
    return reversed;
}

// Function to check if a number is a power of two using bitwise operations
int isPowerOfTwo(int n) {
    if (n <= 0) {
        return 0;
    }
    while (n > 1) {
        if (n % 2!= 0) {
            return 0;
        }
        n /= 2;
    }
    return 1;
}

// Function to count the number of set bits in an integer using bitwise operations
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

// Function to swap two variables without using a third variable
void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    char* str = "Hello, world!";
    char* reversed = reverseString(str);
    printf("Reversed string: %s\n", reversed);

    int n = 8;
    if (isPowerOfTwo(n)) {
        printf("%d is a power of two.\n", n);
    } else {
        printf("%d is not a power of two.\n", n);
    }

    int m = 15;
    printf("Number of set bits in %d: %d\n", m, countSetBits(m));

    int x = 5;
    int y = 10;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}