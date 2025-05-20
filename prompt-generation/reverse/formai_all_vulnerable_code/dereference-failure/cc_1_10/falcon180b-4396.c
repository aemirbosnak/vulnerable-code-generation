//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_RESULT_SIZE 100
#define MAX_OPERATORS 10

typedef struct {
    char *input;
    double result;
    int operator_count;
    char **operators;
} Calculator;

Calculator *calculator_create() {
    Calculator *calculator = (Calculator *) malloc(sizeof(Calculator));
    calculator->input = (char *) malloc(MAX_INPUT_SIZE * sizeof(char));
    calculator->result = 0;
    calculator->operator_count = 0;
    calculator->operators = (char **) malloc(MAX_OPERATORS * sizeof(char *));
    return calculator;
}

void calculator_destroy(Calculator *calculator) {
    free(calculator->input);
    free(calculator->operators);
    free(calculator);
}

void calculator_clear(Calculator *calculator) {
    calculator->result = 0;
    calculator->operator_count = 0;
    memset(calculator->input, 0, MAX_INPUT_SIZE);
    memset(calculator->operators, 0, MAX_OPERATORS * sizeof(char *));
}

int calculator_add_operator(Calculator *calculator, char *operator) {
    if (calculator->operator_count >= MAX_OPERATORS) {
        return -1;
    }
    calculator->operators[calculator->operator_count] = strdup(operator);
    calculator->operator_count++;
    return 0;
}

int calculator_evaluate(Calculator *calculator) {
    char *input_copy = strdup(calculator->input);
    char *token = strtok(input_copy, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            calculator->result += atof(token);
        } else {
            int i;
            for (i = 0; i < calculator->operator_count; i++) {
                if (strcmp(token, calculator->operators[i]) == 0) {
                    if (i == 0 || strcmp(calculator->operators[i - 1], "+")!= 0 && strcmp(calculator->operators[i - 1], "-")!= 0) {
                        calculator->result += atof(strtok(NULL, " "));
                    } else {
                        calculator->result -= atof(strtok(NULL, " "));
                    }
                    break;
                }
            }
            if (i == calculator->operator_count) {
                printf("Invalid operator: %s\n", token);
                return -1;
            }
        }
        token = strtok(NULL, " ");
    }
    free(input_copy);
    return 0;
}

int main() {
    Calculator *calculator = calculator_create();
    char input[MAX_INPUT_SIZE];
    while (1) {
        printf("Enter an expression: ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        strcat(calculator->input, input);
        strcat(calculator->input, " ");
        int result = calculator_evaluate(calculator);
        if (result!= 0) {
            break;
        }
    }
    calculator_destroy(calculator);
    return 0;
}