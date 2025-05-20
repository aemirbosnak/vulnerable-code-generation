//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_OPERANDS 10
#define MAX_OPERATORS 5
#define MAX_RESULT_SIZE 2048

// Data structure to hold operands and operators
typedef struct {
    char *operand;
    int operator;
} Operand;

Operand operands[MAX_OPERANDS];
int num_operands;
int current_operand;

void push_operand(char *operand, int operator) {
    if (num_operands >= MAX_OPERANDS) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    operands[num_operands].operand = operand;
    operands[num_operands].operator = operator;
    num_operands++;
}

char *pop_operand() {
    if (num_operands <= 0) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    char *operand = operands[--num_operands].operand;
    free(operand);
    return operand;
}

void print_operands() {
    for (int i = 0; i < num_operands; i++) {
        printf("%s ", operands[i].operand);
    }
    printf("\n");
}

int precedence(int operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

int main() {
    char input[MAX_RESULT_SIZE];
    while (fgets(input, MAX_RESULT_SIZE, stdin)!= NULL) {
        int len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[--len] = '\0';
        }
        char *token = strtok(input, " ");
        while (token!= NULL) {
            if (isdigit(token[0])) {
                push_operand(token, 0);
            } else {
                int op = 0;
                if (strcmp(token, "+") == 0) {
                    op = '+';
                } else if (strcmp(token, "-") == 0) {
                    op = '-';
                } else if (strcmp(token, "*") == 0) {
                    op = '*';
                } else if (strcmp(token, "/") == 0) {
                    op = '/';
                } else if (strcmp(token, "^") == 0) {
                    op = '^';
                }
                if (op!= 0) {
                    while (num_operands > 0 && precedence(operands[num_operands - 1].operator) >= precedence(op)) {
                        char *right = pop_operand();
                        char *left = pop_operand();
                        char result[MAX_RESULT_SIZE];
                        sprintf(result, "%s %c %s", left, op, right);
                        push_operand(result, 0);
                    }
                    push_operand(token, op);
                }
            }
            token = strtok(NULL, " ");
        }
        if (num_operands == 1) {
            char *result = pop_operand();
            printf("%s\n", result);
        } else {
            printf("Error: Invalid input\n");
        }
    }
    return 0;
}