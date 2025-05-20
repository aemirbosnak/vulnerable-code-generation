//Falcon-180B DATASET v1.0 Category: Error handling ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *message;
    int line_number;
} Error;

int error_count = 0;
Error errors[MAX_ERRORS];

void add_error(char *message, int line_number) {
    if (error_count >= MAX_ERRORS) {
        printf("Error: Too many errors!\n");
        exit(1);
    }

    errors[error_count].message = strdup(message);
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
        printf("Line %d: %s\n", errors[i].line_number, errors[i].message);
    }
}

int main() {
    int x = 5;
    int y = 0;

    if (x == 0) {
        add_error("Division by zero error", __LINE__);
    } else {
        int z = x / y;
        printf("Result: %d\n", z);
    }

    print_errors();

    return 0;
}