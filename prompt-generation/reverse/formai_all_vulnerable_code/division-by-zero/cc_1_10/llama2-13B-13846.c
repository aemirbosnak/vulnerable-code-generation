//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_OPERANDS 5
#define MAX_NUM_DIGITS 10

// Structure to hold the operands and result
typedef struct {
    int num_digits;
    char digits[MAX_NUM_DIGITS];
} operand_t;

// Function to perform arithmetic operations
void perform_arithm(operand_t *operand1, operand_t *operand2, char op) {
    int result;

    // Check for invalid inputs
    if (operand1->num_digits == 0 || operand2->num_digits == 0) {
        printf("Invalid input\n");
        return;
    }

    // Perform arithmetic operation
    switch (op) {
        case '+':
            result = strtol(operand1->digits, NULL, 10) + strtol(operand2->digits, NULL, 10);
            break;
        case '-':
            result = strtol(operand1->digits, NULL, 10) - strtol(operand2->digits, NULL, 10);
            break;
        case '*':
            result = strtol(operand1->digits, NULL, 10) * strtol(operand2->digits, NULL, 10);
            break;
        case '/':
            result = strtol(operand1->digits, NULL, 10) / strtol(operand2->digits, NULL, 10);
            break;
        default:
            printf("Invalid operator\n");
            return;
    }

    // Print the result
    printf("%d\n", result);
}

int main() {
    // Get the operands and operator from the user
    char op[2];
    operand_t operand1, operand2;

    printf("Enter the first operand: ");
    fgets(operand1.digits, MAX_NUM_DIGITS, stdin);
    operand1.num_digits = strlen(operand1.digits);

    printf("Enter the second operand: ");
    fgets(operand2.digits, MAX_NUM_DIGITS, stdin);
    operand2.num_digits = strlen(operand2.digits);

    printf("Enter the operator (+, -, *, /): ");
    fread(op, 1, 2, stdin);

    // Perform the arithmetic operation
    perform_arithm(&operand1, &operand2, op[0]);

    return 0;
}