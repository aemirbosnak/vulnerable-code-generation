//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAGIC_NUMBER 42

void math_exercise(int *arr, int size) {
    int i, j, sum = 0, product = 1;
    char op;

    // Exercise 1: Sum of Numbers
    printf("Exercise 1: Sum of Numbers\n");
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("The sum is: %d\n", sum);

    // Exercise 2: Product of Numbers
    printf("Exercise 2: Product of Numbers\n");
    for (i = 0; i < size; i++) {
        product *= arr[i];
    }
    printf("The product is: %d\n", product);

    // Exercise 3: Modulo
    printf("Exercise 3: Modulo\n");
    for (i = 0; i < size; i++) {
        sum = arr[i] % MAGIC_NUMBER;
        printf("%d mod %d = %d\n", arr[i], MAGIC_NUMBER, sum);
    }

    // Exercise 4: Greatest Common Divisor
    printf("Exercise 4: Greatest Common Divisor\n");
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] % arr[j] == 0) {
                break;
            }
        }
        if (j == size) {
            printf("No GCD found\n");
            break;
        }
        printf("GCD of %d and %d is %d\n", arr[i], arr[j], arr[i] % arr[j]);
    }

    // Exercise 5: Fibonacci Sequence
    printf("Exercise 5: Fibonacci Sequence\n");
    for (i = 0; i < size; i++) {
        sum = arr[i] + (arr[i - 1] + arr[i - 2]) % MAGIC_NUMBER;
        printf("%dth Fibonacci number is %d\n", i, sum);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    math_exercise(arr, size);
    return 0;
}