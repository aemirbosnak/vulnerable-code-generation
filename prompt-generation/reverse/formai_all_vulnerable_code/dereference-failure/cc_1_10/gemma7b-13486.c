//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double value;
  char operator;
  struct Calculator* next;
} Calculator;

void calculate(Calculator* calculator) {
  double result = 0;
  switch (calculator->operator) {
    case '+':
      result = calculator->value + calculator->next->value;
      break;
    case '-':
      result = calculator->value - calculator->next->value;
      break;
    case '*':
      result = calculator->value * calculator->next->value;
      break;
    case '/':
      result = calculator->value / calculator->next->value;
      break;
  }
  calculator->value = result;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  Calculator* head = NULL;

  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the expression and create a linked list of calculators
  char* token = strtok(buffer, " ");
  while (token) {
    Calculator* newCalculator = malloc(sizeof(Calculator));
    newCalculator->value = atof(token);
    newCalculator->operator = token[0];
    newCalculator->next = head;
    head = newCalculator;
    token = strtok(NULL, " ");
  }

  // Calculate the result
  calculate(head);

  // Print the result
  printf("The result is: %.2lf\n", head->value);

  return 0;
}