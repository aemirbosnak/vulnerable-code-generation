//Falcon-180B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_ERROR_MESSAGES 10
#define MAX_ERROR_MESSAGE_LENGTH 100

typedef struct {
    int error_code;
    char error_message[MAX_ERROR_MESSAGE_LENGTH];
} Error;

Error error_stack[MAX_ERROR_MESSAGES];
int error_stack_index = 0;

void push_error(int error_code, const char* error_message) {
    if (error_stack_index >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error stack overflow\n");
        exit(1);
    }

    error_stack[error_stack_index].error_code = error_code;
    strncpy(error_stack[error_stack_index].error_message, error_message, MAX_ERROR_MESSAGE_LENGTH - 1);
    error_stack[error_stack_index].error_message[MAX_ERROR_MESSAGE_LENGTH - 1] = '\0';
    error_stack_index++;
}

const char* get_error_message(int error_code) {
    for (int i = 0; i < error_stack_index; i++) {
        if (error_stack[i].error_code == error_code) {
            return error_stack[i].error_message;
        }
    }
    return NULL;
}

void clear_error_stack() {
    error_stack_index = 0;
}

void example_function() {
    int error_code = 0;
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        error_code = errno;
        push_error(error_code, "Failed to open file");
        return;
    }

    char buffer[100];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        error_code = errno;
        push_error(error_code, "Failed to read from file");
        fclose(file);
        return;
    }

    int value = atoi(buffer);
    if (value <= 0) {
        push_error(EINVAL, "Invalid value");
        fclose(file);
        return;
    }

    printf("Value from file: %d\n", value);
    fclose(file);
}

int main() {
    example_function();

    const char* error_message = get_error_message(EINVAL);
    if (error_message!= NULL) {
        fprintf(stderr, "Error: %s\n", error_message);
        return 1;
    }

    return 0;
}