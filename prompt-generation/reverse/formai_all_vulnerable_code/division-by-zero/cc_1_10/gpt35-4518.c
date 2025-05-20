//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num1, num2, choice, answer;
  srand(time(NULL)); //seed random number generator with current time

  do {
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 5) {
      printf("Exiting...\n");
      break;
    }

    num1 = rand() % 100; //generate random number between 0-99
    num2 = rand() % 100;

    switch (choice) {
      case 1:
        printf("What is the sum of %d and %d? ", num1, num2);
        answer = num1 + num2;
        break;
      case 2:
        printf("What is the difference between %d and %d? ", num1, num2);
        answer = num1 - num2;
        break;
      case 3:
        printf("What is the product of %d and %d? ", num1, num2);
        answer = num1 * num2;
        break;
      case 4:
        printf("What is %d divided by %d? ", num1, num2);
        answer = num1 / num2;
        break;
      default:
        printf("Invalid choice. Try again.\n");
        continue; //skip to next iteration of loop
    }

    int user_answer;
    scanf("%d", &user_answer);

    if (user_answer == answer) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The correct answer is %d.\n", answer);
    }

  } while (choice != 5);

  return 0;
}