//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERANDS 5
#define MAX_OPERATORS 5

// Define a struct to hold the operands and operators
typedef struct {
    int num;
    char operator;
} operand_t;

// Define an array to hold the operands and operators
operand_t operands[MAX_OPERANDS];

// Define a function to parse the input string and store the operands and operators in the array
void parse_input(char *input);

// Define a function to perform the arithmetic operations
void perform_operations(void);

int main() {
    // Get the input from the user
    char input[100];
    printf("Enter an arithmetic expression: ");
    fgets(input, 100, stdin);

    // Parse the input and store the operands and operators in the array
    parse_input(input);

    // Perform the arithmetic operations
    perform_operations();

    return 0;
}

// Define a function to parse the input string and store the operands and operators in the array
void parse_input(char *input) {
    int i = 0;
    char operator;

    // Loop through the input string
    for (; i < strlen(input); i++) {
        // Check if the current character is a number
        if (isdigit(input[i])) {
            // If it is a number, store it in the operands array
            operands[i].num = atoi(input + i);
        } else {
            // If it is an operator, store it in the operands array
            operands[i].operator = input[i];
        }
    }
}

// Define a function to perform the arithmetic operations
void perform_operations(void) {
    int result = 0;

    // Loop through the operands and perform the operations
    for (int i = 0; i < MAX_OPERANDS; i++) {
        switch (operands[i].operator) {
            case '+':
                result += operands[i].num;
                break;
            case '-':
                result -= operands[i].num;
                break;
            case '*':
                result *= operands[i].num;
                break;
            case '/':
                result /= operands[i].num;
                break;
            default:
                break;
        }
    }

    // Print the result
    printf("Result: %d\n", result);
}