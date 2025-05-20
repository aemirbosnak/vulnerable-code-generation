//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int num1, num2, result, choice, answer, correct = 0, total = 0;
  float percentage;
  
  srand(time(NULL)); // Initialize random seed
  
  printf("Welcome to the Math Exercise program!\n\n");
  printf("=====================================\n\n");
  
  // While loop to continue program until user decides to exit
  while (1) {
    printf("Please select the type of exercise you want to do:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division (answer is rounded to 2 decimal places)\n");
    printf("5. Exit program\n\n");
    
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    
    if (choice == 5) {
      printf("\nGoodbye!\n");
      break; // Exit program
    }
    
    printf("\nHow many questions do you want to answer? ");
    scanf("%d", &num1);
    
    printf("\nWhat is the maximum value of the numbers used in the exercise? ");
    scanf("%d", &num2);
    
    printf("\nYour exercise is ready!\n\n");
    
    // For loop to generate exercises and ask for user input
    for (int i = 0; i < num1; i++) {
      int symbol = rand() % 2; // Randomly choose either + or -
      int num3 = rand() % num2 + 1; // Random number between 1 and num2
      
      switch (choice) {
        case 1: // Addition
          num1 = rand() % num2 + 1;
          num2 = rand() % num2 + 1;
          result = num1 + num2;
          printf("%d + %d = ", num1, num2);
          scanf("%d", &answer);
          break;
        case 2: // Subtraction
          num1 = rand() % num2 + 1;
          num2 = rand() % num2 + 1;
          result = num1 - num2;
          printf("%d - %d = ", num1, num2);
          scanf("%d", &answer);
          break;
        case 3: // Multiplication
          num1 = rand() % num2 + 1;
          num2 = rand() % num2 + 1;
          result = num1 * num2;
          printf("%d * %d = ", num1, num2);
          scanf("%d", &answer);
          break;
        case 4: // Division (rounded to 2 decimal places)
          num1 = rand() % num2 + 1;
          num2 = rand() % num2 + 1;
          result = num1 / (float)num2;
          printf("%d / %d = ", num1, num2);
          scanf("%f", &percentage);
          answer = roundf(percentage * 100) / 100; // Round input to 2 decimal places
          break;
        default:
          printf("Invalid choice\n");
          break;
      }
      
      if (answer == result) {
        printf("Correct!\n\n");
        correct++;
      }
      else {
        printf("Wrong. The correct answer is %d\n\n", result);
      }
      total++;
    }
    
    percentage = (float)correct / total * 100;
    printf("You have answered %d out of %d questions correctly (%.2f%%).\n\n", correct, total, percentage);
  }
  
  return 0;
}