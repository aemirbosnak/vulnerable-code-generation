//Falcon-180B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define MAX_ERRORS 100
#define ERROR_MSG_LEN 512

typedef struct {
    char *file;
    int line;
    char *func;
    char msg[ERROR_MSG_LEN];
} error_t;

static int error_count = 0;
static error_t errors[MAX_ERRORS];

void log_error(const char *file, int line, const char *func, const char *fmt,...) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Too many errors, cannot log more.\n");
        return;
    }

    va_list ap;
    va_start(ap, fmt);
    vsnprintf(errors[error_count].msg, ERROR_MSG_LEN, fmt, ap);
    va_end(ap);

    errors[error_count].file = file;
    errors[error_count].line = line;
    errors[error_count].func = func;

    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        fprintf(stdout, "No errors found.\n");
        return;
    }

    fprintf(stdout, "Found %d errors:\n", error_count);
    for (int i = 0; i < error_count; i++) {
        fprintf(stdout, "File: %s, Line: %d, Function: %s\nMessage: %s\n",
                errors[i].file, errors[i].line, errors[i].func, errors[i].msg);
    }
}

int main() {
    int a = 10;
    int b = 0;

    if (a > b) {
        log_error(__FILE__, __LINE__, __FUNCTION__, "a is greater than b (%d > %d)", a, b);
    }

    char *str = NULL;
    strcpy(str, "Hello, world!");

    log_error(__FILE__, __LINE__, __FUNCTION__, "Invalid string operation: %s", str);

    print_errors();

    return 0;
}