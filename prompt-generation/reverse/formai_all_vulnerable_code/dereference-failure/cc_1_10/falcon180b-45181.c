//Falcon-180B DATASET v1.0 Category: Error handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VARIABLES 100
#define MAX_VARIABLE_LENGTH 50
#define MAX_ERROR_MESSAGE_LENGTH 100

typedef struct {
    char *name;
    int value;
} Variable;

Variable variables[MAX_VARIABLES];
int num_variables = 0;

void add_variable(char *name, int value) {
    if (num_variables >= MAX_VARIABLES) {
        fprintf(stderr, "Error: Too many variables\n");
        exit(1);
    }
    Variable v;
    v.name = strdup(name);
    v.value = value;
    variables[num_variables++] = v;
}

int get_variable_index(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int evaluate_expression(char *expression) {
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            int value = atoi(token);
            add_variable(token, value);
        } else {
            int index = get_variable_index(token);
            if (index == -1) {
                char error_message[MAX_ERROR_MESSAGE_LENGTH];
                sprintf(error_message, "Error: Undefined variable '%s'\n", token);
                fprintf(stderr, "%s", error_message);
                exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char input[MAX_VARIABLE_LENGTH];
    while (fgets(input, MAX_VARIABLE_LENGTH, stdin)!= NULL) {
        if (input[0] == '#') {
            continue;
        }
        char *expression = strtok(input, "=");
        if (expression == NULL) {
            continue;
        }
        evaluate_expression(expression);
    }
    return 0;
}