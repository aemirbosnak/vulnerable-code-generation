//FormAI DATASET v1.0 Category: Memory management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() {

   //Create a pointer to an array of integers
   int *ptr;
   int size = 5;
   ptr = (int*)malloc(size * sizeof(int)); //allocating memory dynamically
   
   //Fill the array with some values
   for(int i=0; i<size; i++) {
      ptr[i] = i+1;
   }
   
   //Print the original array
   printf("Original array: \n");
   for(int i=0; i<size; i++) {
      printf("%d ", ptr[i]);
   }
   
   //Reallocate memory
   size = 10;
   ptr = (int*)realloc(ptr, size * sizeof(int));
   
   //Add some values to the new space in memory
   for(int i=5; i<size; i++) {
      ptr[i] = i+1;
   }
   
   //Print the new array
   printf("\n\nNew array: \n");
   for(int i=0; i<size; i++) {
      printf("%d ", ptr[i]);
   }
   
   //Free the allocated memory
   free(ptr);
   
   return 0;
}

/*
Expected output:
Original array: 
1 2 3 4 5 

New array: 
1 2 3 4 5 6 7 8 9 10 
*/