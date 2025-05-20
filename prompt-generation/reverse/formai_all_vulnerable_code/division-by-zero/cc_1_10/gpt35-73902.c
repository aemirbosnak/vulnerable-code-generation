//FormAI DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));  // Seed the random number generator

  int num1 = rand() % 101;  // Generate a random number between 0 and 100
  int num2 = rand() % 101;
  int operator = rand() % 4;

  switch(operator) {  // Choose a random math operator
    case 0:
      printf("What is the sum of %d and %d?\n", num1, num2);
      break;
    case 1:
      printf("What is the difference between %d and %d?\n", num1, num2);
      break;
    case 2:
      printf("What is the product of %d and %d?\n", num1, num2);
      break;
    case 3:
      printf("What is the quotient of %d and %d (rounded down to the nearest integer)?\n", num1, num2);
      break;
  }

  int correctAnswer;
  switch(operator) {  // Calculate the correct answer based on the chosen operator
    case 0:
      correctAnswer = num1 + num2;
      break;
    case 1:
      correctAnswer = num1 - num2;
      break;
    case 2:
      correctAnswer = num1 * num2;
      break;
    case 3:
      correctAnswer = num1 / num2;
      break;
  }

  int userAnswer;
  scanf("%d", &userAnswer);  // Get the user's answer

  if(userAnswer == correctAnswer) {
    printf("Correct!\n");
  } else {
    printf("Incorrect. The correct answer is %d.\n", correctAnswer);
  }

  return 0;
}