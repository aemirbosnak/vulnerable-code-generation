//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void addToBuffer(Calculator* calculator, char character) {
  if (calculator->top == MAX_BUFFER_SIZE - 1) {
    return;
  }
  calculator->buffer[++calculator->top] = character;
}

void clearBuffer(Calculator* calculator) {
  calculator->top = -1;
  calculator->result = 0.0;
}

double calculateExpression(Calculator* calculator) {
  double result = 0.0;
  char operator = '\0';
  for (int i = calculator->top; i >= 0; i--) {
    char character = calculator->buffer[i];
    switch (character) {
      case '+':
        operator = '+';
        break;
      case '-':
        operator = '-';
        break;
      case '*':
        operator = '*';
        break;
      case '/':
        operator = '/';
        break;
      case '=':
        switch (operator) {
          case '+':
            result = calculator->result + (double)atof(calculator->buffer[i - 1]);
            break;
          case '-':
            result = calculator->result - (double)atof(calculator->buffer[i - 1]);
            break;
          case '*':
            result = calculator->result * (double)atof(calculator->buffer[i - 1]);
            break;
          case '/':
            result = calculator->result / (double)atof(calculator->buffer[i - 1]);
            break;
          default:
            result = (double)atof(calculator->buffer[i]);
            break;
        }
        calculator->result = result;
        break;
    }
  }
  return result;
}

int main() {
  Calculator* calculator = createCalculator();
  addToBuffer(calculator, '5');
  addToBuffer(calculator, '2');
  addToBuffer(calculator, '+');
  addToBuffer(calculator, '3');
  addToBuffer(calculator, '=');
  double result = calculateExpression(calculator);
  printf("The result is: %.2lf", result);
  clearBuffer(calculator);
  return 0;
}