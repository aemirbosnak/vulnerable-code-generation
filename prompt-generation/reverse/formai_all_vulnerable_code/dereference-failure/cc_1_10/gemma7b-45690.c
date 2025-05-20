//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
  char name[20];
  int quantity;
  float price;
} Item;

Item items[MAX_ITEMS] = {
  {"Coffee", 0, 50.0},
  {"Tea", 1, 40.0},
  {"Juice", 2, 30.0},
  {"Smoothie", 3, 20.0},
  {"Water", 4, 10.0}
};

int main() {
  int numItems = 5;
  int i, totalItems = 0, totalAmount = 0;
  char choice;

  printf("Welcome to the C Cafe Billing System!\n");

  // Calculate total number of items
  for (i = 0; i < numItems; i++) {
    totalItems += items[i].quantity;
  }

  // Display total number of items
  printf("Total number of items: %d\n", totalItems);

  // Loop to get item selection and quantity
  printf("Enter item name: ");
  scanf("%s", &choice);

  // Calculate item cost and quantity
  for (i = 0; i < numItems; i++) {
    if (strcmp(choice, items[i].name) == 0) {
      int itemQuantity = items[i].quantity;
      float itemPrice = items[i].price;

      // Calculate item cost
      float itemTotalCost = itemQuantity * itemPrice;

      // Add item cost to total amount
      totalAmount += itemTotalCost;
    }
  }

  // Display total amount
  printf("Total amount: $%.2f\n", totalAmount);

  // Calculate tax and total payment
  float tax = 0.1 * totalAmount;
  float totalPayment = totalAmount + tax;

  // Display tax and total payment
  printf("Tax: $%.2f\n", tax);
  printf("Total payment: $%.2f\n", totalPayment);

  return 0;
}