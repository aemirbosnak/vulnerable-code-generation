//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *message;
    int line;
} Error;

Error errors[MAX_ERRORS];
int error_count = 0;

void add_error(const char *message, int line) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors\n");
        exit(1);
    }
    errors[error_count].message = strdup(message);
    errors[error_count].line = line;
    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found\n");
        return;
    }
    printf("Errors found:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%d: %s\n", errors[i].line, errors[i].message);
    }
}

int main() {
    int x = 5;
    int y = 0;

    if (x == 0) {
        add_error("Division by zero", __LINE__);
        return 1;
    }

    int z = x / y;

    if (z == 0) {
        add_error("Result is zero", __LINE__);
        return 1;
    }

    printf("Result: %d\n", z);
    print_errors();

    return 0;
}