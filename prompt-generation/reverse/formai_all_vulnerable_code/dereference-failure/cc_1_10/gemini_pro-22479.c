//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct item {
  char name[50];
  int price;
  int quantity;
};

struct order {
  int num_items;
  struct item *items;
  int total_price;
};

struct cafe {
  char name[50];
  struct order *orders;
  int num_orders;
  int total_revenue;
};

void add_item_to_order(struct order *order, struct item *item) {
  order->items = realloc(order->items, sizeof(struct item) * (order->num_items + 1));
  order->items[order->num_items] = *item;
  order->num_items++;
  order->total_price += item->price * item->quantity;
}

void add_order_to_cafe(struct cafe *cafe, struct order *order) {
  cafe->orders = realloc(cafe->orders, sizeof(struct order) * (cafe->num_orders + 1));
  cafe->orders[cafe->num_orders] = *order;
  cafe->num_orders++;
  cafe->total_revenue += order->total_price;
}

void print_order(struct order *order) {
  printf("Order: %d\n", order->num_items);
  for (int i = 0; i < order->num_items; i++) {
    printf("\t%s x %d = %d\n", order->items[i].name, order->items[i].quantity,
           order->items[i].price * order->items[i].quantity);
  }
  printf("\tTotal: %d\n", order->total_price);
}

void print_cafe(struct cafe *cafe) {
  printf("Cafe: %s\n", cafe->name);
  for (int i = 0; i < cafe->num_orders; i++) {
    print_order(&cafe->orders[i]);
  }
  printf("Total Revenue: %d\n", cafe->total_revenue);
}

int main() {
  struct cafe cafe = {"The Coffee Shop", NULL, 0, 0};

  struct item item1 = {"Latte", 3, 2};
  struct item item2 = {"Cappuccino", 4, 1};
  struct item item3 = {"Muffin", 2, 3};

  struct order order1 = {0, NULL, 0};
  add_item_to_order(&order1, &item1);
  add_item_to_order(&order1, &item2);

  struct order order2 = {0, NULL, 0};
  add_item_to_order(&order2, &item3);
  add_item_to_order(&order2, &item1);

  add_order_to_cafe(&cafe, &order1);
  add_order_to_cafe(&cafe, &order2);

  print_cafe(&cafe);

  return 0;
}