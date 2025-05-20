//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in an order
#define MAX_ITEMS 10

// Define the structure of an item in an order
typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

// Define the structure of an order
typedef struct {
  int order_id;
  char customer_name[50];
  Item items[MAX_ITEMS];
  int num_items;
  float total_price;
} Order;

// Define the menu of items
Item menu[] = {
  {"Coffee", 1, 2.50},
  {"Tea", 1, 2.00},
  {"Cake", 1, 3.00},
  {"Muffin", 1, 2.00},
  {"Cookie", 1, 1.00}
};

// Define the number of items in the menu
int num_menu_items = sizeof(menu) / sizeof(Item);

// Function to create a new order
Order* create_order(int order_id, char* customer_name) {
  Order* order = malloc(sizeof(Order));
  order->order_id = order_id;
  strcpy(order->customer_name, customer_name);
  order->num_items = 0;
  order->total_price = 0.0;
  return order;
}

// Function to add an item to an order
void add_item_to_order(Order* order, Item* item) {
  if (order->num_items < MAX_ITEMS) {
    order->items[order->num_items++] = *item;
    order->total_price += item->price * item->quantity;
  } else {
    printf("Error: Order is full.\n");
  }
}

// Function to print an order
void print_order(Order* order) {
  printf("Order ID: %d\n", order->order_id);
  printf("Customer Name: %s\n", order->customer_name);
  printf("Items:\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("  - %s x %d = %.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
  }
  printf("Total Price: %.2f\n", order->total_price);
}

// Function to process a customer's order
void process_order(Order* order) {
  // Get the customer's name
  printf("Enter your name: ");
  scanf("%s", order->customer_name);

  // Get the items the customer wants to order
  int item_number;
  int quantity;
  do {
    // Get the item number
    printf("Enter the item number (0 to quit): ");
    scanf("%d", &item_number);

    // If the item number is valid, get the quantity
    if (item_number > 0 && item_number <= num_menu_items) {
      printf("Enter the quantity: ");
      scanf("%d", &quantity);

      // Add the item to the order
      add_item_to_order(order, &menu[item_number - 1]);
    }
  } while (item_number != 0);

  // Print the order
  print_order(order);
}

// Main function
int main() {
  // Create a new order
  Order* order = create_order(1, "John Doe");

  // Process the order
  process_order(order);

  // Free the memory allocated for the order
  free(order);

  return 0;
}