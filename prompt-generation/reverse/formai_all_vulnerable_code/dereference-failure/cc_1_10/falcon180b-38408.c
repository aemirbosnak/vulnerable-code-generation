//Falcon-180B DATASET v1.0 Category: Error handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ERROR_MESSAGES 10
#define ERROR_MESSAGE_LENGTH 80

typedef struct {
    char* message;
    bool is_error;
} ErrorMessage;

void add_error_message(ErrorMessage* error_messages, int num_messages, const char* message) {
    if (num_messages >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error: Too many error messages.\n");
        exit(1);
    }

    error_messages[num_messages].message = strdup(message);
    error_messages[num_messages].is_error = true;
    num_messages++;
}

void add_info_message(ErrorMessage* error_messages, int num_messages, const char* message) {
    if (num_messages >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error: Too many error messages.\n");
        exit(1);
    }

    error_messages[num_messages].message = strdup(message);
    error_messages[num_messages].is_error = false;
    num_messages++;
}

void print_error_messages(ErrorMessage* error_messages, int num_messages) {
    for (int i = 0; i < num_messages; i++) {
        if (error_messages[i].is_error) {
            fprintf(stderr, "Error: %s\n", error_messages[i].message);
        } else {
            fprintf(stdout, "Info: %s\n", error_messages[i].message);
        }
    }
}

int main() {
    ErrorMessage error_messages[MAX_ERROR_MESSAGES];
    int num_messages = 0;

    // Example usage of error handling functions
    add_error_message(error_messages, num_messages, "Invalid input");
    add_info_message(error_messages, num_messages, "Program running...");
    add_error_message(error_messages, num_messages, "Out of memory");

    print_error_messages(error_messages, num_messages);

    return 0;
}