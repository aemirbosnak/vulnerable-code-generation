//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the menu items and their prices
struct MenuItem {
  char *name;
  double price;
};

struct MenuItem menuItems[] = {
  {"Coffee", 2.50},
  {"Tea", 2.00},
  {"Cake", 3.00},
  {"Pastry", 2.50},
  {"Sandwich", 4.00}
};

// Define the table
struct Table {
  int tableNumber;
  int numCustomers;
  struct MenuItem *orderedItems[10];
  int numOrderedItems;
  double totalBill;
};

// Create a new table
struct Table *createTable(int tableNumber, int numCustomers) {
  struct Table *table = malloc(sizeof(struct Table));
  table->tableNumber = tableNumber;
  table->numCustomers = numCustomers;
  table->numOrderedItems = 0;
  table->totalBill = 0.0;

  return table;
}

// Add an item to the table's order
void addItemToTable(struct Table *table, struct MenuItem *item) {
  table->orderedItems[table->numOrderedItems++] = item;
  table->totalBill += item->price;
}

// Print the table's bill
void printBill(struct Table *table) {
  printf("Table %d\n", table->tableNumber);
  printf("Number of customers: %d\n", table->numCustomers);
  printf("Ordered items:\n");

  for (int i = 0; i < table->numOrderedItems; i++) {
    printf("  %s - $%.2f\n", table->orderedItems[i]->name, table->orderedItems[i]->price);
  }

  printf("Total bill: $%.2f\n", table->totalBill);
}

// The main function
int main() {
  // Create a new table
  struct Table *table = createTable(1, 2);

  // Add some items to the table's order
  addItemToTable(table, &menuItems[0]); // Coffee
  addItemToTable(table, &menuItems[2]); // Cake
  addItemToTable(table, &menuItems[4]); // Sandwich

  // Print the table's bill
  printBill(table);

  return 0;
}