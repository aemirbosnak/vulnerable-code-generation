//Falcon-180B DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>

typedef struct {
    jmp_buf env;
    int code;
    const char* message;
} error_t;

error_t* error_new(int code, const char* message,...) {
    error_t* error = malloc(sizeof(error_t));
    if (error == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        abort();
    }
    error->code = code;
    error->message = message;
    va_list args;
    va_start(args, message);
    vsnprintf(error->message, 1024, message, args);
    va_end(args);
    return error;
}

void error_delete(error_t* error) {
    free(error);
}

void error_throw(error_t* error) {
    longjmp(error->env, error->code);
}

void error_catch(error_t* error) {
    if (setjmp(error->env) == 0) {
        switch (error->code) {
            case 1:
                printf("Error: %s\n", error->message);
                break;
            case 2:
                printf("Warning: %s\n", error->message);
                break;
            default:
                printf("Unknown error: %d\n", error->code);
        }
    }
}

int main() {
    error_t* error = error_new(1, "This is an error message %d", 42);
    error_catch(error);
    printf("This should not be printed\n");
    error_delete(error);
    return 0;
}