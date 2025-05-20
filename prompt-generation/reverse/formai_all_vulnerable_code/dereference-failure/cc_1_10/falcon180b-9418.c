//Falcon-180B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10
#define ERROR_MESSAGE_LENGTH 80

typedef struct {
    char *message;
    int line_number;
} Error;

Error errors[MAX_ERRORS];
int error_count = 0;

void add_error(char *message, int line_number) {
    if (error_count >= MAX_ERRORS) {
        printf("Error: Too many errors.\n");
        exit(1);
    }
    strncpy(errors[error_count].message, message, ERROR_MESSAGE_LENGTH);
    errors[error_count].line_number = line_number;
    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors.\n");
    } else {
        printf("Errors:\n");
        for (int i = 0; i < error_count; i++) {
            printf("%d: %s\n", errors[i].line_number, errors[i].message);
        }
    }
}

int main() {
    char *input = "This is a test.\n";
    char *token;
    int line_number = 1;

    while ((token = strtok(input, "\n"))!= NULL) {
        if (strlen(token) > 10) {
            add_error("Line too long.", line_number);
        }
        line_number++;
        input = NULL;
    }

    print_errors();

    return 0;
}