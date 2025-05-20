//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, answer, guess, max = 100;
  int correct = 0, incorrect = 0;
  char op[3];

  srand(time(0));
  
  printf("Welcome to the Math Game!\n");
  printf("You will be given an addition or subtraction question.\n");
  printf("You get 3 chances per question. Good luck!\n\n");

  for(int i = 0; i < 5; i++) {

    if(rand() % 2 == 0) {
      num1 = rand() % max;
      num2 = rand() % max;
      answer = num1 + num2;
      sprintf(op, "+");
    } else {
      num1 = rand() % max;
      num2 = rand() % num1;
      answer = num1 - num2;
      sprintf(op, "-");
    }

    printf("Question %d: %d %s %d = ?", i+1, num1, op, num2);

    for(int j = 0; j < 3; j++) {
      printf("\nAttempt %d: ", j+1);
      scanf("%d", &guess);

      if(guess == answer) {
        printf("Correct!\n");
        correct++;
        break;
      } else {
        if(j == 2) {
          printf("Incorrect. The answer was %d.\n", answer);
          incorrect++;
        } else {
          printf("Incorrect. Try again.\n");
        }
      }
    }

    printf("\n");
  }

  printf("Game over! You answered %d questions correctly and %d questions incorrectly.\n", correct, incorrect);
  printf("Thanks for playing!\n");

  return 0;
}