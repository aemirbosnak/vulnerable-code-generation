//FormAI DATASET v1.0 Category: Random ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimum(int arr[], int n) {
   int min = arr[0];
   
   for (int i = 1; i < n; i++) {
      if (arr[i] < min) {
         min = arr[i];
      }
   }
   
   return min;
}

int maximum(int arr[], int n) {
   int max = arr[0];
   
   for (int i = 1; i < n; i++) {
      if (arr[i] > max) {
         max = arr[i];
      }
   }
   
   return max;
}

int main() {
   int n;
   printf("Enter the number of elements in the array: ");
   scanf("%d", &n);

   int arr[n];
   srand(time(NULL));

   for (int i = 0; i < n; i++) {
      arr[i] = rand() % 100;
   }

   int min = minimum(arr, n);
   int max = maximum(arr, n);
   
   printf("Array: ");
   
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   
   printf("\nMinimum value: %d\n", min);
   printf("Maximum value: %d\n", max);
   
   return 0;
}