//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ERROR_MESSAGE_SIZE 256

typedef enum {
    SUCCESS,
    FAILED,
    INVALID_INPUT,
    OUT_OF_BOUNDS,
    DIVIDE_BY_ZERO,
    UNKNOWN_ERROR
} error_t;

void handle_error(error_t error_code, const char *func_name, const char *file_name, int line_num) {
    char error_message[MAX_ERROR_MESSAGE_SIZE];
    switch (error_code) {
        case SUCCESS:
            break;
        case INVALID_INPUT:
            snprintf(error_message, MAX_ERROR_MESSAGE_SIZE, "Invalid input: %s", func_name);
            break;
        case OUT_OF_BOUNDS:
            snprintf(error_message, MAX_ERROR_MESSAGE_SIZE, "Out of bounds: %s", func_name);
            break;
        case DIVIDE_BY_ZERO:
            snprintf(error_message, MAX_ERROR_MESSAGE_SIZE, "Divide by zero: %s", func_name);
            break;
        case UNKNOWN_ERROR:
            snprintf(error_message, MAX_ERROR_MESSAGE_SIZE, "Unknown error: %s", func_name);
            break;
        default:
            snprintf(error_message, MAX_ERROR_MESSAGE_SIZE, "Unhandled error: %d", error_code);
            break;
    }
    printf("Error: %s (%d) at %s:%d\n", error_message, error_code, file_name, line_num);
    exit(error_code);
}

int main() {
    int x = 5;
    int y = 0;
    int z = x / y;

    if (z == 0) {
        handle_error(DIVIDE_BY_ZERO, __func__, __FILE__, __LINE__);
    }

    if (x > 10) {
        handle_error(OUT_OF_BOUNDS, __func__, __FILE__, __LINE__);
    }

    if (strlen(x) > MAX_INPUT_SIZE) {
        handle_error(INVALID_INPUT, __func__, __FILE__, __LINE__);
    }

    return SUCCESS;
}