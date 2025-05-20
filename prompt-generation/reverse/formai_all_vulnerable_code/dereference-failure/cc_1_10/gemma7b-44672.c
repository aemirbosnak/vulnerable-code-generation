//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void inv_scientific_calculator(char **buffer, int *index) {
  char operator;
  double operand1, operand2;

  // Check if the buffer is full
  if (*index == MAX_BUFFER_SIZE - 1) {
    printf("Error: buffer overflow!\n");
    return;
  }

  // Get the operator
  operator = buffer[*index];

  // Get the first operand
  operand1 = atof(buffer[*index - 1]);

  // Get the second operand
  operand2 = atof(buffer[*index - 2]);

  // Perform the operation
  switch (operator) {
    case '+':
      buffer[*index] = '+';
      buffer[*index + 1] = '\0';
      *index++;
      break;
    case '-':
      buffer[*index] = '-';
      buffer[*index + 1] = '\0';
      *index++;
      break;
    case '*':
      buffer[*index] = '*';
      buffer[*index + 1] = '\0';
      *index++;
      break;
    case '/':
      buffer[*index] = '/';
      buffer[*index + 1] = '\0';
      *index++;
      break;
    case '^':
      buffer[*index] = '^';
      buffer[*index + 1] = '\0';
      *index++;
      break;
    default:
      printf("Error: invalid operator.\n");
      return;
  }

  // Print the result
  printf("%f\n", operand1 + operand2 * operator);
}

int main() {
  char **buffer = (char **)malloc(MAX_BUFFER_SIZE * sizeof(char *));
  int *index = (int *)malloc(sizeof(int));

  *index = 0;
  buffer[0] = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));

  inv_scientific_calculator(buffer, index);

  free(buffer);
  free(index);

  return 0;
}