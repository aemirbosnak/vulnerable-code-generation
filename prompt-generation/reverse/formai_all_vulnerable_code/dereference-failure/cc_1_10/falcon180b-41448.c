//Falcon-180B DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 100

// define a struct to hold variable information
typedef struct {
    char *name;
    int size;
    void *data;
} Variable;

Variable *variables = NULL;
int num_variables = 0;

void init() {
    variables = malloc(MAX_VARIABLES * sizeof(Variable));
    if (variables == NULL) {
        printf("Error: unable to allocate memory for variables.\n");
        exit(1);
    }
    num_variables = 0;
}

void add_variable(char *name, int size) {
    if (num_variables >= MAX_VARIABLES) {
        printf("Error: maximum number of variables reached.\n");
        exit(1);
    }
    Variable *new_var = malloc(sizeof(Variable));
    if (new_var == NULL) {
        printf("Error: unable to allocate memory for new variable.\n");
        exit(1);
    }
    strcpy(new_var->name, name);
    new_var->size = size;
    new_var->data = malloc(size);
    if (new_var->data == NULL) {
        printf("Error: unable to allocate memory for variable data.\n");
        exit(1);
    }
    variables[num_variables++] = *new_var;
}

void *get_variable(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].data;
        }
    }
    printf("Error: variable '%s' not found.\n", name);
    exit(1);
}

int main() {
    init();
    add_variable("my_int", sizeof(int));
    add_variable("my_float", sizeof(float));
    add_variable("my_double", sizeof(double));
    add_variable("my_char", sizeof(char));

    int *my_int = get_variable("my_int");
    *my_int = 42;

    float *my_float = get_variable("my_float");
    *my_float = 3.14;

    double *my_double = get_variable("my_double");
    *my_double = 1.23;

    char *my_char = get_variable("my_char");
    *my_char = 'A';

    printf("my_int: %d\n", *my_int);
    printf("my_float: %f\n", *my_float);
    printf("my_double: %f\n", *my_double);
    printf("my_char: %c\n", *my_char);

    return 0;
}