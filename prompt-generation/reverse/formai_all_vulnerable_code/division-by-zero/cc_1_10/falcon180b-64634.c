//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>

#define MAX_ERROR_MESSAGES 100

typedef struct {
    const char *file;
    int line;
    const char *function;
} error_location_t;

typedef struct {
    error_location_t location;
    const char *message;
} error_t;

static jmp_buf error_jmp_buf;
static int error_count = 0;
static error_t error_messages[MAX_ERROR_MESSAGES];

void error_occurred(const char *format,...) {
    if (error_count >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Too many errors occurred\n");
        exit(1);
    }

    va_list args;
    va_start(args, format);
    vsnprintf(error_messages[error_count].message, sizeof(error_messages[error_count].message), format, args);
    va_end(args);

    error_messages[error_count].location.file = __FILE__;
    error_messages[error_count].location.line = __LINE__;
    error_messages[error_count].location.function = __FUNCTION__;

    error_count++;
    longjmp(error_jmp_buf, 1);
}

void error_cleanup(void) {
    if (error_count > 0) {
        fprintf(stderr, "Errors occurred:\n");
        for (int i = 0; i < error_count; i++) {
            fprintf(stderr, "%s:%d in %s(): %s\n", error_messages[i].location.file, error_messages[i].location.line, error_messages[i].location.function, error_messages[i].message);
        }
    }
}

void my_function(int a, int b) {
    if (a == 0) {
        error_occurred("Division by zero is not allowed");
    }

    int result = b / a;

    if (result == 0) {
        error_occurred("Result of division is zero");
    }
}

int main(void) {
    if (setjmp(error_jmp_buf) == 0) {
        my_function(0, 5);
    }

    error_cleanup();

    return 0;
}