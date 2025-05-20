//Falcon-180B DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAX_ERRORS 100

typedef struct error_t {
    char *message;
    int line;
    int column;
    struct error_t *next;
} error_t;

error_t *errors = NULL;
int error_count = 0;

void add_error(char *message, int line, int column) {
    error_t *new_error = malloc(sizeof(error_t));
    new_error->message = message;
    new_error->line = line;
    new_error->column = column;
    new_error->next = NULL;

    if (errors == NULL) {
        errors = new_error;
    } else {
        error_t *last_error = errors;
        while (last_error->next!= NULL) {
            last_error = last_error->next;
        }
        last_error->next = new_error;
    }

    error_count++;
}

void print_errors() {
    printf("Found %d errors:\n", error_count);

    error_t *current_error = errors;
    while (current_error!= NULL) {
        printf("Line %d, Column %d: %s\n", current_error->line, current_error->column, current_error->message);
        current_error = current_error->next;
    }
}

void free_errors() {
    error_t *current_error = errors;
    while (current_error!= NULL) {
        free(current_error->message);
        free(current_error);
        current_error = current_error->next;
    }
}

#define LOG_ERROR(...) { char *message = malloc(1024); \
                           snprintf(message, 1024, __VA_ARGS__); \
                           add_error(message, __LINE__, 0); }

#define LOG_ERROR_WITH_COLUMN(...) { char *message = malloc(1024); \
                                      snprintf(message, 1024, __VA_ARGS__); \
                                      add_error(message, __LINE__, __COLUMN__); }

int main() {
    int a = 1;
    int b = 0;

    int result = a / b;

    LOG_ERROR("Division by zero!");

    printf("Result: %d\n", result);

    print_errors();

    free_errors();

    return 0;
}