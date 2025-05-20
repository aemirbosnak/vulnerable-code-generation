//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define VAR_COUNT 4
typedef struct {
    char name;
    int value;
} Variable;

Variable variables[VAR_COUNT];

void set_variable(char variable_name, int value) {
    for (int i = 0; i < VAR_COUNT; i++) {
        if (variables[i].name == variable_name) {
            variables[i].value = value;
            break;
        }
    }
}

int get_variable(char variable_name) {
    for (int i = 0; i < VAR_COUNT; i++) {
        if (variables[i].name == variable_name) {
            return variables[i].value;
        }
    }

    // Variable not found
    return -1;
}

void print_variables() {
    printf("Variables: [");
    for (int i = 0; i < VAR_COUNT; i++) {
        printf("'%c': %d, ", variables[i].name, variables[i].value);
    }
    printf("]\n");
}

void evaluate_expression(char* expression) {
    int a, b, result;
    char op;

    sscanf(expression, "%c %c %d %d", &op, &expression[0], &a, &b);

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '&':
            result = a & b;
            break;
        case '|':
            result = a | b;
            break;
        case '^':
            result = a ^ b;
            break;
        case '!':
            result = !a;
            break;
        default:
            printf("Invalid operator: %c\n", op);
            return;
    }

    set_variable(expression[0], result);
}

void calculate(char* expression) {
    char* token;
    token = strtok(expression, " ");

    while (token != NULL) {
        evaluate_expression(token);
        token = strtok(NULL, " ");
    }

    print_variables();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <calculation expression>\n", argv[0]);
        return 1;
    }

    calculate(argv[1]);

    return 0;
}