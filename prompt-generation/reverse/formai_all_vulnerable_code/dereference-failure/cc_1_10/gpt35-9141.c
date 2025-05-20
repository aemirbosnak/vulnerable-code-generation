//FormAI DATASET v1.0 Category: Benchmarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacci(int n) {
   if(n <= 1)
      return n;
   return fibonacci(n-1) + fibonacci(n-2);
}

void surreal_sort(int *array, int size) {
   int swapped = 1, i = 0, j = 0;
   while(swapped) {
      swapped = 0;
      for(i = 0; i < size; i++) {
         for(j = 0; j < size-i-1; j++) {
            if(fibonacci(array[j]) > fibonacci(array[j+1])) {
               int temp = array[j];
               array[j] = array[j+1];
               array[j+1] = temp;
               swapped = 1;
            }
         }
      }
   }
}

void surreal_printer(int *array, int size) {
   printf("Surrealist sorted array is:");
   for(int i=0; i<size; i++) {
      printf("%d, ", fibonacci(array[i]));
   }
   printf("\n");
}

int main() {
   int size, *array;
   printf("Enter the size of the array: ");
   scanf("%d", &size);

   array = (int*) malloc(size * sizeof(int));
   srand(time(NULL));
   printf("The original array is: ");
   
   for(int i=0; i<size; i++) {
      int random_num = rand()%21;
      printf("%d, ", random_num);
      array[i] = random_num;
   }
   printf("\n");

   surreal_sort(array, size);
   surreal_printer(array, size);

   free(array);
   return 0;
}