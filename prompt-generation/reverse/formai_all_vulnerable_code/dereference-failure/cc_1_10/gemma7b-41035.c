//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double operand;
  char operator;
  struct Calculator* next;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->operand = 0.0;
  calculator->operator = '\0';
  calculator->next = NULL;
  return calculator;
}

void addCalculator(Calculator* calculator, double operand, char operator) {
  Calculator* newCalculator = createCalculator();
  newCalculator->operand = operand;
  newCalculator->operator = operator;
  newCalculator->next = calculator;
  calculator = newCalculator;
}

double evaluateCalculator(Calculator* calculator) {
  double result = calculator->operand;
  while (calculator->next) {
    switch (calculator->operator) {
      case '+':
        result += calculator->next->operand;
        break;
      case '-':
        result -= calculator->next->operand;
        break;
      case '*':
        result *= calculator->next->operand;
        break;
      case '/':
        result /= calculator->next->operand;
        break;
    }
    calculator = calculator->next;
  }
  return result;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  Calculator* calculator = createCalculator();
  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the expression and add calculators to the linked list
  char* token = strtok(buffer, " ");
  while (token) {
    double operand = atof(token);
    addCalculator(calculator, operand, token[0]);
    token = strtok(NULL, " ");
  }

  // Evaluate the expression and print the result
  double result = evaluateCalculator(calculator);
  printf("The result is: %f\n", result);

  return 0;
}