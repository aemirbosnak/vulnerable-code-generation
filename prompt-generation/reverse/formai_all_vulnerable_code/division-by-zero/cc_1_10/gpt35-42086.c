//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program generates two random numbers and asks the user to solve a math problem using them */

int main() {
  int num1, num2; // storing the two random numbers
  char operator; // storing the operator for the math problem
  int correct_answer, user_answer; // storing the correct and user's answers respectively
  int attempts = 0; // counting the number of attempts the user takes
  srand(time(0)); // seeding the random number generator with the current time

  // generating two random numbers
  num1 = rand() % 100;
  num2 = rand() % 100;

  // selecting a random operator
  switch(rand() % 4) {
    case 0:
      operator = '+';
      correct_answer = num1 + num2;
      break;
    case 1:
      operator = '-';
      correct_answer = num1 - num2;
      break;
    case 2:
      operator = '*';
      correct_answer = num1 * num2;
      break;
    case 3:
      operator = '/';
      correct_answer = num1 / num2;
      break;
  }

  // asking the user to solve the math problem
  printf("What is %d %c %d? ", num1, operator, num2);
  scanf("%d", &user_answer);
  attempts++;

  // looping until the user enters the correct answer
  while(user_answer != correct_answer) {
    printf("Incorrect. Try again: ");
    scanf("%d", &user_answer);
    attempts++;
  }

  // displaying the result to the user
  printf("Correct! You took %d attempts to solve the problem.\n", attempts);

  return 0;
}