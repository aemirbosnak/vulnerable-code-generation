//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

// Defining struct to store weight and value of items
typedef struct Item 
{
   int value, weight;
} Item;

// Function to calculate maximum of two integers
int max(int a, int b) 
{
   return (a > b) ? a : b;
}

// Greedy approach to Knapsack problem
int knapsack(Item items[], int capacity, int n) 
{
   int i, j, profit = 0;
   // Sorting items based on value/weight ratio in descending order
   for (i = 0; i < n; i++) 
   {
      for (j = i + 1; j < n; j++) 
      {
         if ((double) items[i].value / items[i].weight < (double) items[j].value / items[j].weight) 
         {
            Item temp = items[i];
            items[i] = items[j];
            items[j] = temp;
         }
      }
   }

   // Adding items to the knapsack
   for (i = 0; i < n; i++) 
   {
      if (items[i].weight <= capacity) 
      {
         profit += items[i].value;
         capacity -= items[i].weight;
      } 
      else 
      {
         profit += (double) items[i].value / items[i].weight * capacity;
         break;
      }
   }
   return profit;
}

// Driver program to test the functions
int main() 
{
   int i, j, n, capacity;
   printf("Enter the number of items in Knapsack:");
   scanf("%d", &n);

   Item items[n];
   printf("Enter the values and weights of the items:\n");
   for (i = 0; i < n; i++) 
   {
      printf("Item %d:\n", i + 1);
      printf("Value = ");
      scanf("%d", &items[i].value);
      printf("Weight = ");
      scanf("%d", &items[i].weight);
   }

   printf("Enter the capacity of Knapsack:");
   scanf("%d", &capacity);

   int maxProfit = knapsack(items, capacity, n);
   printf("Maximum profit = %d\n", maxProfit);

   return 0;
}