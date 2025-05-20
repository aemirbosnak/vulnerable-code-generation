//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Item struct
typedef struct {
  int weight;
  int value;
} Item;

// Knapsack struct
typedef struct {
  int capacity;
  Item *items;
  int num_items;
} Knapsack;

// Compare function for qsort
int compare_items(const void *a, const void *b) {
  const Item *item1 = (const Item *)a;
  const Item *item2 = (const Item *)b;
  return (item2->value / item2->weight) - (item1->value / item1->weight);
}

// Greedy algorithm to fill the knapsack
void fill_knapsack(Knapsack *knapsack) {
  // Sort the items in decreasing order of value/weight ratio
  qsort(knapsack->items, knapsack->num_items, sizeof(Item), compare_items);

  // Initialize the current weight and value of the knapsack
  int current_weight = 0;
  int current_value = 0;

  // Iterate over the items
  for (int i = 0; i < knapsack->num_items; i++) {
    // If the current weight plus the weight of the item is less than or equal to the capacity of the knapsack, add the item to the knapsack
    if (current_weight + knapsack->items[i].weight <= knapsack->capacity) {
      current_weight += knapsack->items[i].weight;
      current_value += knapsack->items[i].value;
    }
  }

  // Print the total value of the items in the knapsack
  printf("Total value of items in knapsack: %d\n", current_value);
}

// Main function
int main() {
  // Initialize the knapsack
  Knapsack knapsack;
  knapsack.capacity = 50;
  knapsack.num_items = 5;
  knapsack.items = malloc(knapsack.num_items * sizeof(Item));

  // Populate the knapsack with items
  knapsack.items[0].weight = 10;
  knapsack.items[0].value = 60;
  knapsack.items[1].weight = 20;
  knapsack.items[1].value = 100;
  knapsack.items[2].weight = 30;
  knapsack.items[2].value = 120;
  knapsack.items[3].weight = 40;
  knapsack.items[3].value = 140;
  knapsack.items[4].weight = 50;
  knapsack.items[4].value = 160;

  // Fill the knapsack using the greedy algorithm
  fill_knapsack(&knapsack);

  return 0;
}