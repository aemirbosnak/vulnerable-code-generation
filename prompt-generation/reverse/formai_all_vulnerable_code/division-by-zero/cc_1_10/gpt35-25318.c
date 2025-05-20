//FormAI DATASET v1.0 Category: Math exercise ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Math Exercise program!\n\n");

  // Generate two random numbers to use for the problem
  srand(time(NULL));
  int num1 = rand() % 21;  // Range from 0 to 20
  int num2 = rand() % 21;

  // Ask the user what operation to perform
  printf("What operation would you like to perform?\n");
  printf("\t1) Addition\n");
  printf("\t2) Subtraction\n");
  printf("\t3) Multiplication\n");
  printf("\t4) Division (round down to nearest integer)\n\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  // Perform the selected operation and get the user's answer
  int expected_answer;
  char operation;
  switch (choice) {
    case 1:
      expected_answer = num1 + num2;
      operation = '+';
      break;
    case 2:
      expected_answer = num1 - num2;
      operation = '-';
      break;
    case 3:
      expected_answer = num1 * num2;
      operation = '*';
      break;
    case 4:
      expected_answer = num1 / num2;
      operation = '/';
      break;
    default:
      printf("Invalid choice. Exiting...\n");
      return 1;
  }

  printf("\nWhat is %d %c %d? ", num1, operation, num2);

  int user_answer;
  scanf("%d", &user_answer);

  // Check if the user's answer is correct
  if (user_answer == expected_answer) {
    printf("Congratulations! You got it right!\n");
  } else {
    printf("Sorry, that's incorrect. The correct answer is %d.\n", expected_answer);
  }

  return 0;
}