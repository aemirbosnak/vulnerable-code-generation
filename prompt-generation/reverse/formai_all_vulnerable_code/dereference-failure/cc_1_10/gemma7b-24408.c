//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_ORDERS 100

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

typedef struct Order {
  char customer_name[50];
  int order_number;
  struct Item* items;
  struct Order* next;
} Order;

Item* insert_item(Item* head, char* name, int quantity) {
  Item* new_item = malloc(sizeof(Item));
  strcpy(new_item->name, name);
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (head == NULL) {
    head = new_item;
  } else {
    head->next = new_item;
  }

  return head;
}

Order* insert_order(Order* head, char* customer_name, int order_number) {
  Order* new_order = malloc(sizeof(Order));
  strcpy(new_order->customer_name, customer_name);
  new_order->order_number = order_number;
  new_order->items = NULL;
  new_order->next = NULL;

  if (head == NULL) {
    head = new_order;
  } else {
    head->next = new_order;
  }

  return head;
}

void print_items(Item* head) {
  Item* current_item = head;
  while (current_item) {
    printf("%s - %d\n", current_item->name, current_item->quantity);
    current_item = current_item->next;
  }
}

void print_orders(Order* head) {
  Order* current_order = head;
  while (current_order) {
    printf("%s - Order # %d\n", current_order->customer_name, current_order->order_number);
    print_items(current_order->items);
    current_order = current_order->next;
  }
}

int main() {
  Item* items = NULL;
  Order* orders = NULL;

  // Insert some items
  insert_item(items, "Bread", 10);
  insert_item(items, "Cheese", 5);
  insert_item(items, "Wine", 2);

  // Insert some orders
  insert_order(orders, "John Doe", 1);
  insert_order(orders, "Jane Doe", 2);

  // Print the items
  print_items(items);

  // Print the orders
  print_orders(orders);

  return 0;
}