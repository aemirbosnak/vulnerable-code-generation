//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //seeding random number generator with system time

  int num1, num2, operator, answer, user_answer; //declaring integers for math problem and user answer

  int num_correct = 0; //to keep track of number of correct answers
  int num_questions = 0; //to keep track of number of questions asked 

  while(1) { //infinite loop until user exits

    //generating random numbers and operator
    num1 = rand() % 100;
    num2 = rand() % 100;
    operator = rand() % 4;

    //displaying math problem based on operator
    switch(operator) {
      case 0:
        answer = num1 + num2;
        printf("%d + %d = ", num1, num2);
        break;
      case 1:
        answer = num1 - num2;
        printf("%d - %d = ", num1, num2);
        break;
      case 2:
        answer = num1 * num2;
        printf("%d * %d = ", num1, num2);
        break;
      case 3:
        answer = num1 / num2;
        printf("%d / %d = ", num1, num2);
        break;
      default:
        printf("Oops something went wrong...");
        exit(0);
    }

    scanf("%d", &user_answer);

    num_questions++; //incrementing number of questions asked

    if(user_answer == answer) {
      printf("Correct!\n");
      num_correct++; //incrementing number of correct answers
    } else {
      printf("Incorrect, the answer was %d\n", answer);
    }

    printf("You have answered %d out of %d questions correctly.\n", num_correct, num_questions);

    char choice;
    printf("Would you like to continue? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'n') break; //if user chooses to stop, break out of loop
  }

  printf("Thank you for playing!");

  return 0;
}