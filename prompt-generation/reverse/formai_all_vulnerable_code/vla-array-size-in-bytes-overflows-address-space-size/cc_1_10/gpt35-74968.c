//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>

int main() {
   int n, i, j, temp, weight;
   float value, totalValue=0.0, capacity;

   printf("Enter the number of items: ");
   scanf("%d", &n);

   int weights[n], values[n];

   printf("Enter the weight and value of each item:\n");

   for(i=0; i<n; i++) {
      printf("Item %d: ", i+1);
      scanf("%d%f", &weights[i], &values[i]);
   }

   printf("Enter the maximum capacity of the knapsack: ");
   scanf("%f", &capacity);

   for(i=0; i<n-1; i++) {
      for(j=i+1; j<n; j++) {
         if(values[j]/weights[j] > values[i]/weights[i]) { // Sort items in descending order of value/weight
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;

            temp = weights[i];
            weights[i] = weights[j];
            weights[j] = temp;
         }
      }
   }

   printf("\nItems in the knapsack are:\n");

   for(i=0; i<n; i++) {
      if(weights[i] > capacity) {
         break;
      }
      printf("Item %d - %.2fkg - $%.2f\n", i+1, (float)weights[i], (float)values[i]);
      totalValue += values[i];
      capacity -= weights[i];
   }

   if(i < n){
      value = values[i] * (capacity/weights[i]);   // Add fractional item if space left in knapsack
      printf("Item %d - %.2fkg - $%.2f\n", i+1, (float)capacity, value);
      totalValue += value;
   }

   printf("\nTotal value of items in knapsack: $%.2f\n", totalValue);

   return 0;
}