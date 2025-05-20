//Falcon-180B DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *error_message;
    int line_number;
} Error;

int error_count = 0;
Error errors[MAX_ERRORS];

void add_error(char *message, int line_number) {
    if (error_count >= MAX_ERRORS) {
        printf("Error: Maximum number of errors reached.\n");
        return;
    }

    errors[error_count].error_message = strdup(message);
    errors[error_count].line_number = line_number;

    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Errors found:\n");
    for (int i = 0; i < error_count; i++) {
        printf("Line %d: %s\n", errors[i].line_number, errors[i].error_message);
    }
}

int main() {
    int a = 1;
    int b = 0;
    int c = a / b;

    if (c!= 0) {
        add_error("Division by zero", __LINE__);
    }

    if (a == b) {
        add_error("a and b are equal", __LINE__);
    }

    return 0;
}