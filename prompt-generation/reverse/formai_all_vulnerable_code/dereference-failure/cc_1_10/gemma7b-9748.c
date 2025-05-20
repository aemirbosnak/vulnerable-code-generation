//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  int history[10];
  int historyPos;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = malloc(sizeof(Calculator));
  calc->pos = 0;
  calc->historyPos = 0;
  return calc;
}

void calculator_add(Calculator* calc, char num) {
  calc->buffer[calc->pos++] = num;
}

void calculator_clear(Calculator* calc) {
  calc->pos = 0;
}

double calculator_calculate(Calculator* calc) {
  double result = 0.0;
  int i = 0;
  for (i = 0; i < calc->pos; i++) {
    double num = calc->buffer[i] - '0';
    result += num * pow(10, calc->pos - i - 1);
  }
  return result;
}

void calculator_history(Calculator* calc) {
  calc->history[calc->historyPos++] = calculator_calculate(calc);
}

int main() {
  Calculator* calc = calculator_init();
  char input[MAX_BUFFER_SIZE];

  printf("Enter an expression: ");
  scanf("%s", input);

  for (int i = 0; input[i] != '\0'; i++) {
    calculator_add(calc, input[i]);
  }

  double result = calculator_calculate(calc);
  calculator_history(calc);

  printf("Result: %.2lf\n", result);

  return 0;
}