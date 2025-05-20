//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  // Welcome the user to the surrealist scientific calculator.
  printf("Welcome to the surrealist scientific calculator!\n");
  printf("This calculator is designed to help you explore the world of mathematics in a new and creative way.\n");
  printf("Please feel free to experiment with the different functions and see what you can discover.\n");

  // Get the user's input.
  printf("What calculation would you like to perform?\n");
  char input[1024];
  fgets(input, 1024, stdin);

  // Parse the user's input.
  char *token;
  token = strtok(input, " ");
  char *operator;
  char *operand1;
  char *operand2;
  while (token != NULL) {
    if (strcmp(token, "+") == 0) {
      operator = token;
    } else if (strcmp(token, "-") == 0) {
      operator = token;
    } else if (strcmp(token, "*") == 0) {
      operator = token;
    } else if (strcmp(token, "/") == 0) {
      operator = token;
    } else if (strcmp(token, "^") == 0) {
      operator = token;
    } else if (strcmp(token, "sqrt") == 0) {
      operator = token;
    } else if (strcmp(token, "log") == 0) {
      operator = token;
    } else if (strcmp(token, "sin") == 0) {
      operator = token;
    } else if (strcmp(token, "cos") == 0) {
      operator = token;
    } else if (strcmp(token, "tan") == 0) {
      operator = token;
    } else {
      if (operand1 == NULL) {
        operand1 = token;
      } else if (operand2 == NULL) {
        operand2 = token;
      }
    }
    token = strtok(NULL, " ");
  }

  // Perform the calculation.
  double result;
  if (strcmp(operator, "+") == 0) {
    result = atof(operand1) + atof(operand2);
  } else if (strcmp(operator, "-") == 0) {
    result = atof(operand1) - atof(operand2);
  } else if (strcmp(operator, "*") == 0) {
    result = atof(operand1) * atof(operand2);
  } else if (strcmp(operator, "/") == 0) {
    result = atof(operand1) / atof(operand2);
  } else if (strcmp(operator, "^") == 0) {
    result = pow(atof(operand1), atof(operand2));
  } else if (strcmp(operator, "sqrt") == 0) {
    result = sqrt(atof(operand1));
  } else if (strcmp(operator, "log") == 0) {
    result = log(atof(operand1));
  } else if (strcmp(operator, "sin") == 0) {
    result = sin(atof(operand1));
  } else if (strcmp(operator, "cos") == 0) {
    result = cos(atof(operand1));
  } else if (strcmp(operator, "tan") == 0) {
    result = tan(atof(operand1));
  }

  // Print the result.
  printf("The result is: %f\n", result);

  return 0;
}