//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MESSAGE_SIZE 100

typedef struct {
    char message[ERROR_MESSAGE_SIZE];
    int line_number;
    bool is_warning;
} Error;

int error_count = 0;
Error errors[MAX_ERRORS];

void add_error(const char* message, int line_number, bool is_warning) {
    if (error_count >= MAX_ERRORS) {
        fprintf(stderr, "Too many errors. Aborting.\n");
        exit(1);
    }

    strncpy(errors[error_count].message, message, ERROR_MESSAGE_SIZE - 1);
    errors[error_count].message[ERROR_MESSAGE_SIZE - 1] = '\0';
    errors[error_count].line_number = line_number;
    errors[error_count].is_warning = is_warning;

    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found.\n");
    } else {
        printf("Found %d error(s):\n", error_count);
        for (int i = 0; i < error_count; i++) {
            printf("%s at line %d\n", errors[i].message, errors[i].line_number);
        }
    }
}

int main() {
    // Example code that generates errors
    char* input = "Hello, world!";
    char* token = strtok(input, " ");

    while (token!= NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}