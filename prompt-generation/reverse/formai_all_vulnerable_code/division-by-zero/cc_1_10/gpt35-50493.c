//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_operation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int perform_operation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0; // Invalid operator
    }
}

bool is_valid_input(char* input) {
    if (strlen(input) < 3 || !isdigit(input[0])) {
        return false;
    }

    for (int i = 1; i < strlen(input) - 1; i++) {
        if (!isdigit(input[i]) && !is_valid_operation(input[i])) {
            return false;
        }
    }

    return isdigit(input[strlen(input) - 1]);
}

int main() {
    printf("Please enter a valid input: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (!is_valid_input(input)) {
        printf("Invalid input, please try again\n");
        exit(EXIT_FAILURE);
    }

    int result = 0;
    int operand = -1;
    char operation = '\0';

    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            int digit = input[i] - '0';

            if (operand == -1) {
                operand = digit;
            } else {
                operand = operand * 10 + digit;
            }
        } else if (is_valid_operation(input[i])) {
            if (operation != '\0') {
                result = perform_operation(result, operand, operation);
                operand = -1;
            } else {
                result = operand;
                operand = -1;
            }

            operation = input[i];
        }
    }

    if (operand != -1) {
        result = perform_operation(result, operand, operation);
    }

    printf("Result: %d\n", result);

    return 0;
}