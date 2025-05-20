//LLAMA2-13B DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_VARIABLES 10
#define MAX_VALUES 100

typedef struct variable {
    char name[20];
    int value;
} variable_t;

typedef struct {
    variable_t variables[MAX_VARIABLES];
    int num_variables;
} problem_t;

problem_t* create_problem(void) {
    problem_t* p = malloc(sizeof(problem_t));
    p->num_variables = 0;
    return p;
}

void add_variable(problem_t* p, char* name, int value) {
    if (p->num_variables >= MAX_VARIABLES) {
        printf("Error: too many variables\n");
        return;
    }
    strcpy(p->variables[p->num_variables].name, name);
    p->variables[p->num_variables].value = value;
    p->num_variables++;
}

void set_value(problem_t* p, int variable_index, int value) {
    if (variable_index < 0 || variable_index >= p->num_variables) {
        printf("Error: invalid variable index\n");
        return;
    }
    p->variables[variable_index].value = value;
}

int get_value(problem_t* p, int variable_index) {
    if (variable_index < 0 || variable_index >= p->num_variables) {
        printf("Error: invalid variable index\n");
        return -1;
    }
    return p->variables[variable_index].value;
}

int solve(problem_t* p) {
    int result = 0;
    for (int i = 0; i < p->num_variables; i++) {
        if (p->variables[i].value > 0) {
            result += p->variables[i].value;
        }
    }
    return result;
}

int main(void) {
    problem_t* p = create_problem();

    add_variable(p, "x", 1);
    add_variable(p, "y", 2);
    add_variable(p, "z", 3);

    set_value(p, 0, 4);
    set_value(p, 1, 5);
    set_value(p, 2, 6);

    int solution = solve(p);
    printf("Solution: %d\n", solution);

    return 0;
}