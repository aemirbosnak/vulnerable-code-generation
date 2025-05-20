//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initializing Variables
  int num_of_coins, target_sum, i, j;
  int *coin_values, *coin_counts;
  int sum_so_far = 0, coins_used = 0;

  // Taking Inputs
  printf("Enter the number of coins:");
  scanf("%d", &num_of_coins);

  coin_values = (int *) malloc(num_of_coins * sizeof(int));
  coin_counts = (int *) malloc(num_of_coins * sizeof(int));

  for (i = 0; i < num_of_coins; i++) {
    printf("Enter the value and count of coin %d: ", i + 1);
    scanf("%d %d", &coin_values[i], &coin_counts[i]);
  }

  printf("Enter the target sum: ");
  scanf("%d", &target_sum);

  printf("\nUsing greedy algorithm, we can select the coins in the following manner:\n");

  // Greedy Algorithm
  for (i = num_of_coins - 1; i >= 0; i--) {
    while (coin_counts[i] > 0) {
      if (coin_values[i] + sum_so_far <= target_sum) {
        sum_so_far += coin_values[i];
        coin_counts[i]--;
        coins_used++;
        printf("Coin %d used, remaining value to reach the target is %d\n",
               coin_values[i], target_sum - sum_so_far);
      } else {
        break;
      }
    }

    if (sum_so_far == target_sum) {
      break;
    }
  }

  // Output
  if (sum_so_far == target_sum) {
    printf("\nTarget sum reached using minimum coins.\n");
    printf("\nTotal coins used: %d\n", coins_used);
  } else {
    printf("\nTarget sum cannot be reached using the given coins.\n");
  }

  // Freeing memory
  free(coin_values);
  free(coin_counts);
  coin_values = NULL;
  coin_counts = NULL;

  return 0;
}