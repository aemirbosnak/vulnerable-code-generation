//FormAI DATASET v1.0 Category: Memory management ; Style: funny
#include<stdio.h>

int main(){

   int *ptr;
   
   printf("Welcome to the Memory Management World!\n");
   printf("I am Picky, the Pointer\n");
   printf("And now, let me allocate some memory for you!\n");

   ptr = (int*) malloc(5 * sizeof(int));

   if (ptr == NULL) {
       printf("Oh no! Memory allocation failed!\n");
       printf("Looks like I'm running low on memory :(\n");
       return 1;
   }
   
   printf("Yay! Memory allocation successful!\n");
   printf("Now, let me show you how to waste memory:\n");

   for (int i = 0; i < 5; i++) {
       printf("Let me allocate another chunk of memory...\n");
       int *temp = (int*) malloc(sizeof(int));
       if (temp == NULL) {
           printf("Oops, I ran out of memory again. Sorry!\n");
           printf("Seems like your computer needs some extra RAMs\n");
           return 1;
       }
       else {
           printf("Allocation successful again! Let's waste it!\n");
           *temp = i;
           printf("I allocated value %d in this chunk of memory.\n", *temp);
       }
   }
   
   printf("Now it's time to free up the memory. Are you ready?\n");

   free(ptr);
   
   printf("Memory freed! Now let's try accessing the freed memory...\n");

   for (int i = 0; i < 5; i++) {
       printf("Trying to access freed memory chunk %d...\n", i+1);
       printf("Oops, Segmentation fault! Silly me, I forgot to reassign the pointer.\n");
       printf("Well, that's all for today. Hope you had fun learning about memory management from me, Picky the Pointer!\n");
   }

   return 0;
}