//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void display();
int timer();
int calculateTime(clock_t start, clock_t end);
void displayResult(int timeTaken, int totalWordsTyped);

int main()
{
   display();

   char textToType[100] = "The quick brown fox jumps over the lazy dog.";
   char userTypedText[100];
   int i = 0, totalWordsTyped = 0;

   printf("\nType the above sentence as fast as you can!\n");

   clock_t start = clock();
   
   while (i < strlen(textToType)) {
      if (textToType[i] != ' '){
         userTypedText[i] = getchar();
      }
      else{
         userTypedText[i] = ' ';
         totalWordsTyped++;
      }
      i++;
   }
   userTypedText[i] = '\0'; 

   int timeTaken = calculateTime(start, clock());

   displayResult(timeTaken, totalWordsTyped);

   return 0;
}

void display(){
   printf("\n****************************************");
   printf("\n*** WELCOME TO THE TYPING SPEED TEST ***");
   printf("\n****************************************\n");
}

int calculateTime(clock_t start, clock_t end){
   return (end - start) / CLOCKS_PER_SEC;
}

void displayResult(int timeTaken, int totalWordsTyped) {
   printf("\nTyping speed test completed!\n");

   printf("\nTotal time taken   : %d seconds\n", timeTaken);
   printf("\nWords typed        : %d words\n", totalWordsTyped + 1);

   int typingSpeed = (totalWordsTyped + 1) * 60 / timeTaken;
   printf("\nTyping speed was   : %d words per minute!\n", typingSpeed);
   
   printf("\nTry again to improve your speed!\n");
}