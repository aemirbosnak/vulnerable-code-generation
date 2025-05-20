//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Cyberpunk
// Welcome to the Neon Nectary, choom!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Menu items and prices
typedef struct menuItem {
  char *name;
  float price;
} menuItem;

menuItem menu[] = {
  {"Bio-Espresso", 3.50},
  {"Cyber-Cappuccino", 4.00},
  {"Neural-Latte", 4.50},
  {"Glitch-Tea", 3.00},
  {"Digital-Donut", 2.00},
  {"Virtual-Croissant", 2.50}
};

// Order struct
typedef struct order {
  char *item;
  int quantity;
  float price;
} order;

// Create a new order
order *createOrder(char *item, int quantity, float price) {
  order *newOrder = malloc(sizeof(order));
  newOrder->item = item;
  newOrder->quantity = quantity;
  newOrder->price = price;
  return newOrder;
}

// Print the order
void printOrder(order *order) {
  printf("%s x%d: %f creds\n", order->item, order->quantity, order->price);
}

// Calculate the total price of the order
float calculateTotal(order **orders, int numOrders) {
  float total = 0;
  for (int i = 0; i < numOrders; i++) {
    total += orders[i]->price;
  }
  return total;
}

// Main function
int main() {
  // Welcome the customer
  printf("::: Neon Nectary :::\n");
  printf("Where reality gets a caffeine kick!\n\n");

  // Get the customer's order
  int numOrders;
  printf("How many items would you like to order, choom? ");
  scanf("%d", &numOrders);

  order **orders = malloc(sizeof(order *) * numOrders);
  for (int i = 0; i < numOrders; i++) {
    char item[50];
    int quantity;
    float price;

    printf("Item: ");
    scanf("%s", item);

    printf("Quantity: ");
    scanf("%d", &quantity);

    // Find the item in the menu
    for (int j = 0; j < sizeof(menu) / sizeof(menuItem); j++) {
      if (strcmp(item, menu[j].name) == 0) {
        price = menu[j].price * quantity;
        break;
      }
    }

    // Create the order
    orders[i] = createOrder(item, quantity, price);
  }

  // Print the order
  printf("\nYour order:\n");
  for (int i = 0; i < numOrders; i++) {
    printOrder(orders[i]);
  }

  // Calculate the total price
  float total = calculateTotal(orders, numOrders);

  // Print the total price
  printf("\nTotal: %f creds\n", total);

  // Thank the customer
  printf("\nEnjoy your caffeine fix, choom! Come again soon.\n");

  return 0;
}