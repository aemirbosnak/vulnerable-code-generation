//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

typedef struct operation {
    char op;
    int num1;
    int num2;
} operation;

operation operations[MAX_OPERATIONS];
int num_operations;

void parse_expression(char *expression);
void evaluate_expression(operation *ops);

int main() {
    char expression[100];
    int i, j;

    // Parse expression from user
    printf("Enter an arithmetic expression (e.g. 2 + 3 * 4): ");
    fgets(expression, 100, stdin);

    // Tokenize expression
    char *token = strtok(expression, " ");
    int num_tokens = 0;
    while (token != NULL && num_tokens < MAX_NUMBERS) {
        operations[num_operations].op = token[0];
        sscanf(token, "%d", &operations[num_operations].num1);
        num_operations++;
        token = strtok(NULL, " ");
        num_tokens++;
    }

    // Evaluate expression
    evaluate_expression(operations);

    // Print result
    printf("Result: %d\n", operations[0].num2);

    return 0;
}

void parse_expression(char *expression) {
    char *token = strtok(expression, " ");
    int i = 0;
    while (token != NULL && i < MAX_NUMBERS) {
        operations[i].op = token[0];
        sscanf(token, "%d", &operations[i].num1);
        token = strtok(NULL, " ");
        i++;
    }
    operations[i].op = '\0'; // null-terminate the list
}

void evaluate_expression(operation *ops) {
    int i, j;
    int result = 0;

    for (i = 0; i < num_operations; i++) {
        switch (ops[i].op) {
            case '+':
                result += ops[i].num1 + ops[i].num2;
                break;
            case '-':
                result -= ops[i].num1 - ops[i].num2;
                break;
            case '*':
                result *= ops[i].num1 * ops[i].num2;
                break;
            case '/':
                result /= ops[i].num1 / ops[i].num2;
                break;
            default:
                break;
        }
    }
    printf("Result: %d\n", result);
}