//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void calculate(char **buffer, int *index, double *result) {
  double num1, num2;
  char operator;

  num1 = atof(buffer[*index - 1]);
  num2 = atof(buffer[*index]);
  operator = buffer[*index - 2];

  switch (operator) {
    case '+':
      *result = num1 + num2;
      break;
    case '-':
      *result = num1 - num2;
      break;
    case '*':
      *result = num1 * num2;
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: division by zero is not allowed");
        return;
      }
      *result = num1 / num2;
      break;
  }

  *index++;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int index = 0;
  double result = 0;

  printf("Enter an expression: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  while (buffer[index] != '\0') {
    calculate(&buffer, &index, &result);
  }

  printf("The result is: %.2lf", result);

  return 0;
}