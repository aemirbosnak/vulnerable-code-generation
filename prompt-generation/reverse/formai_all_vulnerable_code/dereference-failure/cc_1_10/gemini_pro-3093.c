//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
typedef struct MenuItem {
  char *name;
  float price;
} MenuItem;

MenuItem menuItems[] = {
  {"Latte", 3.50},
  {"Cappuccino", 4.00},
  {"Espresso", 2.50},
  {"Americano", 3.00},
  {"Mocha", 4.50},
  {"Caramel Macchiato", 5.00},
  {"Tea", 2.00},
  {"Hot Chocolate", 3.00},
  {"Pastry", 2.50}
};

int numMenuItems = sizeof(menuItems) / sizeof(MenuItem);

// Define the order structure
typedef struct Order {
  int quantity;
  MenuItem *item;
} Order;

// Define the customer structure
typedef struct Customer {
  char *name;
  Order *orders;
  int numOrders;
} Customer;

// Define the global variables
Customer *customers[100];
int numCustomers = 0;

// Function to add a new customer
void addCustomer(char *name) {
  customers[numCustomers] = malloc(sizeof(Customer));
  customers[numCustomers]->name = name;
  customers[numCustomers]->numOrders = 0;
  customers[numCustomers]->orders = NULL;
  numCustomers++;
}

// Function to add an order to a customer
void addOrder(Customer *customer, MenuItem *item, int quantity) {
  customer->orders = realloc(customer->orders, sizeof(Order) * (customer->numOrders + 1));
  customer->orders[customer->numOrders].item = item;
  customer->orders[customer->numOrders].quantity = quantity;
  customer->numOrders++;
}

// Function to calculate the total price of an order
float calculateTotalPrice(Customer *customer) {
  float totalPrice = 0;
  for (int i = 0; i < customer->numOrders; i++) {
    totalPrice += customer->orders[i].item->price * customer->orders[i].quantity;
  }
  return totalPrice;
}

// Function to print the bill
void printBill(Customer *customer) {
  printf("Customer: %s\n", customer->name);
  printf("Orders:\n");
  for (int i = 0; i < customer->numOrders; i++) {
    printf("  - %d %s: $%.2f\n", customer->orders[i].quantity, customer->orders[i].item->name, customer->orders[i].item->price * customer->orders[i].quantity);
  }
  printf("Total price: $%.2f\n", calculateTotalPrice(customer));
}

// Main function
int main() {
  // Add some customers
  addCustomer("John Doe");
  addCustomer("Jane Doe");

  // Add some orders to the customers
  addOrder(customers[0], &menuItems[0], 2);
  addOrder(customers[0], &menuItems[2], 1);
  addOrder(customers[1], &menuItems[3], 3);
  addOrder(customers[1], &menuItems[7], 2);

  // Print the bills
  for (int i = 0; i < numCustomers; i++) {
    printBill(customers[i]);
  }

  return 0;
}