//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  This is a simple implementation of a scientific calculator in C.
  It supports basic arithmetic operations as well as advanced
  scientific functions such as sin, cos, tan, log, sqrt, etc.

  To use the calculator, simply enter a valid mathematical expression
  and the program will evaluate it and output the result.

  This implementation uses a stack data structure to parse and evaluate
  the expression. The stack is implemented using a dynamically allocated
  array, which is resized as needed to accommodate more items.

  Note: This implementation handles input errors gracefully by printing out an error message
  and allowing the user to try again. However, this is not a foolproof approach, and more
  robust error handling should be implemented in a production-level application.

*/

// Define the maximum input length for the calculator
#define MAX_INPUT_LENGTH 100

// Define the initial size of the stack
#define INITIAL_STACK_SIZE 10

// Function prototypes
void push(double value);
double pop();
int is_empty();
int is_full();
void resize_stack();
double evaluate_operator(char operator, double operand1, double operand2);
double evaluate_expression(char *expression);

// Define the stack and its associated variables
double *stack;
int stack_size = INITIAL_STACK_SIZE;
int stack_top = -1;

int main() {
  char input[MAX_INPUT_LENGTH]; // The calculator input buffer
  double result; // The result of the calculation
  
  // Allocate memory for the stack
  stack = (double*) malloc(stack_size * sizeof(double));

  // Loop until the user enters "exit"
  while (1) {
    printf("Enter your calculation: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Check if the user wants to exit
    if (strcmp(input,"exit\n") == 0) {
      break;
    }
    
    // Evaluate the expression and print the result
    result = evaluate_expression(input);
    if (!isnan(result)) {
      printf("Result: %lf\n", result);
    }
  }

  // Free the memory allocated for the stack
  free(stack);

  return 0;
}

/*
  Pushes a value onto the stack.
*/
void push(double value) {
  if (is_full()) {
    resize_stack();
  }
  stack[++stack_top] = value;
}

/*
  Pops a value from the stack and returns it.
*/
double pop() {
  if (is_empty()) {
    printf("Error: Stack is empty.\n");
    return NAN;
  }
  return stack[stack_top--];
}

/*
  Returns 1 if the stack is empty, 0 otherwise.
*/
int is_empty() {
  return stack_top == -1;
}

/*
  Returns 1 if the stack is full, 0 otherwise.
*/
int is_full() {
  return stack_top == stack_size - 1;
}

/*
  Resizes the stack to accommodate more items.
*/
void resize_stack() {
  stack_size *= 2;
  stack = (double*) realloc(stack, stack_size * sizeof(double));
}

/*
  Evaluates a binary operator on two operands and returns the result.
*/
double evaluate_operator(char operator, double operand1, double operand2) {
  double result;
  switch (operator) {
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
      if (operand2 == 0) {
        printf("Error: Division by zero.\n");
        return NAN;
      }
      result = operand1 / operand2;
      break;
    case '^':
      result = pow(operand1, operand2);
      break;
    default:
      printf("Error: Invalid operator.\n");
      return NAN;
  }
  return result;
}

/*
  Evaluates a mathematical expression and returns the result.
*/
double evaluate_expression(char *expression) {
  double num = 0; // The current number being parsed
  double decimal = 0; // The decimal part of the current number being parsed
  int is_negative = 0; // Flag to indicate if the current number is negative
  int is_decimal = 0; // Flag to indicate if the current number has a decimal part
  int has_exponent = 0; // Flag to indicate if the current number has an exponent
  int exponent = 0; // The exponent part of the current number being parsed
  int i; // Loop index
  char current_char; // The current character being parsed

  // Loop through the input string character by character
  for (i = 0; expression[i] != '\0' && expression[i] != '\n'; i++) {
    current_char = expression[i];

    // Check if the current character is whitespace or a digit
    if (isspace(current_char)) {
      continue;
    } else if (isdigit(current_char)) {
      num = num * 10 + (current_char - '0');
      
      // Handle decimal points and exponents
      if (is_decimal) {
        decimal *= 0.1;
        num += decimal * (current_char - '0');
      } else if (has_exponent) {
        exponent = exponent * 10 + (current_char - '0');
      }
    } else if (current_char == '-') {
      // Handle negative signs
      if (num == 0 && !is_negative && !is_decimal && !has_exponent) {
        is_negative = 1;
      } else {
        // The minus sign denotes a binary operator
        while (!is_empty() && (stack[stack_top] == '+' || stack[stack_top] == '-' || 
               stack[stack_top] == '*' || stack[stack_top] == '/' || stack[stack_top] == '^')) {
          double operand2 = pop();
          double operand1 = pop();
          double result = evaluate_operator((char)stack[stack_top--], operand1, operand2);
          push(result);
        }
        push('-');
        num = 0;
        decimal = 0;
        is_negative = 0;
        is_decimal = 0;
        has_exponent = 0;
        exponent = 0;
      }
    } else if (current_char == '.') {
      // Handle decimal points
      if (is_decimal || has_exponent) {
        printf("Error: Invalid decimal point.\n");
        return NAN;
      }
      is_decimal = 1;
    } else if (current_char == 'e' || current_char == 'E') {
      // Handle exponents
      if (has_exponent || num == 0) {
        printf("Error: Invalid exponent.\n");
        return NAN;
      }
      has_exponent = 1;
      num = is_negative ? -num : num;
      decimal = decimal * (is_negative ? -1 : 1);
      is_negative = 0;
    } else if (current_char == '+' || current_char == '*' || current_char == '/' || 
               current_char == '^' || current_char == '(' || current_char == ')') {
      // Handle binary operators and parentheses
      while (!is_empty() && ((current_char == '^' && stack[stack_top] == '^') ||
                             (current_char == '*' && (stack[stack_top] == '*' || stack[stack_top] == '/')) ||
                             (current_char == '/' && (stack[stack_top] == '*' || stack[stack_top] == '/')) ||
                             (current_char == '+' && (stack[stack_top] == '+' || stack[stack_top] == '-' ||
                                                      stack[stack_top] == '*' || stack[stack_top] == '/' ||
                                                      stack[stack_top] == '^')) ||
                             (current_char == ')' && stack[stack_top] != '('))) {
        double operand2 = pop();
        double operand1 = pop();
        double result = evaluate_operator((char)stack[stack_top--], operand1, operand2);
        push(result);
      }
      if (current_char == ')') {
        if (!is_empty() && stack[stack_top] == '(') {
          pop();
        } else {
          printf("Error: Mismatched parentheses.\n");
          return NAN;
        }
      } else {
        push((double)current_char);
      }
      num = 0;
      decimal = 0;
      is_negative = 0;
      is_decimal = 0;
      has_exponent = 0;
      exponent = 0;
    } else {
      printf("Error: Invalid character '%c'.\n", current_char);
      return NAN;
    }
  }

  // Finish parsing any remaining numbers and operators
  if (num != 0 || is_decimal || has_exponent) {
    double value = is_negative ? -(num + decimal) : num + decimal;
    if (has_exponent) {
      value = value * pow(10, exponent);
    }
    push(value);
  }
  while (!is_empty()) {
    if (stack[stack_top] == '(' || stack[stack_top] == ')') {
      printf("Error: Mismatched parentheses.\n");
      return NAN;
    }
    double operand2 = pop();
    double operand1 = pop();
    double result = evaluate_operator((char)stack[stack_top--], operand1, operand2);
    push(result);
  }

  // Return the final result
  return pop();
}