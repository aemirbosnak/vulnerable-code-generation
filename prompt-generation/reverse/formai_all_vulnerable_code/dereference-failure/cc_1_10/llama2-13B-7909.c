//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define MAX_OPERATIONS 10

typedef struct {
    char op[2];   // operation (e.g. +, -, *, /)
    int a, b;    // operands
} operation;

operation operations[MAX_OPERATIONS];
int num_ops = 0;

void parse_input() {
    char input[MAX_INPUT];
    printf("Enter a math expression (e.g. '3+4*5'-2): ");
    fgets(input, MAX_INPUT, stdin);
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < MAX_OPERATIONS) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
                strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            operations[i].op[0] = token[0];
            token = strtok(NULL, " ");
            operations[i].a = atoi(token);
            token = strtok(NULL, " ");
            operations[i].b = atoi(token);
            i++;
        }
    }
}

void evaluate() {
    int result = 0;
    for (int i = 0; i < num_ops; i++) {
        switch (operations[i].op[0]) {
            case '+':
                result += operations[i].a + operations[i].b;
                break;
            case '-':
                result -= operations[i].a - operations[i].b;
                break;
            case '*':
                result *= operations[i].a * operations[i].b;
                break;
            case '/':
                result /= operations[i].a / operations[i].b;
                break;
            default:
                printf("Invalid operation %c\n", operations[i].op[0]);
                return;
        }
    }
    printf("Result: %d\n", result);
}

int main() {
    srand(time(NULL));
    parse_input();
    evaluate();
    return 0;
}