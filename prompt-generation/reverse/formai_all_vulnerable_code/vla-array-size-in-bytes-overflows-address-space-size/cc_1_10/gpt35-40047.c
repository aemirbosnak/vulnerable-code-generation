//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Donald Knuth
/* 
   C Searching Algorithm Example Program
   Inspired by Donald Knuth
*/

#include <stdio.h>

int binary_search(int arr[], int low, int high, int x) {

   while (low <= high) {
      int mid = low + (high - low)/2;

      //If x is present at middle 
      if (arr[mid] == x) return mid; 

      //If x greater, ignore left half 
      if (arr[mid] < x) low = mid + 1; 

      //If x is smaller, ignore right half 
      else high = mid - 1; 
   }

   //Element not present
   return -1; 
}

int main() {

   int n, x;

   printf("Enter number of elements: ");
   scanf("%d", &n);

   int arr[n];

   printf("Enter %d elements in ascending order: ", n);
   for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }

   printf("Enter the element you want to search: ");
   scanf("%d", &x);

   int result = binary_search(arr, 0, n-1, x);

   if(result == -1) {
      printf("Element not found in the array.");
   } else {
      printf("Element found at index: %d", result);
   }

   return 0;
}