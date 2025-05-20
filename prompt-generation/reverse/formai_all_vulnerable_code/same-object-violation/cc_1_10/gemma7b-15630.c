//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void calculate(char **buffer, int *size) {
  int i, j, operator_precedence = 0, number_of_operators = 0, is_operator_valid = 0;
  char operator, number[MAX_BUFFER_SIZE];

  for (i = 0; i < *size; i++) {
    if (buffer[i] >= 'a' && buffer[i] <= 'z') {
      operator = buffer[i];
      number_of_operators++;
    } else if (buffer[i] >= '0' && buffer[i] <= '9') {
      number[number_of_operators] = buffer[i];
    } else if (buffer[i] == '+') {
      operator_precedence++;
    } else if (buffer[i] == '-') {
      operator_precedence++;
    } else if (buffer[i] == '*') {
      operator_precedence++;
    } else if (buffer[i] == '/') {
      operator_precedence++;
    }
  }

  if (number_of_operators > 0) {
    is_operator_valid = 1;
  }

  if (is_operator_valid) {
    switch (operator) {
      case '+':
        printf("%d + %d = %d\n", number[0], number[1], number[0] + number[1]);
        break;
      case '-':
        printf("%d - %d = %d\n", number[0], number[1], number[0] - number[1]);
        break;
      case '*':
        printf("%d * %d = %d\n", number[0], number[1], number[0] * number[1]);
        break;
      case '/':
        if (number[1] == 0) {
          printf("Cannot divide by zero\n");
        } else {
          printf("%d / %d = %d\n", number[0], number[1], number[0] / number[1]);
        }
        break;
    }
  } else {
    printf("Invalid expression\n");
  }
}

int main() {
  char buffer[MAX_BUFFER_SIZE];
  int size = 0;

  printf("Enter an expression: ");
  getline(buffer, MAX_BUFFER_SIZE, stdin);

  size = strlen(buffer);

  calculate(buffer, &size);

  return 0;
}