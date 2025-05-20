//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    double x, y, z;
    char operation;

    printf("Welcome to the Mathematical Expression Evaluator!\n");

    // Read the number of operands from the user
    printf("Enter the number of operands: ");
    scanf("%d", &n);

    // Create an array to store the operands
    double operands[n];
    for (int i = 0; i < n; i++) {
        printf("Operand %d: ", i + 1);
        scanf("%lf", &operands[i]);
    }

    // Read the operation from the user
    printf("Enter the operation (+, -, *, /, ^): ");
    scanf(" %c", &operation);

    // Evaluate the expression
    switch (operation) {
        case '+':
            z = 0;
            for (int i = 0; i < n; i++) {
                z += operands[i];
            }
            break;
        case '-':
            z = 0;
            for (int i = 0; i < n; i++) {
                z -= operands[i];
            }
            break;
        case '*':
            z = 1;
            for (int i = 0; i < n; i++) {
                z *= operands[i];
            }
            break;
        case '/':
            z = 1;
            for (int i = 0; i < n; i++) {
                z /= operands[i];
            }
            break;
        case '^':
            z = 1;
            for (int i = 0; i < n; i++) {
                z *= pow(operands[i], i);
            }
            break;
        default:
            printf("Invalid operation. Please try again.\n");
            return 1;
    }

    // Print the result
    printf("Result: %lf\n", z);

    return 0;
}