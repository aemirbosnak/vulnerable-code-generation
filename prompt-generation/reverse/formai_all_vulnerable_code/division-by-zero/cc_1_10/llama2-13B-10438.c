//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

int main() {
    // Declare variables
    int num1, num2, sum, difference, product, quotient, remainder;
    float average, standardDeviation;
    char operation[5];

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, x, /, or ^): ");
    scanf(" %c", &operation[0]);

    // Perform the operation
    if (operation[0] == '+') {
        sum = num1 + num2;
    } else if (operation[0] == '-') {
        difference = num1 - num2;
    } else if (operation[0] == '*') {
        product = num1 * num2;
    } else if (operation[0] == '/') {
        quotient = num1 / num2;
        remainder = num1 % num2;
    } else if (operation[0] == '^') {
        float base = num1;
        for (int i = 1; i <= num2; i++) {
            base *= num1;
        }
        product = base;
    }

    // Calculate the average and standard deviation
    average = (num1 + num2 + sum + product) / 4;
    standardDeviation = sqrt(((product - average * 2) * (product - average * 2)) / 12);

    // Print the results
    printf("The result of %d %c %d is %d\n", num1, operation[0], num2, sum);
    printf("The average is %f\n", average);
    printf("The standard deviation is %f\n", standardDeviation);

    // Add some magic to the program
    if (sum % MAGIC_NUMBER == 0) {
        printf("Magic happens when the result is a multiple of 42\n");
    }

    return 0;
}