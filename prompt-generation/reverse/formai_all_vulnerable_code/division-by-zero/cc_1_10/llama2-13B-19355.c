//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1e-100
#define MAX_VALUE 1e100

int main() {
    int num1, num2, sum;
    char op;

    // Invasive math exercises!

    printf("Welcome to the Invasive Math Exercise Program!\n");

    // Exercise 1: Add two numbers
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    if (op == '+') {
        printf("Addition: ");
        sum = num1 + getRandomNumber();
        printf("%d\n", sum);
    } else {
        printf("Invalid operation. Please try again.\n");
        exit(1);
    }

    // Exercise 2: Subtract two numbers
    printf("Enter two numbers: ");
    scanf("%d%c", &num2, &op);
    if (op == '-') {
        printf("Subtraction: ");
        sum = num1 - num2;
        printf("%d\n", sum);
    } else {
        printf("Invalid operation. Please try again.\n");
        exit(1);
    }

    // Exercise 3: Multiply two numbers
    printf("Enter two numbers: ");
    scanf("%d%c", &num1, &op);
    if (op == '*') {
        printf("Multiplication: ");
        sum = num1 * getRandomNumber();
        printf("%d\n", sum);
    } else {
        printf("Invalid operation. Please try again.\n");
        exit(1);
    }

    // Exercise 4: Divide two numbers
    printf("Enter two numbers: ");
    scanf("%d%c", &num2, &op);
    if (op == '/') {
        printf("Division: ");
        sum = num1 / num2;
        printf("%.2f\n", sum);
    } else {
        printf("Invalid operation. Please try again.\n");
        exit(1);
    }

    // Exercise 5: Calculate the square root of a number
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Square root: %.2f\n", sqrt(num1));

    // Exercise 6: Calculate the absolute value of a number
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Absolute value: %d\n", abs(num1));

    // Exercise 7: Calculate the sine, cosine, and tangent of an angle
    printf("Enter an angle in degrees: ");
    scanf("%.2f", &num1);
    printf("Sine: %.2f\n", sin(num1));
    printf("Cosine: %.2f\n", cos(num1));
    printf("Tangent: %.2f\n", tan(num1));

    return 0;
}

// Utility function to generate a random number between two values
int getRandomNumber() {
    int low = 1;
    int high = MAX_VALUE;
    int random = low + (high - low) * (double)rand() / RAND_MAX;
    return random;
}