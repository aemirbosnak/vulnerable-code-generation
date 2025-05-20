//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ERROR_MESSAGE_SIZE 2048

void handle_error(const char *file, int line, const char *func, const char *message, ...) {
    va_list args;
    va_start(args, message);

    char error_message[MAX_ERROR_MESSAGE_SIZE];
    vsnprintf(error_message, sizeof(error_message), message, args);
    va_end(args);

    printf("Error: %s, line %d, in function %s\n", error_message, line, func);

    if (file) {
        printf("  File: %s\n", file);
    }

    exit(EXIT_FAILURE);
}

int main() {
    int x = 0;
    char y[] = "hello";

    // Test 1: division by zero
    x = 10 / 0;
    if (x == -1) {
        handle_error(__FILE__, __LINE__, __FUNCTION__, "Division by zero");
    }

    // Test 2: invalid input
    y[0] = 'x';
    x = strtol(y, NULL, 10);
    if (x == 0) {
        handle_error(__FILE__, __LINE__, __FUNCTION__, "Invalid input");
    }

    // Test 3: null pointer dereference
    char *ptr = NULL;
    *ptr = 'x';
    if (ptr == NULL) {
        handle_error(__FILE__, __LINE__, __FUNCTION__, "Null pointer dereference");
    }

    return 0;
}