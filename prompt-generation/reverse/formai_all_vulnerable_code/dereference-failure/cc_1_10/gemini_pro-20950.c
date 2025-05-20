//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  double price;
  int quantity;
} Item;

typedef struct {
  Item *items;
  int num_items;
  double total;
} Order;

void add_item(Order *order, Item *item) {
  order->items = realloc(order->items, (order->num_items + 1) * sizeof(Item));
  order->items[order->num_items] = *item;
  order->num_items++;
  order->total += item->price * item->quantity;
}

void print_order(Order *order) {
  printf("Order:\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("  %s: $%.2f x %d = $%.2f\n", order->items[i].name, order->items[i].price, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
  }
  printf("Total: $%.2f\n", order->total);
}

int main() {
  Order order;
  order.items = NULL;
  order.num_items = 0;
  order.total = 0.0;

  Item coffee;
  coffee.name = "Coffee";
  coffee.price = 2.00;
  coffee.quantity = 2;

  Item tea;
  tea.name = "Tea";
  tea.price = 1.50;
  tea.quantity = 1;

  Item cake;
  cake.name = "Cake";
  cake.price = 3.00;
  cake.quantity = 1;

  add_item(&order, &coffee);
  add_item(&order, &tea);
  add_item(&order, &cake);

  print_order(&order);

  return 0;
}