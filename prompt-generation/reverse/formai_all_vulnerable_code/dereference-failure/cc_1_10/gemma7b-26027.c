//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
  char buffer[MAX_BUFFER_SIZE];
  int pos;
  int history[10];
  int historyPos;
  char operator;
  double result;
} Calculator;

Calculator* calculator_init() {
  Calculator* calc = (Calculator*)malloc(sizeof(Calculator));
  calc->pos = 0;
  calc->historyPos = 0;
  return calc;
}

void calculator_add(Calculator* calc, char operator, double number) {
  calc->operator = operator;
  sprintf(calc->buffer + calc->pos, "%lf", number);
  calc->pos += strlen(calc->buffer) + 1;
  calc->history[calc->historyPos++] = calc->result;
}

void calculator_subtract(Calculator* calc, char operator, double number) {
  calc->operator = operator;
  sprintf(calc->buffer + calc->pos, "%lf", number);
  calc->pos += strlen(calc->buffer) + 1;
  calc->history[calc->historyPos++] = calc->result;
}

void calculator_multiply(Calculator* calc, char operator, double number) {
  calc->operator = operator;
  sprintf(calc->buffer + calc->pos, "%lf", number);
  calc->pos += strlen(calc->buffer) + 1;
  calc->history[calc->historyPos++] = calc->result;
}

void calculator_divide(Calculator* calc, char operator, double number) {
  calc->operator = operator;
  sprintf(calc->buffer + calc->pos, "%lf", number);
  calc->pos += strlen(calc->buffer) + 1;
  calc->history[calc->historyPos++] = calc->result;
}

double calculator_calculate(Calculator* calc) {
  double result = 0.0;
  switch (calc->operator) {
    case '+':
      result = atof(calc->buffer) + calc->history[calc->historyPos - 1];
      break;
    case '-':
      result = atof(calc->buffer) - calc->history[calc->historyPos - 1];
      break;
    case '*':
      result = atof(calc->buffer) * calc->history[calc->historyPos - 1];
      break;
    case '/':
      result = atof(calc->buffer) / calc->history[calc->historyPos - 1];
      break;
  }
  calc->result = result;
  return result;
}

int main() {
  Calculator* calc = calculator_init();
  calculator_add(calc, '+', 10.0);
  calculator_add(calc, '*', 5.0);
  calculator_multiply(calc, '*', 2.0);
  calculator_divide(calc, '/', 4.0);
  calculator_calculate(calc);
  printf("The result is: %lf", calc->result);
  printf("\nThe history is:");
  for (int i = 0; i < calc->historyPos; i++) {
    printf("\t%lf", calc->history[i]);
  }
  return 0;
}