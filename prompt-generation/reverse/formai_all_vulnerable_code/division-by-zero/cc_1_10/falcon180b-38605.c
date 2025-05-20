//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num() {
    return rand() % 100;
}

// Function to perform arithmetic operations
int arithmetic_op(int num1, int num2, char op) {
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2!= 0) {
                return num1 / num2;
            } else {
                printf("Error: Division by zero\n");
                exit(1);
            }
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }
}

int main() {
    int num1, num2, result, choice;
    char op;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers
    num1 = rand_num();
    num2 = rand_num();

    // Prompt user to choose operation
    printf("Enter the arithmetic operation (+, -, *, /): ");
    scanf("%c", &op);

    // Perform arithmetic operation
    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }

    // Prompt user to choose next operation
    printf("Do you want to perform another arithmetic operation? (y/n): ");
    scanf("%c", &choice);

    // Continue with next operation
    while(choice == 'y' || choice == 'Y') {
        // Generate new random numbers
        num1 = rand_num();
        num2 = rand_num();

        // Prompt user to choose operation
        printf("Enter the arithmetic operation (+, -, *, /): ");
        scanf("%c", &op);

        // Perform arithmetic operation
        switch(op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if(num2!= 0) {
                    result = num1 / num2;
                } else {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                break;
            default:
                printf("Invalid operation\n");
                exit(1);
        }

        // Prompt user to choose next operation
        printf("Do you want to perform another arithmetic operation? (y/n): ");
        scanf("%c", &choice);
    }

    return 0;
}