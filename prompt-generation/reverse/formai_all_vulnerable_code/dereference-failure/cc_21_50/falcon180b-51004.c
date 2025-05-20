//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char *token;
    int num1, num2;
    double result;
    int operator;
    int is_valid_input = 1;

    while (1) {
        printf("Enter an expression or type 'q' to quit: ");
        fgets(input, MAX_LENGTH, stdin);

        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        token = strtok(input, " ");
        while (token!= NULL) {
            if (isdigit(token[0])) {
                num1 = atoi(token);
            } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '^') {
                operator = token[0];
            } else if (token[0] == '(') {
                // Handle parentheses
            } else if (token[0] == ')') {
                // Handle parentheses
            } else if (token[0] == '.') {
                // Handle decimal point
            } else {
                is_valid_input = 0;
                printf("Invalid input: %s\n", token);
                break;
            }

            token = strtok(NULL, " ");
        }

        if (!is_valid_input) {
            continue;
        }

        switch (operator) {
            case '+':
                num2 = atoi(token);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
            case '-':
                num2 = atoi(token);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case '*':
                num2 = atoi(token);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case '/':
                num2 = atoi(token);
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;
            case '^':
                num2 = atoi(token);
                result = pow(num1, num2);
                printf("Result: %f\n", result);
                break;
            default:
                printf("Invalid operator: %c\n", operator);
        }
    }

    return 0;
}