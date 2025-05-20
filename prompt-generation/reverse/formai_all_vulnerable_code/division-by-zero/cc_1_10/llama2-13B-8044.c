//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024

int main() {
    int num1, num2, sum, diff, mult, div;
    char op;
    char line[MAX_LENGTH];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 1;
    div = 1;

    // Get the first number from the user
    printf("Enter the first number: ");
    fgets(line, MAX_LENGTH, stdin);
    sscanf(line, "%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    fgets(line, MAX_LENGTH, stdin);
    sscanf(line, "%d", &num2);

    // Get the operator from the user
    printf("Enter the operator (+, -, *, /): ");
    fgets(line, MAX_LENGTH, stdin);
    sscanf(line, "%c", &op);

    // Perform the operation
    switch (op) {
        case '+':
            sum = num1 + num2;
            break;
        case '-':
            diff = num1 - num2;
            break;
        case '*':
            mult = num1 * num2;
            break;
        case '/':
            div = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 1;
    }

    // Print the result
    printf("Result: %d\n", sum);

    return 0;
}