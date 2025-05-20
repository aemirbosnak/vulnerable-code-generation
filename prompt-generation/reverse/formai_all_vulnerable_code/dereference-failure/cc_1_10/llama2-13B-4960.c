//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: excited
// 🎉 Math Exercise Extravaganza! 🎉

// 100 points if you can solve this bad boy! 😈

// Here's the deal, my fellow math whizzes:
// You have been tasked with creating a program that takes in a series of math expressions,
// evaluates them one by one, and then spits out the final result.
// But here's the twist! 🎉 Each expression can have multiple operators,
// and you have to evaluate them in the correct order.
// Oh, and did I mention that some expressions can have negative numbers? 😱
// Yeah, it's gonna be a wild ride! 🎢

// So, are you ready to show off your mad math skills? 💪
// Let's get this party started! 🎉

#include <stdio.h>
#include <string.h>

// Function to evaluate a single math expression
int evaluate(char *expression) {
  // Tokenize the expression into individual operators and numbers
  char *token = strtok(expression, " ");
  int num1 = atoi(token);
  token = strtok(NULL, " ");
  int op = atoi(token);
  token = strtok(NULL, " ");
  int num2 = atoi(token);

  // Evaluate the expression based on the operator
  int result;
  switch (op) {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      break;
    default:
      printf("Invalid operator\n");
      return 0;
  }

  // Return the result of the evaluation
  return result;
}

int main() {
  // Get the user's input
  char expression[100];
  printf("Enter a math expression: ");
  fgets(expression, 100, stdin);

  // Evaluate the expression
  int result = evaluate(expression);

  // Print the result
  printf("Result: %d\n", result);

  return 0;
}