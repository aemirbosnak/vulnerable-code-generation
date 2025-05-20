//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the menu items and their prices
char *menu_items[] = {"Coffee", "Tea", "Soda", "Water", "Muffin", "Scone", "Cookie", "Cake", "Pie", "Ice Cream"};
double menu_prices[] = {1.50, 1.25, 1.00, 0.50, 2.00, 2.50, 1.00, 3.00, 3.50, 2.50};

// Define the order struct
typedef struct order {
  char *items[MAX_ITEMS];
  int quantities[MAX_ITEMS];
  double prices[MAX_ITEMS];
  double total_price;
} order;

// Create a new order
order *new_order() {
  order *o = malloc(sizeof(order));
  o->total_price = 0.0;
  return o;
}

// Add an item to an order
void add_item(order *o, char *item, int quantity) {
  int i;
  for (i = 0; i < MAX_ITEMS; i++) {
    if (o->items[i] == NULL) {
      o->items[i] = item;
      o->quantities[i] = quantity;
      o->prices[i] = menu_prices[i];
      o->total_price += quantity * menu_prices[i];
      break;
    }
  }
}

// Print an order
void print_order(order *o) {
  int i;
  printf("Order:\n");
  for (i = 0; i < MAX_ITEMS; i++) {
    if (o->items[i] != NULL) {
      printf("  %s x %d = $%.2f\n", o->items[i], o->quantities[i], o->prices[i] * o->quantities[i]);
    }
  }
  printf("Total: $%.2f\n", o->total_price);
}

// Free an order
void free_order(order *o) {
  int i;
  for (i = 0; i < MAX_ITEMS; i++) {
    if (o->items[i] != NULL) {
      free(o->items[i]);
    }
  }
  free(o);
}

// Main function
int main() {
  // Create a new order
  order *o = new_order();

  // Add some items to the order
  add_item(o, "Coffee", 2);
  add_item(o, "Muffin", 1);
  add_item(o, "Soda", 3);

  // Print the order
  print_order(o);

  // Free the order
  free_order(o);

  return 0;
}