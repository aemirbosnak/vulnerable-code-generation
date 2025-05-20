//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

typedef struct {
  char *name;
  char *value;
} Variable;

typedef struct {
  char *name;
  char *body;
} Function;

typedef struct {
  Variable *variables;
  int num_variables;
  Function *functions;
  int num_functions;
} Program;

Program *parse_program(char *input) {
  Program *program = malloc(sizeof(Program));
  program->variables = NULL;
  program->num_variables = 0;
  program->functions = NULL;
  program->num_functions = 0;

  char *token = strtok(input, " ");
  while (token != NULL) {
    if (strcmp(token, "var") == 0) {
      Variable *variable = malloc(sizeof(Variable));
      variable->name = strtok(NULL, " ");
      variable->value = strtok(NULL, ";");
      program->variables = realloc(program->variables, (program->num_variables + 1) * sizeof(Variable));
      program->variables[program->num_variables++] = *variable;
    } else if (strcmp(token, "fun") == 0) {
      Function *function = malloc(sizeof(Function));
      function->name = strtok(NULL, " ");
      function->body = strtok(NULL, ";");
      program->functions = realloc(program->functions, (program->num_functions + 1) * sizeof(Function));
      program->functions[program->num_functions++] = *function;
    }

    token = strtok(NULL, " ");
  }

  return program;
}

void print_program(Program *program) {
  printf("Variables:\n");
  for (int i = 0; i < program->num_variables; i++) {
    printf("  %s = %s\n", program->variables[i].name, program->variables[i].value);
  }

  printf("Functions:\n");
  for (int i = 0; i < program->num_functions; i++) {
    printf("  %s\n", program->functions[i].name);
    printf("    %s\n", program->functions[i].body);
  }
}

int main() {
  char input[MAX_INPUT_LENGTH];
  printf("Enter a C program:\n");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  Program *program = parse_program(input);
  print_program(program);

  return 0;
}