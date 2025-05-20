//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define ERRORLOG_LEVEL 3
#define ERRORLOG_MAX_MSG_LEN 1024

typedef enum {
    ERR_NONE,
    ERR_WARNING,
    ERR_ERROR,
    ERR_FATAL,
} ErrorType;

typedef struct {
    ErrorType type;
    const char* message;
} ErrorMessage;

static void handle_error(ErrorMessage* error) {
    if (error->type == ERR_WARNING) {
        printf("Warning: %s\n", error->message);
    } else if (error->type == ERR_ERROR) {
        printf("Error: %s\n", error->message);
    } else {
        printf("Fatal error: %s\n", error->message);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int x = 5 / 0;  // Division by zero

    if (x == -1) {
        ErrorMessage error = {ERR_ERROR, "Division by zero!"};
        handle_error(&error);
    }

    char* str = malloc(10);  // NULL pointer

    if (str == NULL) {
        ErrorMessage error = {ERR_ERROR, "Memory allocation failed!"};
        handle_error(&error);
    }

    int y = strlen(str);  // NULL pointer

    if (y == 0) {
        ErrorMessage error = {ERR_WARNING, "Empty string!"};
        handle_error(&error);
    }

    // Some other code that might fail

    return 0;
}