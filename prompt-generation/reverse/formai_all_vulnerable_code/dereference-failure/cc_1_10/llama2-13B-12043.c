//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUMBER_OF_OPERATIONS 10

// Function to perform mathematical operations
void performMathOperations(char** operations) {
  int i, j, k;
  double result = 0;

  for (i = 0; i < MAX_NUMBER_OF_OPERATIONS; i++) {
    // Get the current operation and its operands
    char* currentOperation = operations[i];
    double operand1 = atof(currentOperation + 1);
    double operand2 = atof(currentOperation + 2);

    // Perform the operation
    switch (currentOperation[0]) {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      default:
        break;
    }

    // Print the result
    printf("%.2f\n", result);
  }
}

int main() {
  char** operations = malloc(MAX_NUMBER_OF_OPERATIONS * sizeof(char*));
  int i;

  // Get the mathematical expressions from the user
  for (i = 0; i < MAX_NUMBER_OF_OPERATIONS; i++) {
    printf("Enter a mathematical expression: ");
    scanf("%s", operations[i]);
  }

  // Perform the mathematical operations
  performMathOperations(operations);

  return 0;
}