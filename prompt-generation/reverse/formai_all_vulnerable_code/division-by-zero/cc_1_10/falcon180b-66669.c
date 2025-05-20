//Falcon-180B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MESSAGES 10
#define ERROR_MESSAGE_LENGTH 80

typedef struct {
    char *message;
    int line_number;
} ErrorMessage;

int error_count = 0;
ErrorMessage error_messages[MAX_ERROR_MESSAGES];

void add_error_message(char *message, int line_number) {
    if (error_count >= MAX_ERROR_MESSAGES) {
        fprintf(stderr, "Error: Too many errors. Cannot add more.\n");
        return;
    }

    error_messages[error_count].message = strdup(message);
    error_messages[error_count].line_number = line_number;
    error_count++;
}

void print_error_messages() {
    if (error_count == 0) {
        printf("No errors found.\n");
        return;
    }

    printf("Error messages:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%d: %s\n", error_messages[i].line_number, error_messages[i].message);
    }
}

int main() {
    // Example code that may cause errors
    int a = 10;
    int b = 0;
    int c = a / b; // Division by zero error

    if (error_count > 0) {
        print_error_messages();
        return 1;
    }

    return 0;
}