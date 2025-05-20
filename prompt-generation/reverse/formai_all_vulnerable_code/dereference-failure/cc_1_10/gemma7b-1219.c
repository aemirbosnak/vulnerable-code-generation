//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  double result;
  double operand1;
  double operand2;
  char operator;
  char buffer[MAX_BUFFER_SIZE];
  int bufferIndex;
  int state;
} Calculator;

void initializeCalculator(Calculator *calc) {
  calc->result = 0;
  calc->operand1 = 0;
  calc->operand2 = 0;
  calc->operator = '\0';
  calc->bufferIndex = 0;
  calc->state = 0;
}

void calculate(Calculator *calc) {
  switch (calc->operator) {
    case '+':
      calc->result = calc->operand1 + calc->operand2;
      break;
    case '-':
      calc->result = calc->operand1 - calc->operand2;
      break;
    case '*':
      calc->result = calc->operand1 * calc->operand2;
      break;
    case '/':
      if (calc->operand2 == 0) {
        printf("Cannot divide by zero\n");
      } else {
        calc->result = calc->operand1 / calc->operand2;
      }
      break;
    default:
      printf("Invalid operator\n");
  }
}

int main() {
  Calculator *calc = (Calculator *)malloc(sizeof(Calculator));
  initializeCalculator(calc);

  printf("Enter an expression: ");
  fgets(calc->buffer, MAX_BUFFER_SIZE, stdin);

  calc->bufferIndex = 0;
  while (calc->buffer[calc->bufferIndex] != '\0') {
    char operator = calc->buffer[calc->bufferIndex];
    calc->operand2 = atof(calc->buffer + calc->bufferIndex);
    calc->bufferIndex++;

    switch (operator) {
      case ' ':
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        calculate(calc);
        printf("%f\n", calc->result);
        initializeCalculator(calc);
        break;
      default:
        printf("Invalid operator\n");
    }
  }

  free(calc);

  return 0;
}