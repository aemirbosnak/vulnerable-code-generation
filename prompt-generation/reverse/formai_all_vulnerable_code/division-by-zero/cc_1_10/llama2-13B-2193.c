//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAX_ATTEMPTS 5

typedef struct {
    char *message;
    int line;
} error_t;

void handle_error(error_t *error) {
    printf("Error: %s (line %d)\n", error->message, error->line);
    if (error->line >= 10 && error->line <= 20) {
        printf("Possible cause: invalid input\n");
    } else if (error->line >= 30 && error->line <= 40) {
        printf("Possible cause: division by zero\n");
    } else {
        printf("Possible cause: unknown\n");
    }
    sleep(1); // simulate a delay to make the program more interactive
    printf("Press enter to continue...");
    getchar();
}

int main() {
    int attempts = 0;
    while (1) {
        attempts++;
        int result = calculate_result();
        if (result == -1) {
            error_t error = { "Invalid input", __LINE__ };
            handle_error(&error);
        } else if (result == 0) {
            error_t error = { "Division by zero", __LINE__ };
            handle_error(&error);
        } else {
            break; // successful execution
        }
    }
    if (attempts >= MAX_ATTEMPTS) {
        error_t error = { "Too many attempts", __LINE__ };
        handle_error(&error);
    }
    return 0;
}

int calculate_result() {
    int a, b;
    char op;
    int result;

    // prompt user for input
    printf("Enter two numbers and an operator (+, -, *, /): ");
    scanf("%d%c%d", &a, &op, &b);

    // perform calculation
    if (op == '+') {
        result = a + b;
    } else if (op == '-') {
        result = a - b;
    } else if (op == '*') {
        result = a * b;
    } else if (op == '/') {
        result = a / b;
    } else {
        result = -1; // invalid input
    }

    return result;
}