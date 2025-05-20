//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed with current time

  // array of operators for the math exercises
  char operators[4] = {'+', '-', '*', '/'};

  printf("Welcome to the Math Exercise Generator!\n");

  while (1) {
    printf("\nChoose a difficulty level (1-3) or enter 0 to quit: ");
    int level;
    scanf("%d", &level);

    if (level == 0) {
      printf("Goodbye!\n");
      break;
    } else if (level < 1 || level > 3) {
      printf("Invalid input. Please enter a number between 1 and 3.\n");
      continue;
    } else {
      int num1 = rand() % (level * 10); // first number for the exercise
      int num2 = rand() % (level * 10); // second number for the exercise
      char op = operators[rand() % 4]; // operator for the exercise
      
      printf("\nWhat is %d %c %d?\n", num1, op, num2);
      int answer;
      scanf("%d", &answer);

      // calculate actual answer based on operator
      int actual_answer;
      switch(op) {
        case '+':
          actual_answer = num1 + num2;
          break;
        case '-':
          actual_answer = num1 - num2;
          break;
        case '*':
          actual_answer = num1 * num2;
          break;
        case '/':
          actual_answer = num1 / num2;
          break;
      }

      if (answer == actual_answer) {
        printf("Correct!\n");
      } else {
        printf("Incorrect. The correct answer is %d\n", actual_answer);
      }
    }
  }

  return 0;
}