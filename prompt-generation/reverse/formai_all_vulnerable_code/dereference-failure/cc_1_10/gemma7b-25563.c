//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAR 10

typedef struct Variable {
  char name[20];
  double value;
  struct Variable* next;
} Variable;

Variable* createVariable(char* name, double value) {
  Variable* newVariable = (Variable*)malloc(sizeof(Variable));
  strcpy(newVariable->name, name);
  newVariable->value = value;
  newVariable->next = NULL;
  return newVariable;
}

void addVariable(Variable* head, char* name, double value) {
  Variable* newVariable = createVariable(name, value);
  if (head == NULL) {
    head = newVariable;
  } else {
    Variable* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newVariable;
  }
}

double getVariableValue(Variable* head, char* name) {
  Variable* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      return temp->value;
    }
    temp = temp->next;
  }
  return -1;
}

int main() {
  Variable* variables = NULL;

  // Add variables
  addVariable(variables, "a", 10.0);
  addVariable(variables, "b", 20.0);
  addVariable(variables, "c", 30.0);

  // Get variable values
  double aValue = getVariableValue(variables, "a");
  double bValue = getVariableValue(variables, "b");
  double cValue = getVariableValue(variables, "c");

  // Print variable values
  printf("a = %.2lf\n", aValue);
  printf("b = %.2lf\n", bValue);
  printf("c = %.2lf\n", cValue);

  return 0;
}