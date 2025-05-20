//Falcon-180B DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERRORS 10

typedef struct {
    char *message;
    int line_number;
} Error;

int error_count = 0;
Error errors[MAX_ERRORS];

void add_error(char *message, int line_number) {
    if (error_count >= MAX_ERRORS) {
        printf("Error: Too many errors!\n");
        exit(1);
    }

    errors[error_count].message = strdup(message);
    errors[error_count].line_number = line_number;
    error_count++;
}

void print_errors() {
    printf("Errors:\n");
    for (int i = 0; i < error_count; i++) {
        printf("%d: %s\n", errors[i].line_number, errors[i].message);
    }
}

int main() {
    // Example code that generates errors

    int x = 5;
    int y = 0;
    int z = x / y;

    if (z == 0) {
        add_error("Division by zero", __LINE__);
    }

    char *str = "Hello, world!";
    char *ptr = strtok(str, ", ");

    while (ptr!= NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, ", ");
    }

    return 0;
}