//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and their prices
char *menu_items[] = {"Coffee", "Tea", "Espresso", "Latte", "Cappuccino", "Mocha", "Hot Chocolate"};
float menu_prices[] = {2.50, 1.50, 3.00, 3.50, 4.00, 4.50, 3.00};

// Define the order structure
typedef struct order {
  char *item;
  int quantity;
  float price;
} order_t;

// Define the cafe structure
typedef struct cafe {
  order_t *orders;
  int num_orders;
  float total;
} cafe_t;

// Create a new cafe
cafe_t *create_cafe() {
  cafe_t *cafe = malloc(sizeof(cafe_t));
  cafe->orders = NULL;
  cafe->num_orders = 0;
  cafe->total = 0.0;
  return cafe;
}

// Add an order to the cafe
void add_order(cafe_t *cafe, char *item, int quantity) {
  // Find the index of the item in the menu
  int index = -1;
  for (int i = 0; i < sizeof(menu_items) / sizeof(char *); i++) {
    if (strcmp(item, menu_items[i]) == 0) {
      index = i;
      break;
    }
  }

  // If the item is not found, return
  if (index == -1) {
    printf("Item not found.\n");
    return;
  }

  // Create a new order
  order_t *order = malloc(sizeof(order_t));
  order->item = item;
  order->quantity = quantity;
  order->price = menu_prices[index] * quantity;

  // Add the order to the cafe
  cafe->orders = realloc(cafe->orders, (cafe->num_orders + 1) * sizeof(order_t));
  cafe->orders[cafe->num_orders] = *order;
  cafe->num_orders++;

  // Update the cafe's total
  cafe->total += order->price;
}

// Print the cafe's orders
void print_orders(cafe_t *cafe) {
  for (int i = 0; i < cafe->num_orders; i++) {
    order_t order = cafe->orders[i];
    printf("%s x%d: $%.2f\n", order.item, order.quantity, order.price);
  }
}

// Print the cafe's total
void print_total(cafe_t *cafe) {
  printf("Total: $%.2f\n", cafe->total);
}

// Main function
int main() {
  // Create a new cafe
  cafe_t *cafe = create_cafe();

  // Add some orders to the cafe
  add_order(cafe, "Coffee", 2);
  add_order(cafe, "Tea", 1);
  add_order(cafe, "Espresso", 3);

  // Print the cafe's orders
  print_orders(cafe);

  // Print the cafe's total
  print_total(cafe);

  // Free the cafe's memory
  for (int i = 0; i < cafe->num_orders; i++) {
    free(cafe->orders[i].item);
  }
  free(cafe->orders);
  free(cafe);

  return 0;
}