//Falcon-180B DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_ERROR_MESSAGES 100

struct error_message {
    int line_number;
    char *message;
};

int error_count = 0;
struct error_message errors[MAX_ERROR_MESSAGES];

void add_error(int line_number, const char *format,...) {
    va_list args;
    char message[512];

    if (error_count >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error: Too many errors! ");
        exit(1);
    }

    errors[error_count].line_number = line_number;
    va_start(args, format);
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    fprintf(stderr, "Error at line %d: %s\n", line_number, message);
    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found! ");
        return;
    }

    printf("Found %d errors:\n", error_count);
    for (int i = 0; i < error_count; i++) {
        printf("Line %d: %s\n", errors[i].line_number, errors[i].message);
    }
}

int main() {
    int a = 10;
    int b = 0;
    int c = a / b;

    if (c == 0) {
        add_error(__LINE__, "Division by zero is not allowed! ");
    }

    int d = 20;
    int e = 5;
    int f = d / e;

    if (f!= 4) {
        add_error(__LINE__, "Unexpected result: %d!= 4", f);
    }

    print_errors();

    return 0;
}