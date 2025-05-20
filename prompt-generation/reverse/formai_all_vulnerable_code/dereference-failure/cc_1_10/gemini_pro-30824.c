//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
int is_operator(char ch);
int get_precedence(char ch);
int infix_to_postfix(char *infix, char *postfix);
int evaluate_postfix(char *postfix);

// Main function
int main() {
  char infix[100], postfix[100];
  int result;

  // Get the infix expression from the user
  printf("Enter an infix expression: ");
  gets(infix);

  // Convert the infix expression to postfix expression
  if (infix_to_postfix(infix, postfix)) {
    printf("Invalid infix expression\n");
    return 1;
  }

  // Evaluate the postfix expression
  result = evaluate_postfix(postfix);

  // Print the result
  printf("Result: %d\n", result);

  return 0;
}

// Function to check if a character is an operator
int is_operator(char ch) {
  switch (ch) {
    case '+':
    case '-':
    case '*':
    case '/':
      return 1;
    default:
      return 0;
  }
}

// Function to get the precedence of an operator
int get_precedence(char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return 0;
  }
}

// Function to convert an infix expression to a postfix expression
int infix_to_postfix(char *infix, char *postfix) {
  int i, j, stack[100], top = -1;
  char ch;

  for (i = 0; infix[i] != '\0'; i++) {
    ch = infix[i];

    if (ch == '(') {
      stack[++top] = ch;
    } else if (ch == ')') {
      while (top != -1 && stack[top] != '(') {
        postfix[j++] = stack[top--];
      }
      if (top == -1) {
        return 1;
      }
      top--;
    } else if (is_operator(ch)) {
      while (top != -1 && get_precedence(stack[top]) >= get_precedence(ch)) {
        postfix[j++] = stack[top--];
      }
      stack[++top] = ch;
    } else {
      postfix[j++] = ch;
    }
  }

  while (top != -1) {
    postfix[j++] = stack[top--];
  }

  postfix[j] = '\0';

  return 0;
}

// Function to evaluate a postfix expression
int evaluate_postfix(char *postfix) {
  int i, stack[100], top = -1;
  int op1, op2, result;
  char ch;

  for (i = 0; postfix[i] != '\0'; i++) {
    ch = postfix[i];

    if (isdigit(ch)) {
      stack[++top] = ch - '0';
    } else {
      op2 = stack[top--];
      op1 = stack[top--];

      switch (ch) {
        case '+':
          result = op1 + op2;
          break;
        case '-':
          result = op1 - op2;
          break;
        case '*':
          result = op1 * op2;
          break;
        case '/':
          result = op1 / op2;
          break;
      }

      stack[++top] = result;
    }
  }

  return stack[top];
}