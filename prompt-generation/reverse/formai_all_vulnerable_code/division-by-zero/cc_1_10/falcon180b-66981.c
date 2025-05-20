//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX_ERRORS 100

typedef struct {
    char *message;
    int line_number;
} Error;

Error errors[MAX_ERRORS];
int error_count = 0;

void add_error(char *format,...) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Error: Too many errors.\n");
        exit(1);
    }

    va_list args;
    va_start(args, format);
    vsnprintf(errors[error_count].message, sizeof(errors[error_count].message), format, args);
    errors[error_count].line_number = __LINE__;
    va_end(args);

    error_count++;
}

int main() {
    int a = 1;
    int b = 0;
    int c = a / b;

    if (c!= 0) {
        add_error("Division by zero at line %d", __LINE__);
    }

    if (a > 10) {
        add_error("Value of a is greater than 10 at line %d", __LINE__);
    }

    if (b < 0) {
        add_error("Value of b is negative at line %d", __LINE__);
    }

    if (c == 0) {
        printf("Result is zero.\n");
    } else if (c > 0) {
        printf("Result is positive.\n");
    } else {
        printf("Result is negative.\n");
    }

    return 0;
}