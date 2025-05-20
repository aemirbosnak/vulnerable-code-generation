//FormAI DATASET v1.0 Category: Calculator ; Style: lively
#include <stdio.h>

// This program is a fun little calculator that can perform basic arithmetic operations
// like addition, subtraction, multiplication and division. 

int main() {
    int num1, num2, result;
    char operator;

    // Greet the user and prompt them for the first number and the operator
    printf("Hello! I'm a calculator. Let's get started.\n");
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the operator: ");
    scanf("%s", &operator);

    // Check if the operator entered is valid and prompt the user
    // for the second number if it is.
    switch (operator) {
        case '+':
            printf("You selected addition. Enter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            break;
        case '-':
            printf("You selected subtraction. Enter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            break;
        case '*':
            printf("You selected multiplication. Enter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            break;
        case '/':
            printf("You selected division. Enter the second number: ");
            scanf("%d", &num2);
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator. Please try again.\n");
            main();
    }

    // Print the result and ask the user if they want to do another calculation
    printf("The result is: %d\n", result);
    printf("Do another calculation? (y/n): ");
    char choice;
    scanf("%s", &choice);

    // If the user chooses 'y', call main() again, otherwise exit the program
    if (choice == 'y') {
        main();
    } else {
        printf("Thanks for using the calculator. Goodbye!\n");
        return 0;
    }
}