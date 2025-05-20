//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100000

int main() {
    int num1, num2, sum, diff, mult, div, mod;
    char operation;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    mod = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /, %): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
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
        case '%':
            mod = num1 % num2;
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 0;
    }

    // Print the results
    printf("Result of %c %d and %d is %d\n", operation, num1, num2, sum);
    printf("Result of %c %d and %d is %d\n", operation, num1, num2, diff);
    printf("Result of %c %d and %d is %d\n", operation, num1, num2, mult);
    printf("Result of %c %d and %d is %d\n", operation, num1, num2, div);
    printf("Result of %c %d and %d is %d\n", operation, num1, num2, mod);

    return 0;
}