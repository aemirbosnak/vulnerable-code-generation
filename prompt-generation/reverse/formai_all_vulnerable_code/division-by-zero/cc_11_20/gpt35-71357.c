//FormAI DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>

int main() {
  printf("************************************************\n");
  printf("*** Welcome to the Ultimate Arithmetic Game! ***\n");
  printf("************************************************\n");

  int num1 = 0, num2 = 0, operator = 0, answer = 0, userAnswer = 0, score = 0;
  char playAgain;

  do {
    printf("\nEnter your first number: ");
    scanf("%d", &num1);

    printf("Enter your second number: ");
    scanf("%d", &num2);

    printf("\nChoose your operator:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Enter the number of your choice: ");
    scanf("%d", &operator);

    switch (operator) {
      case 1:
        answer = num1 + num2;
        break;
      case 2:
        answer = num1 - num2;
        break;
      case 3:
        answer = num1 * num2;
        break;
      case 4:
        answer = num1 / num2;
        break;
      default:
        printf("Invalid operator.\n");
    }

    printf("\nWhat is the answer to %d %c %d? ", num1, operator == 1 ? '+' : operator == 2 ? '-' : operator == 3 ? '*' : '/', num2);
    scanf("%d", &userAnswer);
    if (userAnswer == answer) {
      printf("\nCorrect!\n");
      score++;
    } else {
      printf("\nIncorrect! The correct answer is %d.\n", answer);
    }

    printf("Your current score is %d.\n", score);
    printf("\nDo you want to play again? (y/n): ");
    scanf("%s", &playAgain);

  } while (playAgain == 'y' || playAgain == 'Y');

  printf("\nThanks for playing! Your final score is %d.\n", score);

  return 0;
}