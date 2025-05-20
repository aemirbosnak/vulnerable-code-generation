//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the menu items and their prices
struct MenuItem {
  char *name;
  double price;
};

struct MenuItem menuItems[] = {
  {"CyberBurger", 10.99},
  {"PhotonPizza", 8.99},
  {"QuantumSoda", 2.99},
  {"AntimatterFries", 4.99},
  {"SingularitySundae", 5.99}
};

// Define the order struct
struct Order {
  int numItems;
  struct MenuItem *items[MAX_ITEMS];
  double total;
};

// Function to create a new order
struct Order *createOrder() {
  struct Order *order = malloc(sizeof(struct Order));
  order->numItems = 0;
  order->total = 0.0;
  return order;
}

// Function to add an item to an order
void addItemToOrder(struct Order *order, struct MenuItem *item) {
  if (order->numItems < MAX_ITEMS) {
    order->items[order->numItems++] = item;
    order->total += item->price;
  }
}

// Function to print an order
void printOrder(struct Order *order) {
  printf("Order Summary:\n");
  for (int i = 0; i < order->numItems; i++) {
    printf("  %s: $%.2f\n", order->items[i]->name, order->items[i]->price);
  }
  printf("Total: $%.2f\n", order->total);
}

// Function to get the current time in a string
char *getTime() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char *timeString = malloc(100);
  strftime(timeString, 100, "%Y-%m-%d %H:%M:%S", tm);
  return timeString;
}

// Main function
int main() {
  // Create a new order
  struct Order *order = createOrder();

  // Add items to the order
  addItemToOrder(order, &menuItems[0]);
  addItemToOrder(order, &menuItems[2]);
  addItemToOrder(order, &menuItems[4]);

  // Print the order
  printOrder(order);

  // Get the current time
  char *timeString = getTime();

  // Print the receipt
  printf("\nReceipt:\n");
  printf("Time: %s\n", timeString);
  printOrder(order);
  printf("Thank you for your order! Please come again soon.\n");

  // Free the allocated memory
  free(order);
  free(timeString);
  return 0;
}