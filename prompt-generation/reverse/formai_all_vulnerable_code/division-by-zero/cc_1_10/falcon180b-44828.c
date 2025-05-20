//Falcon-180B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MSG_LEN 100

typedef struct {
    char *msg;
    int line_num;
    bool is_warning;
} error_t;

static error_t errors[MAX_ERRORS];
static int num_errors = 0;

void add_error(const char *msg, int line_num, bool is_warning) {
    if (num_errors >= MAX_ERRORS) {
        printf("Error: too many errors!\n");
        exit(1);
    }

    errors[num_errors].msg = strdup(msg);
    errors[num_errors].line_num = line_num;
    errors[num_errors].is_warning = is_warning;

    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Found %d errors:\n", num_errors);

    for (int i = 0; i < num_errors; i++) {
        printf("%s:%d - %s\n", errors[i].is_warning? "Warning" : "Error", errors[i].line_num, errors[i].msg);
    }
}

void cleanup_errors() {
    for (int i = 0; i < num_errors; i++) {
        free(errors[i].msg);
    }

    num_errors = 0;
}

#define ERR_MSG(msg) add_error(msg, __LINE__, false)
#define WARN_MSG(msg) add_error(msg, __LINE__, true)

#define CLEANUP \
    cleanup_errors(); \
    return 1;

int main() {
    int x = 10;
    int y = 0;

    ERR_MSG("Division by zero is not allowed.");
    x /= y;

    WARN_MSG("This variable might be uninitialized.");
    int z = x;

    printf("Program completed successfully.\n");
    CLEANUP;
}