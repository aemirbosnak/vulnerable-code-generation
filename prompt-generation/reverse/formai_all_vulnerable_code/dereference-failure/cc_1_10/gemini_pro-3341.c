//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the order
#define MAX_ITEMS 100

// Define the maximum length of an item name
#define MAX_ITEM_NAME_LENGTH 50

// Define the maximum length of a customer name
#define MAX_CUSTOMER_NAME_LENGTH 50

// Define the tax rate
#define TAX_RATE 0.08

// Define the structure of an item
typedef struct item {
  char name[MAX_ITEM_NAME_LENGTH];
  float price;
  int quantity;
} item;

// Define the structure of an order
typedef struct order {
  char customer_name[MAX_CUSTOMER_NAME_LENGTH];
  item items[MAX_ITEMS];
  int num_items;
  float subtotal;
  float tax;
  float total;
} order;

// Create a new order
order *create_order(char *customer_name) {
  order *new_order = malloc(sizeof(order));
  strcpy(new_order->customer_name, customer_name);
  new_order->num_items = 0;
  new_order->subtotal = 0;
  new_order->tax = 0;
  new_order->total = 0;
  return new_order;
}

// Add an item to an order
void add_item_to_order(order *order, item *item) {
  order->items[order->num_items] = *item;
  order->num_items++;
  order->subtotal += item->price * item->quantity;
}

// Calculate the tax for an order
void calculate_tax(order *order) {
  order->tax = order->subtotal * TAX_RATE;
}

// Calculate the total for an order
void calculate_total(order *order) {
  order->total = order->subtotal + order->tax;
}

// Print an order
void print_order(order *order) {
  printf("Customer Name: %s\n", order->customer_name);
  printf("Item Name\tPrice\tQuantity\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("%s\t%.2f\t%d\n", order->items[i].name, order->items[i].price, order->items[i].quantity);
  }
  printf("Subtotal: %.2f\n", order->subtotal);
  printf("Tax: %.2f\n", order->tax);
  printf("Total: %.2f\n", order->total);
}

// Main function
int main() {
  // Create a new order
  order *order = create_order("John Doe");

  // Add items to the order
  item item1 = {"Coffee", 2.50, 2};
  add_item_to_order(order, &item1);
  item item2 = {"Muffin", 1.50, 1};
  add_item_to_order(order, &item2);

  // Calculate the tax and total for the order
  calculate_tax(order);
  calculate_total(order);

  // Print the order
  print_order(order);

  // Free the memory allocated for the order
  free(order);

  return 0;
}