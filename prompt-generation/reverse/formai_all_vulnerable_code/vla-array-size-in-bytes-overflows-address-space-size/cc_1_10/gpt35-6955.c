//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include<stdio.h>
#include<stdlib.h>

//Function to sort the weights in non-decreasing order
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void main() {
  //Enter the number of items and capacity of the knapsack
  int n, c;
  printf("Enter the number of items: \n");
  scanf("%d",&n);
  printf("Enter the capacity of the knapsack: \n");
  scanf("%d",&c);

  //Enter the weights and profits
  int w[n], p[n], i;
  for(i=0;i<n;i++) {
    printf("Enter the weight of item %d: \n", i+1);
    scanf("%d",&w[i]);
    printf("Enter the profit of item %d: \n", i+1);
    scanf("%d",&p[i]);
  }

  //Sort the items in non-decreasing order of their weights
  qsort(w, n, sizeof(int), cmpfunc);

  //Initialize the variables
  int cur_wt = 0, cur_pft = 0, rem_wt = c, j = n-1, taken[n];

  //All items are initially not taken
  for(i=0;i<n;i++) {
    taken[i] = 0;
  }

  //Loop through all the items until either all the items are considered or all the capacity is filled
  while(j>=0 && rem_wt > 0) {
    //If the weight of the current item is less than the remaining capacity
    if(w[j] <= rem_wt) {
      taken[j] = 1;
      cur_wt += w[j];
      cur_pft += p[j];
      rem_wt -= w[j];
    }
    //If the weight of the current item is more than the remaining capacity
    else {
      taken[j] = 0;
    }
    j--;
  }

  //Print the items that are taken and their profits
  printf("The taken items are: ");
  for(i=0;i<n;i++) {
    if(taken[i]) {
      printf("%d ", i+1);
    }
  }

  printf("\nThe total profit is: %d", cur_pft);

}