//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include <stdio.h>

int main() {
  int n, i, j, temp, total = 0;
  printf("Enter the number of items: ");
  scanf("%d", &n);
  int weight[n], value[n], ratio[n];
  float capacity;
  printf("Enter the knapsack capacity: ");
  scanf("%f", &capacity);
  printf("Enter the weight and value of each item separately:\n");

  for (i = 0; i < n; i++) {
    scanf("%d %d", &weight[i], &value[i]);
    ratio[i] = value[i] / weight[i]; // calculate value-to-weight ratio
  }

  // sort items according to their ratio
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (ratio[j] > ratio[i]) {
        // swap the values based on the ratio
        temp = ratio[j];
        ratio[j] = ratio[i];
        ratio[i] = temp;
        temp = value[j];
        value[j] = value[i];
        value[i] = temp;
        temp = weight[j];
        weight[j] = weight[i];
        weight[i] = temp;
      }
    }
  }

  // fill the knapsack greedily
  for (i = 0; i < n; i++) {
    if (capacity == 0) {
      break; // check if the knapsack is full
    } else if (weight[i] <= capacity) {
      total += value[i];
      capacity -= weight[i];
    } else {
      total += ratio[i] * capacity; // fill the knapsack partially
      capacity = 0;
    }
  }

  printf("The maximum value that can be obtained is %d\n", total);
  return 0;
}