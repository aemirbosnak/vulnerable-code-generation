//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char op1, op2;
    char input[MAX_LENGTH];

    printf("Welcome to the C Math Exercise Program!\n");

    // Exercise 1: Addition
    printf("Enter two numbers: ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%d%c%d", &num1, &op1, &num2);
    if (op1 == '+') {
        sum = num1 + num2;
        printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    } else {
        printf("Invalid operator. Please enter a valid operator (+, -, x, /, or %).\n");
    }

    // Exercise 2: Subtraction
    printf("Enter two numbers: ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%d%c%d", &num1, &op1, &num2);
    if (op1 == '-') {
        difference = num1 - num2;
        printf("The difference of %d and %d is %d.\n", num1, num2, difference);
    } else {
        printf("Invalid operator. Please enter a valid operator (+, -, x, /, or %).\n");
    }

    // Exercise 3: Multiplication
    printf("Enter two numbers: ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%d%c%d", &num1, &op1, &num2);
    if (op1 == 'x') {
        product = num1 * num2;
        printf("The product of %d and %d is %d.\n", num1, num2, product);
    } else {
        printf("Invalid operator. Please enter a valid operator (+, -, x, /, or %).\n");
    }

    // Exercise 4: Division
    printf("Enter two numbers: ");
    fgets(input, MAX_LENGTH, stdin);
    sscanf(input, "%d%c%d", &num1, &op1, &num2);
    if (op1 == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
        printf("The quotient of %d and %d is %d, with a remainder of %d.\n", num1, num2, quotient, remainder);
    } else {
        printf("Invalid operator. Please enter a valid operator (+, -, x, /, or %).\n");
    }

    return 0;
}