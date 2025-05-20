//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items and prices
char menuItems[][20] = {"Espresso", "Cappuccino", "Latte", "Mocha", "Americano"};
float menuPrices[] = {2.50, 3.00, 3.50, 4.00, 2.75};

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order item
typedef struct {
  char name[20];
  float price;
  int quantity;
} OrderItem;

// Create a new order
OrderItem* createOrder() {
  OrderItem* order = (OrderItem*)malloc(sizeof(OrderItem));
  order->quantity = 0;
  return order;
}

// Add an item to an order
void addItemToOrder(OrderItem* order, char* itemName, float itemPrice) {
  strcpy(order->name, itemName);
  order->price = itemPrice;
  order->quantity++;
}

// Calculate the total price of an order
float calculateTotalPrice(OrderItem* order) {
  return order->price * order->quantity;
}

// Print the order
void printOrder(OrderItem* order) {
  printf("%s x%d = $%.2f\n", order->name, order->quantity, calculateTotalPrice(order));
}

// Get the user's input
char* getUserInput(char* prompt) {
  printf("%s", prompt);
  char* input = (char*)malloc(100);
  scanf("%s", input);
  return input;
}

// Get the user's order
OrderItem* getUserOrder() {
  OrderItem* order = createOrder();

  char* itemName = getUserInput("Enter the name of the item you want to order: ");

  // Find the index of the item in the menu
  int itemIndex = -1;
  for (int i = 0; i < 5; i++) {
    if (strcmp(itemName, menuItems[i]) == 0) {
      itemIndex = i;
      break;
    }
  }

  // If the item was not found, print an error message
  if (itemIndex == -1) {
    printf("Invalid item. Please try again.\n");
    return NULL;
  }

  // Get the quantity of the item
  int quantity = atoi(getUserInput("Enter the quantity of the item you want to order: "));

  // Add the item to the order
  addItemToOrder(order, menuItems[itemIndex], menuPrices[itemIndex]);

  // Return the order
  return order;
}

// Print the menu
void printMenu() {
  printf("Menu:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s - $%.2f\n", menuItems[i], menuPrices[i]);
  }
}

// Main function
int main() {
  // Print a welcome message
  printf("Welcome to the Cafe Billing System!\n");

  // Print the menu
  printMenu();

  // Get the user's order
  OrderItem* order = getUserOrder();

  // If the user entered an invalid item, print an error message and exit the program
  if (order == NULL) {
    printf("Invalid item. Please try again.\n");
    return 1;
  }

  // Calculate the total price of the order
  float totalPrice = calculateTotalPrice(order);

  // Print the order
  printf("Your order:\n");
  printOrder(order);

  // Print the total price
  printf("Total price: $%.2f\n", totalPrice);

  // Print a thank you message
  printf("Thank you for your order! Come again soon!\n");

  return 0;
}