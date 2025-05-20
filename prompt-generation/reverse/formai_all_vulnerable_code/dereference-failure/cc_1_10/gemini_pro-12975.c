//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct Item {
  char name[32];
  int price;
  int quantity;
};

struct Order {
  int table_number;
  struct Item *items;
  int num_items;
  int total_price;
};

struct Customer {
  int id;
  char name[32];
  int table_number;
  struct Order *order;
};

struct Cafe {
  struct Customer *customers;
  int num_customers;
  pthread_mutex_t lock;
};

void create_cafe(struct Cafe *cafe) {
  cafe->customers = NULL;
  cafe->num_customers = 0;
  pthread_mutex_init(&cafe->lock, NULL);
}

void destroy_cafe(struct Cafe *cafe) {
  for (int i = 0; i < cafe->num_customers; i++) {
    free(cafe->customers[i].order->items);
    free(cafe->customers[i].order);
  }
  free(cafe->customers);
  pthread_mutex_destroy(&cafe->lock);
}

void add_customer(struct Cafe *cafe, struct Customer *customer) {
  pthread_mutex_lock(&cafe->lock);
  cafe->customers = realloc(cafe->customers, (cafe->num_customers + 1) * sizeof(struct Customer));
  cafe->customers[cafe->num_customers] = *customer;
  cafe->num_customers++;
  pthread_mutex_unlock(&cafe->lock);
}

void remove_customer(struct Cafe *cafe, int id) {
  pthread_mutex_lock(&cafe->lock);
  for (int i = 0; i < cafe->num_customers; i++) {
    if (cafe->customers[i].id == id) {
      for (int j = i + 1; j < cafe->num_customers; j++) {
        cafe->customers[j - 1] = cafe->customers[j];
      }
      cafe->num_customers--;
      break;
    }
  }
  pthread_mutex_unlock(&cafe->lock);
}

struct Order *get_order(struct Cafe *cafe, int table_number) {
  pthread_mutex_lock(&cafe->lock);
  for (int i = 0; i < cafe->num_customers; i++) {
    if (cafe->customers[i].table_number == table_number) {
      pthread_mutex_unlock(&cafe->lock);
      return cafe->customers[i].order;
    }
  }
  pthread_mutex_unlock(&cafe->lock);
  return NULL;
}

void add_item_to_order(struct Cafe *cafe, int table_number, struct Item *item) {
  pthread_mutex_lock(&cafe->lock);
  struct Order *order = get_order(cafe, table_number);
  if (order == NULL) {
    order = malloc(sizeof(struct Order));
    order->table_number = table_number;
    order->items = NULL;
    order->num_items = 0;
    order->total_price = 0;
    add_customer(cafe, &(struct Customer){.id = cafe->num_customers, .name = "", .table_number = table_number, .order = order});
  }
  order->items = realloc(order->items, (order->num_items + 1) * sizeof(struct Item));
  order->items[order->num_items] = *item;
  order->num_items++;
  order->total_price += item->price * item->quantity;
  pthread_mutex_unlock(&cafe->lock);
}

void remove_item_from_order(struct Cafe *cafe, int table_number, int item_index) {
  pthread_mutex_lock(&cafe->lock);
  struct Order *order = get_order(cafe, table_number);
  if (order != NULL && item_index >= 0 && item_index < order->num_items) {
    for (int i = item_index + 1; i < order->num_items; i++) {
      order->items[i - 1] = order->items[i];
    }
    order->num_items--;
    order->total_price -= order->items[item_index].price * order->items[item_index].quantity;
  }
  pthread_mutex_unlock(&cafe->lock);
}

void print_order(struct Cafe *cafe, int table_number) {
  pthread_mutex_lock(&cafe->lock);
  struct Order *order = get_order(cafe, table_number);
  if (order != NULL) {
    printf("Table %d:\n", order->table_number);
    for (int i = 0; i < order->num_items; i++) {
      printf("  %s x %d = %d\n", order->items[i].name, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
    }
    printf("Total: %d\n", order->total_price);
  }
  pthread_mutex_unlock(&cafe->lock);
}

int main() {
  struct Cafe cafe;
  create_cafe(&cafe);

  // Add some customers and items to the cafe
  add_customer(&cafe, &(struct Customer){.id = 0, .name = "Alice", .table_number = 1, .order = NULL});
  add_item_to_order(&cafe, 1, &(struct Item){.name = "Coffee", .price = 5, .quantity = 2});
  add_item_to_order(&cafe, 1, &(struct Item){.name = "Tea", .price = 3, .quantity = 1});

  add_customer(&cafe, &(struct Customer){.id = 1, .name = "Bob", .table_number = 2, .order = NULL});
  add_item_to_order(&cafe, 2, &(struct Item){.name = "Juice", .price = 4, .quantity = 3});
  add_item_to_order(&cafe, 2, &(struct Item){.name = "Soda", .price = 2, .quantity = 2});

  // Print the orders for each table
  print_order(&cafe, 1);
  print_order(&cafe, 2);

  // Remove an item from an order
  remove_item_from_order(&cafe, 1, 1);

  // Print the updated order for table 1
  print_order(&cafe, 1);

  // Destroy the cafe
  destroy_cafe(&cafe);

  return 0;
}