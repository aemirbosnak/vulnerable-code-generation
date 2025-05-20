//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
  char *name;
  float price;
};

struct MenuItem menu[] = {
  {"Coffee", 2.50},
  {"Tea", 2.00},
  {"Soda", 1.50},
  {"Water", 1.00},
  {"Muffin", 2.00},
  {"Cookie", 1.50}
};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of the order
struct Order {
  struct MenuItem *item;
  int quantity;
};

// Define the structure of the bill
struct Bill {
  struct Order orders[MAX_ITEMS];
  int num_items;
  float total_price;
};

// Create a new order
struct Order *create_order(struct MenuItem *item, int quantity) {
  struct Order *order = malloc(sizeof(struct Order));
  order->item = item;
  order->quantity = quantity;
  return order;
}

// Add an order to the bill
void add_order(struct Bill *bill, struct Order *order) {
  bill->orders[bill->num_items++] = *order;
}

// Calculate the total price of the bill
float calculate_total_price(struct Bill *bill) {
  float total_price = 0.0;
  for (int i = 0; i < bill->num_items; i++) {
    total_price += bill->orders[i].item->price * bill->orders[i].quantity;
  }
  return total_price;
}

// Print the bill
void print_bill(struct Bill *bill) {
  printf("Cafe Billing System\n");
  printf("===================\n");
  for (int i = 0; i < bill->num_items; i++) {
    printf("%-15s %3d x %5.2f = %5.2f\n", bill->orders[i].item->name, bill->orders[i].quantity, bill->orders[i].item->price, bill->orders[i].item->price * bill->orders[i].quantity);
  }
  printf("-------------------\n");
  printf("Total: %5.2f\n", bill->total_price);
}

// Main function
int main() {
  // Create a new bill
  struct Bill *bill = malloc(sizeof(struct Bill));
  bill->num_items = 0;
  bill->total_price = 0.0;

  // Add some orders to the bill
  add_order(bill, create_order(&menu[0], 2));
  add_order(bill, create_order(&menu[1], 1));
  add_order(bill, create_order(&menu[2], 3));

  // Calculate the total price of the bill
  bill->total_price = calculate_total_price(bill);

  // Print the bill
  print_bill(bill);

  return 0;
}