//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of items in the order
#define MAX_ITEMS 10

// Define the menu items and their prices
char *menu_items[] = {"Coffee", "Tea", "Soda", "Water", "Cookie", "Muffin", "Scone", "Bagel", "Sandwich", "Salad"};
double menu_prices[] = {1.50, 1.25, 1.00, 0.50, 0.75, 1.25, 1.50, 1.75, 4.50, 5.00};

// Define the order struct
typedef struct order {
  char *item;
  int quantity;
  double price;
} order;

// Create a new order
order *new_order() {
  order *o = malloc(sizeof(order));
  o->item = NULL;
  o->quantity = 0;
  o->price = 0.0;
  return o;
}

// Add an item to the order
void add_item(order *o, char *item, int quantity) {
  // Find the item in the menu
  int i;
  for (i = 0; i < MAX_ITEMS; i++) {
    if (strcmp(item, menu_items[i]) == 0) {
      break;
    }
  }

  // If the item was found, add it to the order
  if (i < MAX_ITEMS) {
    o->item = item;
    o->quantity += quantity;
    o->price += menu_prices[i] * quantity;
  }
}

// Print the order
void print_order(order *o) {
  printf("Item\tQuantity\tPrice\n");
  printf("%s\t%d\t%.2f\n", o->item, o->quantity, o->price);
}

// Calculate the total price of the order
double calculate_total(order *o) {
  return o->price;
}

// Free the order
void free_order(order *o) {
  free(o->item);
  free(o);
}

// Main function
int main() {
  // Create a new order
  order *o = new_order();

  // Add items to the order
  add_item(o, "Coffee", 2);
  add_item(o, "Tea", 1);
  add_item(o, "Muffin", 1);

  // Print the order
  print_order(o);

  // Calculate the total price of the order
  double total = calculate_total(o);

  // Print the total price
  printf("Total: %.2f\n", total);

  // Free the order
  free_order(o);

  return 0;
}