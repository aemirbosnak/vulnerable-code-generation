//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the maximum length of an item name
#define MAX_ITEM_NAME_LENGTH 50

// Structure to store an item
typedef struct {
  char name[MAX_ITEM_NAME_LENGTH];
  int quantity;
  float price;
} Item;

// Structure to store an order
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
  float total_price;
} Order;

// Function to create a new order
Order* create_order() {
  Order* order = malloc(sizeof(Order));
  order->num_items = 0;
  order->total_price = 0.0;
  return order;
}

// Function to add an item to an order
void add_item_to_order(Order* order, Item item) {
  if (order->num_items < MAX_ITEMS) {
    order->items[order->num_items] = item;
    order->num_items++;
    order->total_price += item.price * item.quantity;
  } else {
    printf("Error: Cannot add more items to order.\n");
  }
}

// Function to remove an item from an order
void remove_item_from_order(Order* order, int index) {
  if (index >= 0 && index < order->num_items) {
    for (int i = index; i < order->num_items - 1; i++) {
      order->items[i] = order->items[i + 1];
    }
    order->num_items--;
    order->total_price -= order->items[index].price * order->items[index].quantity;
  } else {
    printf("Error: Invalid index.\n");
  }
}

// Function to print an order
void print_order(Order* order) {
  printf("Order:\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("  %s x%d @ $%.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price);
  }
  printf("Total: $%.2f\n", order->total_price);
}

// Main function
int main() {
  // Create a new order
  Order* order = create_order();

  // Add some items to the order
  Item item1 = {"Coffee", 2, 2.50};
  add_item_to_order(order, item1);
  Item item2 = {"Tea", 1, 1.50};
  add_item_to_order(order, item2);
  Item item3 = {"Pastry", 1, 3.00};
  add_item_to_order(order, item3);

  // Print the order
  print_order(order);

  // Remove an item from the order
  remove_item_from_order(order, 1);

  // Print the order again
  print_order(order);

  // Free the memory allocated for the order
  free(order);

  return 0;
}