//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

#define MAX_ERRORS 10
#define ERR_SUCCESS 0
#define ERR_FAILURE 1
#define ERR_MEMORY 2
#define ERR_FILE 3
#define ERR_INVALID_ARG 4
#define ERR_INVALID_STATE 5
#define ERR_INVALID_DATA 6
#define ERR_INVALID_FORMAT 7
#define ERR_INVALID_RANGE 8
#define ERR_INVALID_VALUE 9

typedef struct {
    int code;
    const char* message;
} error_t;

static error_t errors[MAX_ERRORS];
static int num_errors = 0;

void error_init() {
    memset(errors, 0, sizeof(errors));
    num_errors = 0;
}

void error_add(int code, const char* message,...) {
    if (num_errors >= MAX_ERRORS) {
        return;
    }

    va_list args;
    va_start(args, message);
    vsnprintf(errors[num_errors].message, sizeof(errors[num_errors].message), message, args);
    va_end(args);

    errors[num_errors].code = code;
    num_errors++;
}

void error_print() {
    if (num_errors == 0) {
        printf("No errors.\n");
        return;
    }

    printf("Errors:\n");
    for (int i = 0; i < num_errors; i++) {
        printf("%d: %s\n", errors[i].code, errors[i].message);
    }
}

void error_clear() {
    memset(errors, 0, sizeof(errors));
    num_errors = 0;
}

int main() {
    error_init();

    // Example usage of error handling
    int* data = malloc(10 * sizeof(int));
    if (data == NULL) {
        error_add(ERR_MEMORY, "Failed to allocate memory.");
        return ERR_FAILURE;
    }

    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        error_add(ERR_FILE, "Failed to open file: %s", strerror(errno));
        return ERR_FAILURE;
    }

    int value = 42;
    if (value < 0 || value > 100) {
        error_add(ERR_INVALID_VALUE, "Invalid value: %d", value);
        return ERR_FAILURE;
    }

    fclose(file);
    free(data);

    error_print();
    error_clear();

    return ERR_SUCCESS;
}