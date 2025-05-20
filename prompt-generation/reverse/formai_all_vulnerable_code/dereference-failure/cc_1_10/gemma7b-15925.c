//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double result;
  char operator;
  double operand;
  struct Calculator* next;
} Calculator;

void calculate(Calculator* calculator) {
  switch (calculator->operator) {
    case '+':
      calculator->result = calculator->operand + calculator->next->result;
      break;
    case '-':
      calculator->result = calculator->operand - calculator->next->result;
      break;
    case '*':
      calculator->result = calculator->operand * calculator->next->result;
      break;
    case '/':
      if (calculator->next->result == 0) {
        printf("Error: division by zero is not allowed\n");
        return;
      }
      calculator->result = calculator->operand / calculator->next->result;
      break;
  }
  calculator->next->result = calculator->result;
}

int main() {
  Calculator* head = (Calculator*)malloc(sizeof(Calculator));
  head->result = 0;
  head->operator = '\0';
  head->operand = 0;
  head->next = NULL;

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  scanf("%s", input);

  char* token = strtok(input, " ");
  while (token) {
    double number = atof(token);
    Calculator* newCalculator = (Calculator*)malloc(sizeof(Calculator));
    newCalculator->result = number;
    newCalculator->operator = token[0];
    newCalculator->operand = number;
    newCalculator->next = NULL;

    if (head->next) {
      head->next->next = newCalculator;
    } else {
      head->next = newCalculator;
    }
    token = strtok(NULL, " ");
  }

  calculate(head);

  printf("The result is: %.2lf\n", head->next->result);

  return 0;
}