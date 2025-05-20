//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 10
#define MAX_VARIABLE_LENGTH 256

struct variable {
    char name[MAX_VARIABLE_LENGTH];
    int value;
};

int num_variables = 0;
struct variable *variables = NULL;

void add_variable(char *name, int value) {
    if (num_variables >= MAX_VARIABLES) {
        printf("Error: Too many variables.\n");
        return;
    }
    struct variable *new_variables = (struct variable *) realloc(variables, sizeof(struct variable) * (num_variables + 1));
    if (new_variables == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    variables = new_variables;
    strcpy(variables[num_variables].name, name);
    variables[num_variables].value = value;
    num_variables++;
}

int get_variable_value(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Error: Variable '%s' not found.\n", name);
    return -1;
}

void print_variables() {
    printf("Variables:\n");
    for (int i = 0; i < num_variables; i++) {
        printf("%s = %d\n", variables[i].name, variables[i].value);
    }
}

int main() {
    add_variable("x", 1);
    add_variable("y", 2);
    add_variable("z", 3);
    print_variables();
    printf("x = %d\n", get_variable_value("x"));
    printf("y = %d\n", get_variable_value("y"));
    printf("z = %d\n", get_variable_value("z"));
    return 0;
}