//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* pointer1 = NULL;
   int* pointer2 = NULL;
   
   // Allocate memory for pointer1
   pointer1 = (int*) malloc(5 * sizeof(int));
   if(pointer1 == NULL) {
      printf("Error: Memory allocation for pointer1 failed\n");
      exit(1);
   }
   
   // Allocate memory for pointer2
   pointer2 = (int*) calloc(3, sizeof(int));
   if(pointer2 == NULL) {
      printf("Error: Memory allocation for pointer2 failed\n");
      exit(1);
   }

   // Set values for pointer1
   pointer1[0] = 1;
   pointer1[1] = 2;
   pointer1[2] = 3;
   pointer1[3] = 4;
   pointer1[4] = 5;
   
   // Set values for pointer2
   pointer2[0] = 6;
   pointer2[1] = 7;
   pointer2[2] = 8;
   
   // Print the values of pointer1
   printf("Values of pointer1: ");
   for(int i=0; i<5; i++) {
      printf("%d ", pointer1[i]);
   }
   printf("\n");
   
   // Print the values of pointer2
   printf("Values of pointer2: ");
   for(int i=0; i<3; i++) {
      printf("%d ", pointer2[i]);
   }
   printf("\n");
   
   // Reallocate memory for pointer1
   pointer1 = (int*) realloc(pointer1, 7 * sizeof(int));
   if(pointer1 == NULL) {
      printf("Error: Memory reallocation for pointer1 failed\n");
      exit(1);
   }
   
   // Set values for the newly allocated memory block in pointer1 
   pointer1[5] = 9;
   pointer1[6] = 10;
   
   // Print the values of pointer1 after reallocation
   printf("Values of pointer1 after reallocation: ");
   for(int i=0; i<7; i++) {
      printf("%d ", pointer1[i]);
   }
   printf("\n");

   // Free memory used by pointer1 and pointer2
   free(pointer1);
   free(pointer2);

   return 0;
}