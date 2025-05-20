//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

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
  calculator->next = NULL;
}

int main() {
  Calculator* head = NULL;
  char buffer[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Parse the expression and create a linked list of calculators
  Calculator* calculator = NULL;
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] >= 'a' && buffer[i] <= 'z') {
      calculator = malloc(sizeof(Calculator));
      calculator->value = 0;
      calculator->operator = buffer[i];
      calculator->next = NULL;

      if (head == NULL) {
        head = calculator;
      } else {
        calculator->next = head;
        head = calculator;
      }
    }
  }

  // Calculate the result
  if (head) {
    calculate(head);
  }

  // Print the result
  if (head->value) {
    printf("The result is: %.2lf\n", head->value);
  } else {
    printf("Error: invalid expression\n");
  }

  return 0;
}