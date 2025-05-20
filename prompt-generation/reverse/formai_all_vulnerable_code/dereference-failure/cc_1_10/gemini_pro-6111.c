//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int quantity;
  float price;
} Item;

typedef struct {
  Item *items;
  int num_items;
  float total;
} Order;

Order *create_order() {
  Order *order = malloc(sizeof(Order));
  order->items = malloc(0);
  order->num_items = 0;
  order->total = 0;
  return order;
}

void destroy_order(Order *order) {
  for (int i = 0; i < order->num_items; i++) {
    free(order->items[i].name);
  }
  free(order->items);
  free(order);
}

void add_item(Order *order, char *name, int quantity, float price) {
  order->items = realloc(order->items, (order->num_items + 1) * sizeof(Item));
  order->items[order->num_items].name = strdup(name);
  order->items[order->num_items].quantity = quantity;
  order->items[order->num_items].price = price;
  order->num_items++;
  order->total += quantity * price;
}

void print_order(Order *order) {
  printf("Order Summary:\n");
  printf("-----------------\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("%s x%d: $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
  }
  printf("Total: $%.2f\n", order->total);
}

int main() {
  Order *order = create_order();

  // Add some surrealist items to the order.
  add_item(order, "Cosmic Latte", 1, 3.50);
  add_item(order, "Dreamy Delusions", 2, 4.00);
  add_item(order, "Ethereal Elixir", 3, 5.00);

  // Print the order summary.
  print_order(order);

  // Destroy the order.
  destroy_order(order);

  return 0;
}