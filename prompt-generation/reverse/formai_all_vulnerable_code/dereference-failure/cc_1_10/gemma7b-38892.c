//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VARIABLES 10

typedef struct Variable {
  char name[20];
  double value;
  struct Variable* next;
} Variable;

Variable* variable_list = NULL;

void add_variable(char* name, double value) {
  Variable* new_variable = malloc(sizeof(Variable));
  strcpy(new_variable->name, name);
  new_variable->value = value;
  new_variable->next = variable_list;
  variable_list = new_variable;
}

double get_variable(char* name) {
  Variable* current_variable = variable_list;
  while (current_variable) {
    if (strcmp(current_variable->name, name) == 0) {
      return current_variable->value;
    }
    current_variable = current_variable->next;
  }
  return -1;
}

void calculate() {
  char expression[256];
  printf("Enter an expression: ");
  scanf("%s", expression);

  // Parse the expression
  // Calculate the result
  double result = 0;
  char* token = strtok(expression, " ");
  while (token) {
    double operand = get_variable(token);
    if (operand != -1) {
      result += operand;
    } else {
      result += atof(token);
    }
    token = strtok(NULL, " ");
  }

  // Print the result
  printf("The result is: %.2lf\n", result);
}

int main() {
  add_variable("a", 10.0);
  add_variable("b", 20.0);
  add_variable("c", 30.0);

  calculate();

  return 0;
}