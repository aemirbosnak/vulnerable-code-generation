//Falcon-180B DATASET v1.0 Category: Error handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_ERROR_MESSAGE_SIZE 1000

typedef struct {
    char *message;
    int code;
} Error;

void generate_error(char *message, int code) {
    Error error = {
       .message = strdup(message),
       .code = code
    };
    printf("Error %d: %s\n", code, error.message);
    exit(code);
}

int main() {
    srand(time(NULL));
    int num1, num2, result;
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the futuristic calculator!\n");
    printf("Please enter a valid expression (e.g. '2 + 3'): ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (strlen(input) <= 2) {
        generate_error("Expression must be at least three characters long.", 1);
    }

    if (!isdigit(input[0]) ||!isdigit(input[1]) ||!isdigit(input[2])) {
        generate_error("Expression must start with a number.", 2);
    }

    num1 = atoi(input);
    num2 = rand() % 100;

    switch (input[2]) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                generate_error("Cannot divide by zero.", 3);
            } else {
                result = num1 / num2;
            }
            break;
        default:
            generate_error("Invalid operator.", 4);
            break;
    }

    printf("Result: %d\n", result);

    return 0;
}