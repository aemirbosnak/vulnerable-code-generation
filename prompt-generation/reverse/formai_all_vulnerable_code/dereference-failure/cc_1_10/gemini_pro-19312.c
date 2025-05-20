//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: retro
// A C Cafe Billing System in Retro Style
// Warning: This program contains retro programming techniques and should be treated as a historical artifact.
// It is not intended for actual use in modern systems.

#include <stdio.h>
#include <stdlib.h>

// Constants for menu items
#define COFFEE 1
#define TEA 2
#define CAKE 3
#define SANDWICH 4

// Constants for prices
#define COFFEE_PRICE 1.50
#define TEA_PRICE 1.25
#define CAKE_PRICE 2.00
#define SANDWICH_PRICE 3.50

// Constants for discounts
#define DISCOUNT_REGULAR 0.10
#define DISCOUNT_LOYALTY 0.15

// Data structures
typedef struct {
  int item;
  int quantity;
  float price;
} OrderItem;

typedef struct {
  OrderItem *items;
  int numItems;
  float total;
} Order;

// Function prototypes
void printMenu();
void takeOrder(Order *order);
void calculateTotal(Order *order);
void printReceipt(Order *order);

// Main function
int main() {
  // Print a welcome message
  printf("\nWelcome to the Retro Cafe!\n");

  // Create an order
  Order order;
  order.numItems = 0;
  order.items = NULL;

  // Take the order
  takeOrder(&order);

  // Calculate the total
  calculateTotal(&order);

  // Print the receipt
  printReceipt(&order);

  // Free the allocated memory
  free(order.items);

  // Exit the program
  return 0;
}

// Function to print the menu
void printMenu() {
  printf("\n**Menu**\n");
  printf("1. Coffee ........................ $1.50\n");
  printf("2. Tea ........................... $1.25\n");
  printf("3. Cake ......................... $2.00\n");
  printf("4. Sandwich ................... $3.50\n");
}

// Function to take the order
void takeOrder(Order *order) {
  int item;
  int quantity;

  // Get the number of items
  printf("\nHow many items would you like to order? ");
  scanf("%d", &order->numItems);

  // Allocate memory for the items
  order->items = malloc(sizeof(OrderItem) * order->numItems);

  // Get the items
  for (int i = 0; i < order->numItems; i++) {
    printf("\nEnter item %d: ", i + 1);
    scanf("%d", &item);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    order->items[i].item = item;
    order->items[i].quantity = quantity;

    // Calculate the price
    switch (item) {
      case COFFEE:
        order->items[i].price = COFFEE_PRICE;
        break;
      case TEA:
        order->items[i].price = TEA_PRICE;
        break;
      case CAKE:
        order->items[i].price = CAKE_PRICE;
        break;
      case SANDWICH:
        order->items[i].price = SANDWICH_PRICE;
        break;
      default:
        printf("Invalid item\n");
        break;
    }
  }
}

// Function to calculate the total
void calculateTotal(Order *order) {
  float total = 0;

  // Calculate the total price
  for (int i = 0; i < order->numItems; i++) {
    total += order->items[i].price * order->items[i].quantity;
  }

  // Apply the discount
  if (order->numItems >= 3) {
    total *= (1 - DISCOUNT_REGULAR);
  }
  if (total >= 10) {
    total *= (1 - DISCOUNT_LOYALTY);
  }

  // Set the total
  order->total = total;
}

// Function to print the receipt
void printReceipt(Order *order) {
  printf("\n**Receipt**\n");

  // Print the items
  for (int i = 0; i < order->numItems; i++) {
    printf("%d x ", order->items[i].quantity);

    switch (order->items[i].item) {
      case COFFEE:
        printf("Coffee");
        break;
      case TEA:
        printf("Tea");
        break;
      case CAKE:
        printf("Cake");
        break;
      case SANDWICH:
        printf("Sandwich");
        break;
    }

    printf(" ................. $%.2f\n", order->items[i].price * order->items[i].quantity);
  }

  // Print the total
  printf("\nTotal ............................. $%.2f\n", order->total);

  // Print a thank you message
  printf("\nThank you for your patronage!\n");
}