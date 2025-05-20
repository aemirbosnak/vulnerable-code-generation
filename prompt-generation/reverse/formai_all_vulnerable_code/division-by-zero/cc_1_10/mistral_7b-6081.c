//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MIN_NUMBER -INT_MAX
#define MAX_NUMBER INT_MAX

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number1> <number2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Paranoid checks
    if (num1 < MIN_NUMBER || num1 > MAX_NUMBER) {
        fprintf(stderr, "Invalid number %d. Number should be within [-%d, %d].\n", num1, MIN_NUMBER, MAX_NUMBER);
        exit(EXIT_FAILURE);
    }

    if (num2 < MIN_NUMBER || num2 > MAX_NUMBER) {
        fprintf(stderr, "Invalid number %d. Number should be within [-%d, %d].\n", num2, MIN_NUMBER, MAX_NUMBER);
        exit(EXIT_FAILURE);
    }

    // Arithmetic operations with paranoid checks
    int sum = num1 + num2;
    if (sum < (num1 + num2)) {
        fprintf(stderr, "Error in addition. Result: %d\n", sum);
        exit(EXIT_FAILURE);
    }

    int diff = num1 - num2;
    if (diff < (num1 - num2)) {
        fprintf(stderr, "Error in subtraction. Result: %d\n", diff);
        exit(EXIT_FAILURE);
    }

    int prod = num1 * num2;
    if (prod < (num1 * num2)) {
        fprintf(stderr, "Error in multiplication. Result: %d\n", prod);
        exit(EXIT_FAILURE);
    }

    int quot = num1 / num2;
    if (num1 % num2 != 0 && quot * num2 != num1) {
        fprintf(stderr, "Error in division. Number %d is not divisible by %d.\n", num1, num2);
        exit(EXIT_FAILURE);
    }

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
    printf("Quotient: %d\n", quot);

    return EXIT_SUCCESS;
}