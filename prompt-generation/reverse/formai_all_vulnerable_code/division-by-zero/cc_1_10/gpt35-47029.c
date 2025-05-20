//FormAI DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int choice, num1, num2, answer, userAnswer, score = 0;
   srand(time(0)); // seed the random number generator
   
   printf("Welcome to the Math Exercise Program!\n");
   
   do {
       printf("\nPlease select the type of exercise:\n");
       printf("1. Addition\n");
       printf("2. Subtraction\n");
       printf("3. Multiplication\n");
       printf("4. Division\n");
       printf("5. Exit\n");
       printf("Your choice: ");
       scanf("%d", &choice);
       switch (choice) {
           case 1:
               num1 = rand() % 100;
               num2 = rand() % 100;
               printf("\nWhat is the sum of %d and %d? ", num1, num2);
               answer = num1 + num2;
               break;
           case 2:
               num1 = rand() % 100;
               num2 = rand() % num1;
               printf("\nWhat is the difference between %d and %d? ", num1, num2);
               answer = num1 - num2;
               break;
           case 3:
               num1 = rand() % 12;
               num2 = rand() % 12;
               printf("\nWhat is the product of %d and %d? ", num1, num2);
               answer = num1 * num2;
               break;
           case 4:
               num1 = rand() % 100;
               do {
                   num2 = rand() % 100;
               } while (num2 == 0); // to avoid division by zero
               printf("\nWhat is %d divided by %d (rounded to the nearest integer)? ", num1, num2);
               answer = (int) num1 / num2;
               break;
           case 5:
               printf("\nThank you for using the Math Exercise Program! Your final score is %d.\n", score);
               return 0;
           default:
               printf("\nInvalid choice. Please select again.\n");
               continue; // to start over the loop
       }
      
       scanf("%d", &userAnswer);
      
       if (userAnswer == answer) {
           printf("\nCorrect! Well done. ");
           score++;
       } else {
           printf("\nSorry, the correct answer is %d. ", answer);
       }
      
   } while (1); // infinite loop
}