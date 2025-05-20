//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int top;
  double result;
} Calculator;

Calculator* createCalculator() {
  Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
  calculator->top = -1;
  calculator->result = 0.0;
  return calculator;
}

void addToCalculator(Calculator* calculator, char number) {
  calculator->buffer[++calculator->top] = number;
}

double calculate(Calculator* calculator) {
  double result = 0.0;
  int i = 0;
  for (i = 0; i <= calculator->top; i++) {
    switch (calculator->buffer[i]) {
      case '+':
        result += calculator->buffer[i + 1] - '0';
        break;
      case '-':
        result -= calculator->buffer[i + 1] - '0';
        break;
      case '*':
        result *= calculator->buffer[i + 1] - '0';
        break;
      case '/':
        result /= calculator->buffer[i + 1] - '0';
        break;
    }
  }
  calculator->result = result;
  return result;
}

int main() {
  Calculator* calculator = createCalculator();
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    addToCalculator(calculator, input[i]);
  }

  double result = calculate(calculator);

  printf("The result is: %.2lf\n", result);

  free(calculator);

  return 0;
}