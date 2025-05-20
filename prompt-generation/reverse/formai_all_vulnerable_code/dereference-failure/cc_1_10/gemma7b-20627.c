//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Calculator {
  int size;
  double **data;
} Calculator;

Calculator *createCalculator(int size) {
  Calculator *calc = malloc(sizeof(Calculator));
  calc->size = size;
  calc->data = malloc(size * sizeof(double *));
  for (int i = 0; i < size; i++) {
    calc->data[i] = malloc(size * sizeof(double));
  }
  return calc;
}

void freeCalculator(Calculator *calc) {
  for (int i = 0; i < calc->size; i++) {
    free(calc->data[i]);
  }
  free(calc->data);
  free(calc);
}

double calculate(Calculator *calc, char operator, double num) {
  switch (operator) {
    case '+':
      calc->data[calc->size - 1][calc->size - 1] += num;
      break;
    case '-':
      calc->data[calc->size - 1][calc->size - 1] -= num;
      break;
    case '*':
      calc->data[calc->size - 1][calc->size - 1] *= num;
      break;
    case '/':
      if (num == 0) {
        printf("Cannot divide by zero\n");
        return -1;
      }
      calc->data[calc->size - 1][calc->size - 1] /= num;
      break;
  }
  return calc->data[calc->size - 1][calc->size - 1];
}

int main() {
  Calculator *calc = createCalculator(MAX_SIZE);
  double result = calculate(calc, '+', 10);
  if (result != -1) {
    printf("The result is: %.2lf\n", result);
  }
  freeCalculator(calc);
  return 0;
}