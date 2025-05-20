//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_receipt(char **items, int num_items, int total_cost) {
  printf("--------------------------------------------------------\n");
  printf("The Great Baker Street Detective Agency\n");
  printf("--------------------------------------------------------\n");
  printf("Items:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s - %d\n", items[i], items[i][0] * items[i][1]);
  }
  printf("Total Cost: $%d\n", total_cost);
  printf("--------------------------------------------------------\n");
}

int main() {
  char **items = NULL;
  int num_items = 0;
  int total_cost = 0;

  // Create a list of items
  items = malloc(sizeof(char *) * 3);
  items[0] = malloc(sizeof(char) * 2);
  items[0] = "Tea";
  items[0][1] = 2;

  items[1] = malloc(sizeof(char) * 2);
  items[1] = "Coffee";
  items[1][1] = 3;

  items[2] = malloc(sizeof(char) * 2);
  items[2] = "Biscuits";
  items[2][1] = 1;

  // Calculate the total cost
  for (int i = 0; i < num_items; i++) {
    total_cost += items[i][0] * items[i][1];
  }

  // Print the receipt
  print_receipt(items, num_items, total_cost);

  // Free the memory
  for (int i = 0; i < num_items; i++) {
    free(items[i]);
  }
  free(items);

  return 0;
}