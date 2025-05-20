//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct calculator {
  double accumulator;
  double operand;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int index;
} calculator;

calculator* create_calculator() {
  calculator* calc = malloc(sizeof(calculator));
  calc->accumulator = 0.0;
  calc->operand = 0.0;
  calc->operator = '\0';
  calc->index = 0;
  return calc;
}

void calculate(calculator* calc) {
  switch (calc->operator) {
    case '+':
      calc->accumulator += calc->operand;
      break;
    case '-':
      calc->accumulator -= calc->operand;
      break;
    case '*':
      calc->accumulator *= calc->operand;
      break;
    case '/':
      if (calc->operand == 0) {
        printf("Error: division by zero\n");
      } else {
        calc->accumulator /= calc->operand;
      }
      break;
  }
  calc->operand = 0.0;
  calc->operator = '\0';
}

int main() {
  calculator* calc = create_calculator();

  char input[MAX_BUFFER_SIZE];
  printf("Enter an expression: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  char* token = strtok(input, " ");

  while (token) {
    switch (*token) {
      case ' ':
      case '\n':
        calculate(calc);
        break;
      default:
        if (calc->index > 0) {
          calc->buffer[calc->index++] = *token;
        } else {
          calc->operand = atof(token);
        }
    }
    token = strtok(NULL, " ");
  }

  calculate(calc);

  printf("Result: %.2lf\n", calc->accumulator);

  return 0;
}