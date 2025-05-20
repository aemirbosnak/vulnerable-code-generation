//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A reflection on the nature of arithmetic

int main() {
    int x, y, z;
    char operation;

    printf("Welcome to the Arithmetic Reflection\n");

    // Ask the user for the first number
    printf("Enter the first number: ");
    scanf("%d", &x);

    // Ask the user for the second number
    printf("Enter the second number: ");
    scanf("%d", &y);

    // Ask the user for the operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch (operation) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // Reflect on the result
    printf("The result of %d + %d is %d\n", x, y, z);
    printf("The result of %d - %d is %d\n", x, y, z);
    printf("The result of %d * %d is %d\n", x, y, z);
    printf("The result of %d / %d is %d\n", x, y, z);

    return 0;
}