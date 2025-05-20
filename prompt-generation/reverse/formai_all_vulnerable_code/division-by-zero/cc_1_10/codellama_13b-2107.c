//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: light-weight
// C Scientific Calculator Implementation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERAND_SIZE 100
#define MAX_OPERATORS 10

// Function to get a string from the user
void get_string(char* str, int n) {
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = 0;
}

// Function to calculate the result of a given expression
int calculate(char* expression) {
    int result = 0;
    int operand1, operand2, operand3;
    char operator;
    char* ptr = expression;

    // Parse the expression
    while (*ptr != '\0') {
        operand1 = atoi(ptr);
        ptr += strcspn(ptr, " +-*/");
        operator = *ptr;
        ptr++;
        operand2 = atoi(ptr);
        ptr += strcspn(ptr, " +-*/");

        switch (operator) {
            case '+':
                operand3 = operand1 + operand2;
                break;
            case '-':
                operand3 = operand1 - operand2;
                break;
            case '*':
                operand3 = operand1 * operand2;
                break;
            case '/':
                operand3 = operand1 / operand2;
                break;
            default:
                operand3 = 0;
        }

        result = operand3;
    }

    return result;
}

int main() {
    char expression[MAX_OPERAND_SIZE];
    char operator[MAX_OPERATORS];
    int operand1, operand2, result;

    printf("Enter the expression: ");
    get_string(expression, MAX_OPERAND_SIZE);

    result = calculate(expression);

    printf("Result: %d\n", result);

    return 0;
}