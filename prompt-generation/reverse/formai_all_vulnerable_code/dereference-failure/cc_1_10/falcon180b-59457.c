//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 100
#define MAX_OPERATORS 5
#define MIN_VALUE -100
#define MAX_VALUE 100

typedef struct {
    char *name;
    int value;
} variable_t;

typedef struct {
    char *name;
    int (*func)(int, int);
} operator_t;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return a / b;
}

int power(int a, int b) {
    return pow(a, b);
}

int main() {
    srand(time(NULL));

    int num_variables = rand() % MAX_NUMBERS + 1;
    int num_operators = rand() % MAX_OPERATORS + 1;

    variable_t *variables = malloc(num_variables * sizeof(variable_t));
    operator_t *operators = malloc(num_operators * sizeof(operator_t));

    for (int i = 0; i < num_variables; i++) {
        variables[i].name = malloc(10 * sizeof(char));
        sprintf(variables[i].name, "var%d", i);
        variables[i].value = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    for (int i = 0; i < num_operators; i++) {
        operators[i].name = malloc(10 * sizeof(char));
        sprintf(operators[i].name, "op%d", i);
        operators[i].func = rand() % 5? add : subtract;
    }

    printf("Welcome to the Funny Arithmetic Program!\n");

    for (int i = 0; i < num_variables; i++) {
        printf("Variable %s = %d\n", variables[i].name, variables[i].value);
    }

    for (int i = 0; i < num_operators; i++) {
        printf("Operator %s() = %d\n", operators[i].name, (*operators[i].func)(variables[0].value, variables[1].value));
    }

    free(variables);
    free(operators);

    return 0;
}