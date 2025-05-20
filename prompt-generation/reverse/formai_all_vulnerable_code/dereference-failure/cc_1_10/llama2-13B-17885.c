//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_VARIABLE_NAME_LENGTH 32
#define MAX_FUNCTION_NAME_LENGTH 32

typedef struct {
    char *name;
    int line_number;
} variable_t;

typedef struct {
    char *name;
    int line_number;
    int parameters;
} function_t;

int main() {
    char buffer[MAX_LINE_LENGTH];
    char *token;
    variable_t *variables = NULL;
    function_t *functions = NULL;
    int variable_count = 0;
    int function_count = 0;
    int line_count = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
        token = strtok(buffer, " ");

        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "int") == 0) {
            variable_t *new_variable = malloc(sizeof(variable_t));
            new_variable->name = token + 3;
            new_variable->line_number = line_count;
            variables = realloc(variables, (variable_count + 1) * sizeof(variable_t));
            variables[variable_count] = *new_variable;
            variable_count++;
        } else if (strcmp(token, "float") == 0) {
            variable_t *new_variable = malloc(sizeof(variable_t));
            new_variable->name = token + 4;
            new_variable->line_number = line_count;
            variables = realloc(variables, (variable_count + 1) * sizeof(variable_t));
            variables[variable_count] = *new_variable;
            variable_count++;
        } else if (strcmp(token, "void") == 0) {
            function_t *new_function = malloc(sizeof(function_t));
            new_function->name = token + 4;
            new_function->line_number = line_count;
            new_function->parameters = 0;
            functions = realloc(functions, (function_count + 1) * sizeof(function_t));
            functions[function_count] = *new_function;
            function_count++;
        } else {
            line_count++;
        }
    }

    printf("Number of variables: %d\n", variable_count);
    printf("Number of functions: %d\n", function_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}