//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *type;
    int size;
} Variable;

typedef struct {
    char *name;
    char *type;
    Variable *args;
    int num_args;
} Function;

typedef struct {
    char *name;
    Function *functions;
    Variable *variables;
    int num_functions;
    int num_variables;
} Module;

Module *parse_module(char *input) {
    Module *module = malloc(sizeof(Module));
    module->name = strtok(input, " \n");
    module->functions = NULL;
    module->variables = NULL;
    module->num_functions = 0;
    module->num_variables = 0;

    char *line = strtok(NULL, "\n");
    while (line) {
        if (line[0] == 'f') {
            Function *function = malloc(sizeof(Function));
            function->name = strtok(line, " \n");
            function->type = strtok(NULL, " \n");
            function->args = NULL;
            function->num_args = 0;

            char *arg = strtok(NULL, ", \n");
            while (arg) {
                Variable *variable = malloc(sizeof(Variable));
                variable->name = arg;
                variable->type = strtok(NULL, " \n");
                variable->size = atoi(strtok(NULL, " \n"));
                function->args = realloc(function->args, (function->num_args + 1) * sizeof(Variable));
                function->args[function->num_args] = *variable;
                function->num_args++;

                arg = strtok(NULL, ", \n");
            }

            module->functions = realloc(module->functions, (module->num_functions + 1) * sizeof(Function));
            module->functions[module->num_functions] = *function;
            module->num_functions++;
        } else if (line[0] == 'v') {
            Variable *variable = malloc(sizeof(Variable));
            variable->name = strtok(line, " \n");
            variable->type = strtok(NULL, " \n");
            variable->size = atoi(strtok(NULL, " \n"));
            module->variables = realloc(module->variables, (module->num_variables + 1) * sizeof(Variable));
            module->variables[module->num_variables] = *variable;
            module->num_variables++;
        }

        line = strtok(NULL, "\n");
    }

    return module;
}

void print_module(Module *module) {
    printf("Module: %s\n", module->name);
    printf("Functions:\n");
    for (int i = 0; i < module->num_functions; i++) {
        Function *function = &module->functions[i];
        printf("  %s %s(", function->type, function->name);
        for (int j = 0; j < function->num_args; j++) {
            Variable *arg = &function->args[j];
            printf("%s %s", arg->type, arg->name);
            if (j < function->num_args - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
    printf("Variables:\n");
    for (int i = 0; i < module->num_variables; i++) {
        Variable *variable = &module->variables[i];
        printf("  %s %s\n", variable->type, variable->name);
    }
}

int main() {
    char *input = "module main\n"
                  "f add i32 add(i32 a, i32 b)\n"
                  "v i32 a\n"
                  "v i32 b\n";

    Module *module = parse_module(input);
    print_module(module);

    return 0;
}