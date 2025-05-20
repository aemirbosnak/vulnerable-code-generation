//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
// Linus Torvalds style cafe billing system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the menu items
#define COFFEE 1
#define TEA 2
#define SANDWICH 3
#define COOKIE 4

// Define the prices of the menu items
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.50
#define SANDWICH_PRICE 4.00
#define COOKIE_PRICE 1.00

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an order
typedef struct {
  int item_code;
  int quantity;
} order_item;

// Define the structure of a bill
typedef struct {
  order_item items[MAX_ITEMS];
  int num_items;
  double total_price;
} bill;

// Function to create a new bill
bill *create_bill() {
  bill *b = malloc(sizeof(bill));
  b->num_items = 0;
  b->total_price = 0.0;
  return b;
}

// Function to add an item to a bill
void add_item_to_bill(bill *b, int item_code, int quantity) {
  b->items[b->num_items].item_code = item_code;
  b->items[b->num_items].quantity = quantity;
  b->num_items++;

  // Update the total price of the bill
  switch (item_code) {
    case COFFEE:
      b->total_price += COFFEE_PRICE * quantity;
      break;
    case TEA:
      b->total_price += TEA_PRICE * quantity;
      break;
    case SANDWICH:
      b->total_price += SANDWICH_PRICE * quantity;
      break;
    case COOKIE:
      b->total_price += COOKIE_PRICE * quantity;
      break;
  }
}

// Function to print a bill
void print_bill(bill *b) {
  printf("Cafe Bill\n");
  printf("=====================\n");
  for (int i = 0; i < b->num_items; i++) {
    switch (b->items[i].item_code) {
      case COFFEE:
        printf("Coffee x%d\n", b->items[i].quantity);
        break;
      case TEA:
        printf("Tea x%d\n", b->items[i].quantity);
        break;
      case SANDWICH:
        printf("Sandwich x%d\n", b->items[i].quantity);
        break;
      case COOKIE:
        printf("Cookie x%d\n", b->items[i].quantity);
        break;
    }
  }
  printf("=====================\n");
  printf("Total: $%.2f\n", b->total_price);
}

// Function to free the memory allocated for a bill
void free_bill(bill *b) {
  free(b);
}

// Main function
int main() {
  // Create a new bill
  bill *b = create_bill();

  // Add items to the bill
  add_item_to_bill(b, COFFEE, 2);
  add_item_to_bill(b, TEA, 1);
  add_item_to_bill(b, SANDWICH, 1);
  add_item_to_bill(b, COOKIE, 2);

  // Print the bill
  print_bill(b);

  // Free the memory allocated for the bill
  free_bill(b);

  return 0;
}