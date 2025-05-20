//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style data structures and functions

typedef struct {
    char *name;
    char *type;
    int value;
} Variable;

typedef struct {
    char *name;
    char *body;
} Function;

typedef struct {
    Variable *variables;
    Function *functions;
    int num_variables;
    int num_functions;
} Program;

Program *parse_program(char *input) {
    Program *program = malloc(sizeof(Program));
    program->variables = NULL;
    program->functions = NULL;
    program->num_variables = 0;
    program->num_functions = 0;

    char *token = strtok(input, " ");
    while (token != NULL) {
        if (strcmp(token, "var") == 0) {
            Variable *variable = malloc(sizeof(Variable));
            variable->name = strtok(NULL, " ");
            variable->type = strtok(NULL, " ");
            variable->value = atoi(strtok(NULL, " "));
            program->variables = realloc(program->variables, sizeof(Variable) * (program->num_variables + 1));
            program->variables[program->num_variables++] = *variable;
        } else if (strcmp(token, "func") == 0) {
            Function *function = malloc(sizeof(Function));
            function->name = strtok(NULL, " ");
            function->body = strtok(NULL, ";");
            program->functions = realloc(program->functions, sizeof(Function) * (program->num_functions + 1));
            program->functions[program->num_functions++] = *function;
        }
        token = strtok(NULL, " ");
    }

    return program;
}

void print_program(Program *program) {
    printf("Variables:\n");
    for (int i = 0; i < program->num_variables; i++) {
        printf("  %s %s %d\n", program->variables[i].name, program->variables[i].type, program->variables[i].value);
    }
    printf("Functions:\n");
    for (int i = 0; i < program->num_functions; i++) {
        printf("  %s %s\n", program->functions[i].name, program->functions[i].body);
    }
}

int main() {
    char *input = "var x int 10; var y float 20.5; func main { x = y * 2; }";
    Program *program = parse_program(input);
    print_program(program);
    return 0;
}