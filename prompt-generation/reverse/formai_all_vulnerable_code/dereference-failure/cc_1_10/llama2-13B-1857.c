//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUMBER 1000
#define MAX_OPERATIONS 10

// Structure to store number and operation
typedef struct {
    int number;
    char operation;
} operation_t;

// Function to perform an operation on two numbers
void perform_operation(operation_t *op1, operation_t *op2) {
    int result;
    switch (op1->operation) {
        case '+':
            result = op1->number + op2->number;
            break;
        case '-':
            result = op1->number - op2->number;
            break;
        case '*':
            result = op1->number * op2->number;
            break;
        case '/':
            result = op1->number / op2->number;
            break;
        default:
            result = -1;
            break;
    }
    op1->number = result;
}

// Function to perform a series of operations
void perform_series_of_operations(operation_t *operations, int num_operations) {
    int i;
    for (i = 0; i < num_operations; i++) {
        perform_operation(operations + i, operations + i + 1);
    }
}

// Function to print the results
void print_results(operation_t *operations, int num_operations) {
    int i;
    for (i = 0; i < num_operations; i++) {
        printf("%d %c %d\n", operations[i].number, operations[i].operation, operations[i + 1].number);
    }
}

int main() {
    srand(time(NULL)); // For random numbers

    // Create an array of operations
    operation_t operations[MAX_OPERATIONS];
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        operations[i].number = rand() % MAX_NUMBER + 1;
        operations[i].operation = '+'; // Start with addition
    }

    // Perform a series of operations
    perform_series_of_operations(operations, MAX_OPERATIONS);

    // Print the results
    print_results(operations, MAX_OPERATIONS);

    return 0;
}