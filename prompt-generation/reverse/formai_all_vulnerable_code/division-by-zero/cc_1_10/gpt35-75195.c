//FormAI DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int firstNum, secondNum, userAnswer, actualAnswer;
   int counter = 1;
   double percentage;
   char option;
   
   srand(time(0));  // srand() function is used to generate random numbers based on the time of the system clock.
   
   printf("\n Welcome to the Math Exercise Program \n\n");
   printf("Choose an operation: \n\n Enter 'a' for addition \n\n Enter 's' for subtraction \n\n Enter 'm' for multiplication \n\n");
   
   scanf(" %c", &option);
   
   while(option == 'a' || option == 's' || option == 'm') {
      printf("\n Task %d \n", counter);
      if(option == 'a') {
         firstNum = rand() % 100;  
         secondNum = rand() % 100;
         actualAnswer = firstNum + secondNum;
         printf("Calculate the sum of %d and %d \n", firstNum, secondNum);
      }
      else if(option == 's') {
         firstNum = rand() % 100;
         secondNum = rand() % firstNum;
         actualAnswer = firstNum - secondNum;
         printf("Calculate %d - %d \n", firstNum, secondNum);
      }
      else if(option == 'm') {
         firstNum = rand() % 10;
         secondNum = rand() % 10;
         actualAnswer = firstNum * secondNum;
         printf("Calculate %d * %d \n", firstNum, secondNum);
      }
      
      scanf("%d", &userAnswer);
      
      if(userAnswer == actualAnswer) {
         printf("\n Correct Answer! \n");
      }
      else {
         printf("\n Incorrect Answer! The correct answer is %d. \n", actualAnswer);
      }
      
      percentage = (double)counter / 10 * 100; // to calculate the percentage value of task completion
      printf("You have completed %d tasks out of 10 (%.0f%%) \n", counter, percentage);
      counter++;
      
      if(counter > 10) {
         counter = 1;
         printf("\n Do you want to continue practicing? Press any key to continue. Press 'q' to exit. \n");
         scanf(" %c", &option);
         if(option == 'q') {
            printf("\n Thank you for using this program. \n");
            break;
         }
      }
   }
   return 0;
}