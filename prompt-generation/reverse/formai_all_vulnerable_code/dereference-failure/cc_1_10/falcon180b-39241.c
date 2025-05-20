//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *message;
    int line;
    int column;
} Error;

typedef struct {
    Error *errors;
    int error_count;
} ErrorStack;

void init_error_stack(ErrorStack *stack) {
    stack->errors = (Error *) malloc(MAX_ERRORS * sizeof(Error));
    stack->error_count = 0;
}

void push_error(ErrorStack *stack, char *message, int line, int column) {
    if (stack->error_count >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors.\n");
        exit(1);
    }

    stack->errors[stack->error_count].message = strdup(message);
    stack->errors[stack->error_count].line = line;
    stack->errors[stack->error_count].column = column;

    stack->error_count++;
}

void print_errors(ErrorStack *stack) {
    if (stack->error_count == 0) {
        printf("No errors.\n");
    } else {
        printf("Errors:\n");
        for (int i = 0; i < stack->error_count; i++) {
            printf("Line %d, Column %d: %s\n", stack->errors[i].line, stack->errors[i].column, stack->errors[i].message);
        }
    }
}

void free_error_stack(ErrorStack *stack) {
    for (int i = 0; i < stack->error_count; i++) {
        free(stack->errors[i].message);
    }

    free(stack->errors);
}

int main() {
    ErrorStack error_stack;

    init_error_stack(&error_stack);

    push_error(&error_stack, "Syntax error on line 3", 3, 5);
    push_error(&error_stack, "Undefined variable on line 7", 7, 10);
    push_error(&error_stack, "Division by zero on line 12", 12, 15);

    print_errors(&error_stack);

    free_error_stack(&error_stack);

    return 0;
}