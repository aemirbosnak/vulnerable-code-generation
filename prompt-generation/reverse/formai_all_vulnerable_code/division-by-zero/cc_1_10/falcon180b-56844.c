//Falcon-180B DATASET v1.0 Category: Error handling ; Style: shape shifting
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
        fprintf(stderr, "Too many errors, aborting.\n");
        exit(1);
    }
    
    errors[error_count].message = strdup(message);
    errors[error_count].line_number = line_number;
    
    error_count++;
}

void print_errors() {
    if (error_count == 0) {
        printf("No errors found.\n");
        return;
    }
    
    printf("Found %d errors:\n", error_count);
    
    for (int i = 0; i < error_count; i++) {
        printf("%d: %s\n", errors[i].line_number, errors[i].message);
    }
}

int main() {
    int x = 5;
    int y = 0;
    int result;
    
    // Divide by zero error
    result = x / y;
    
    if (result == 0) {
        add_error("Divide by zero error", __LINE__);
    } else {
        printf("Result: %d\n", result);
    }
    
    // Out of bounds array access error
    int arr[5] = {1, 2, 3, 4, 5};
    int index = 10;
    
    if (index >= 0 && index < 5) {
        printf("Array element: %d\n", arr[index]);
    } else {
        add_error("Out of bounds array access error", __LINE__);
    }
    
    print_errors();
    
    return 0;
}