//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

/* Recursive function to calculate sum of first n natural numbers */
int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n-1);
    }
}

/* Dynamic memory allocation function to allocate an array of integers */
int* allocateIntArray(int n) {
    int *array = (int*) malloc(n * sizeof(int));

    /* Populate the array with 0's */
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }

    return array;
}

/* Recursive function to find the factorial of n */
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n = 5;

    /* Calculate the sum of the first n natural numbers */
    int sumOfFirstN = sum(n);
    printf("Sum of the first %d natural numbers: %d\n", n, sumOfFirstN);

    /* Dynamically allocate an array of size n */
    int *array = allocateIntArray(n);

    /* Populate the array with factorials */
    for (int i = 0; i < n; i++) {
        array[i] = factorial(i);
    }

    /* Print the array */
    printf("Factorial array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    /* Free the dynamically allocated memory */
    free(array);

    return 0;
}