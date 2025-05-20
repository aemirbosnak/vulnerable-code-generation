//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int main() {
  // Declare variables
  int num1, num2, answer, user_answer;
  char operator;

  // Seed the random number generator
  srand(time(NULL));

  // Generate two random numbers
  num1 = rand() % MAX_NUM;
  num2 = rand() % MAX_NUM;

  // Generate a random operator
  operator = "+-*/"[rand() % 4];

  // Print the problem
  printf("Solve the following problem: %d %c %d = ", num1, operator, num2);

  // Get the user's answer
  scanf("%d", &user_answer);

  // Calculate the correct answer
  switch (operator) {
    case '+':
      answer = num1 + num2;
      break;
    case '-':
      answer = num1 - num2;
      break;
    case '*':
      answer = num1 * num2;
      break;
    case '/':
      answer = num1 / num2;
      break;
  }

  // Check if the user's answer is correct
  if (user_answer == answer) {
    // Print a congratulatory message
    printf("Congratulations! Your answer is correct.\n");
  } else {
    // Print an error message
    printf("Sorry, your answer is incorrect. The correct answer is %d.\n", answer);
  }

  return 0;
}