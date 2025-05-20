//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Set up variables
   int num1, num2, sum, difference, product, quotient, remainder, userAnswer, correct = 0, incorrect = 0;
   char operator;
   srand(time(NULL)); // Seed random number generator
   
   printf("\n**************************************");
   printf("\nWelcome to the Math Exercise Program!");
   printf("\n**************************************\n");
   
   // Loop through 10 questions
   for (int i = 0; i < 10; i++) {
      // Generate random numbers and operator
      num1 = rand() % 50;
      num2 = rand() % 50;
      switch (rand() % 4) {
         case 0:
            operator = '+';
            sum = num1 + num2;
            printf("\nQuestion %d: What is %d %c %d? ", i+1, num1, operator, num2);
            scanf("%d", &userAnswer);
            if (userAnswer == sum) {
               printf("Correct!");
               correct++;
            }
            else {
               printf("Incorrect, the answer was %d", sum);
               incorrect++;
            }
            break;
         case 1:
            operator = '-';
            difference = num1 - num2;
            printf("\nQuestion %d: What is %d %c %d? ", i+1, num1, operator, num2);
            scanf("%d", &userAnswer);
            if (userAnswer == difference) {
               printf("Correct!");
               correct++;
            }
            else {
               printf("Incorrect, the answer was %d", difference);
               incorrect++;
            }
            break;
         case 2:
            operator = '*';
            product = num1 * num2;
            printf("\nQuestion %d: What is %d %c %d? ", i+1, num1, operator, num2);
            scanf("%d", &userAnswer);
            if (userAnswer == product) {
               printf("Correct!");
               correct++;
            }
            else {
               printf("Incorrect, the answer was %d", product);
               incorrect++;
            }
            break;
         case 3:
            operator = '/';
            quotient = num1 / num2;
            remainder = num1 % num2;
            printf("\nQuestion %d: What is %d %c %d (rounded down)? ", i+1, num1, operator, num2);
            scanf("%d", &userAnswer);
            if (userAnswer == quotient) {
               printf("Correct!");
               correct++;
            }
            else {
               printf("Incorrect, the answer was %d with a remainder of %d", quotient, remainder);
               incorrect++;
            }
            break;
      }
   }
   
   // Print results
   printf("\n\n**************************************");
   printf("\nYou answered %d questions correctly and %d questions incorrectly.", correct, incorrect);
   printf("\nThanks for playing!");
   printf("\n**************************************\n");
   
   return 0;
}