//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double value;
  char operator;
  struct Calculator* next;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->value = 0.0;
  calculator->operator = '\0';
  calculator->next = NULL;
  return calculator;
}

void addToCalculator(Calculator* calculator, double value, char operator) {
  calculator->value = value;
  calculator->operator = operator;
}

double calculate(Calculator* calculator) {
  switch (calculator->operator) {
    case '+':
      return calculator->value + calculate(calculator->next);
    case '-':
      return calculator->value - calculate(calculator->next);
    case '*':
      return calculator->value * calculate(calculator->next);
    case '/':
      return calculator->value / calculate(calculator->next);
    default:
      return calculator->value;
  }
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  Calculator* calculator = createCalculator();

  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  char* token = strtok(buffer, " ");

  while (token) {
    double value = atof(token);
    addToCalculator(calculator, value, token[0]);
    token = strtok(NULL, " ");
  }

  double result = calculate(calculator);

  printf("Result: %.2lf\n", result);

  return 0;
}