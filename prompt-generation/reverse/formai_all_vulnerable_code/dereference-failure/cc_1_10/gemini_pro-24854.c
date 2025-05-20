//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct item {
  char name[50];
  float price;
  int quantity;
} item;

// Define the structure of an order
typedef struct order {
  item items[MAX_ITEMS];
  int num_items;
  float total_price;
} order;

// Function to create a new item
item *create_item(char *name, float price, int quantity) {
  item *new_item = (item *)malloc(sizeof(item));
  strcpy(new_item->name, name);
  new_item->price = price;
  new_item->quantity = quantity;
  return new_item;
}

// Function to create a new order
order *create_order() {
  order *new_order = (order *)malloc(sizeof(order));
  new_order->num_items = 0;
  new_order->total_price = 0.0;
  return new_order;
}

// Function to add an item to an order
void add_item_to_order(order *order, item *item) {
  order->items[order->num_items] = *item;
  order->num_items++;
  order->total_price += item->price * item->quantity;
}

// Function to print an order
void print_order(order *order) {
  printf("Order Summary:\n");
  for (int i = 0; i < order->num_items; i++) {
    printf("%s x%d: $%.2f\n", order->items[i].name, order->items[i].quantity,
           order->items[i].price * order->items[i].quantity);
  }
  printf("Total Price: $%.2f\n", order->total_price);
}

// Main function
int main() {
  // Create a new cafe menu
  item *menu[] = {
      create_item("Coffee", 2.50, 0), create_item("Tea", 2.00, 0),
      create_item("Pastry", 3.00, 0), create_item("Sandwich", 5.00, 0)};

  // Create a new order
  order *order = create_order();

  // Welcome the customer and get their name
  char customer_name[50];
  printf("Welcome to the cafe! What is your name?\n");
  scanf("%s", customer_name);
  printf("Hello, %s!\n", customer_name);

  // Get the customer's order
  int choice;
  do {
    // Display the menu
    printf("Menu:\n");
    for (int i = 0; i < 4; i++) {
      printf("%d. %s ($%.2f)\n", i + 1, menu[i]->name, menu[i]->price);
    }
    printf("5. Quit\n");

    // Get the customer's choice
    printf("What would you like to order? (1-5)\n");
    scanf("%d", &choice);

    // Add the item to the order
    if (choice >= 1 && choice <= 4) {
      int quantity;
      printf("How many would you like?\n");
      scanf("%d", &quantity);
      add_item_to_order(order, create_item(menu[choice - 1]->name, menu[choice - 1]->price,
                                            quantity));
    }
  } while (choice != 5);

  // Print the order summary
  print_order(order);

  // Thank the customer and goodbye
  printf("Thank you for your order, %s! Have a great day!\n", customer_name);

  return 0;
}