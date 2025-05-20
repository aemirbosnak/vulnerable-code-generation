//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
char *menu_items[] = {"Coffee", "Tea", "Soda", "Water", "Cookie", "Muffin", "Bagel", "Scone", "Sandwich", "Salad"};
float menu_prices[] = {1.99, 1.50, 1.25, 1.00, 0.50, 1.00, 1.50, 1.75, 4.99, 5.99};

// Define the order structure
typedef struct order {
  char *items[MAX_ITEMS];
  int quantities[MAX_ITEMS];
  float total_price;
} order;

// Function to create a new order
order *create_order() {
  order *new_order = malloc(sizeof(order));
  for (int i = 0; i < MAX_ITEMS; i++) {
    new_order->items[i] = NULL;
    new_order->quantities[i] = 0;
  }
  new_order->total_price = 0.0;
  return new_order;
}

// Function to add an item to an order
void add_item_to_order(order *order, char *item, int quantity) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (order->items[i] == NULL) {
      order->items[i] = item;
      order->quantities[i] = quantity;
      order->total_price += quantity * menu_prices[i];
      break;
    }
  }
}

// Function to print an order
void print_order(order *order) {
  printf("Order:\n");
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (order->items[i] != NULL) {
      printf("  %s x %d\n", order->items[i], order->quantities[i]);
    }
  }
  printf("Total: $%.2f\n", order->total_price);
}

// Function to free an order
void free_order(order *order) {
  for (int i = 0; i < MAX_ITEMS; i++) {
    free(order->items[i]);
  }
  free(order);
}

// Main function
int main() {
  // Create a new order
  order *order = create_order();

  // Add items to the order
  add_item_to_order(order, "Coffee", 2);
  add_item_to_order(order, "Tea", 1);
  add_item_to_order(order, "Cookie", 2);

  // Print the order
  print_order(order);

  // Free the order
  free_order(order);

  return 0;
}