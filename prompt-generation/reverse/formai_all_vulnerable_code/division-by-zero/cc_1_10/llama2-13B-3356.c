//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_VALUE -100
#define MAX_VALUE 100

int main() {
    int num1, num2, sum, difference, product, quotient, remainder;
    char op;

    printf("Welcome to the Math Exercise Program!\n");

    // Exercise 1: Addition
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    scanf("%d%c", &num2, &op);
    sum = num1 + num2;
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);

    // Exercise 2: Subtraction
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    scanf("%d%c", &num2, &op);
    difference = num1 - num2;
    printf("The difference of %d and %d is %d.\n", num1, num2, difference);

    // Exercise 3: Multiplication
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    scanf("%d%c", &num2, &op);
    product = num1 * num2;
    printf("The product of %d and %d is %d.\n", num1, num2, product);

    // Exercise 4: Division
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    scanf("%d%c", &num2, &op);
    quotient = num1 / num2;
    remainder = num1 % num2;
    printf("The quotient of %d and %d is %d, with a remainder of %d.\n", num1, num2, quotient, remainder);

    // Exercise 5: Modulus
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    scanf("%d%c", &num2, &op);
    remainder = num1 % num2;
    printf("The modulus of %d and %d is %d.\n", num1, num2, remainder);

    // Exercise 6: Random Number Generation
    srand(time(NULL));
    int random_num = rand() % 100;
    printf("Here is a random number between 1 and 100: %d.\n", random_num);

    return 0;
}