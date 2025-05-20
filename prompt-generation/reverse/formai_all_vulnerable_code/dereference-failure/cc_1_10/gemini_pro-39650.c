//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures for items and warehouses
typedef struct item {
  int id;
  char *name;
  int quantity;
  float price;
} Item;

typedef struct warehouse {
  int id;
  char *name;
  int capacity;
  Item **items;
  int num_items;
} Warehouse;

// Function to create a new item
Item *create_item(int id, char *name, int quantity, float price) {
  Item *item = malloc(sizeof(Item));
  item->id = id;
  item->name = strdup(name);
  item->quantity = quantity;
  item->price = price;
  return item;
}

// Function to create a new warehouse
Warehouse *create_warehouse(int id, char *name, int capacity) {
  Warehouse *warehouse = malloc(sizeof(Warehouse));
  warehouse->id = id;
  warehouse->name = strdup(name);
  warehouse->capacity = capacity;
  warehouse->items = malloc(sizeof(Item *) * capacity);
  warehouse->num_items = 0;
  return warehouse;
}

// Function to add an item to a warehouse
void add_item_to_warehouse(Warehouse *warehouse, Item *item) {
  if (warehouse->num_items < warehouse->capacity) {
    warehouse->items[warehouse->num_items] = item;
    warehouse->num_items++;
  } else {
    printf("Warehouse is full!\n");
  }
}

// Function to print the details of an item
void print_item(Item *item) {
  printf("Item ID: %d\n", item->id);
  printf("Item Name: %s\n", item->name);
  printf("Item Quantity: %d\n", item->quantity);
  printf("Item Price: %.2f\n", item->price);
}

// Function to print the details of a warehouse
void print_warehouse(Warehouse *warehouse) {
  printf("Warehouse ID: %d\n", warehouse->id);
  printf("Warehouse Name: %s\n", warehouse->name);
  printf("Warehouse Capacity: %d\n", warehouse->capacity);
  printf("Items in Warehouse:\n");
  for (int i = 0; i < warehouse->num_items; i++) {
    print_item(warehouse->items[i]);
  }
}

// Main function
int main() {
  // Create a new warehouse
  Warehouse *warehouse = create_warehouse(1, "Main Warehouse", 10);

  // Create some items
  Item *item1 = create_item(1, "Apple", 10, 1.0);
  Item *item2 = create_item(2, "Banana", 15, 1.5);
  Item *item3 = create_item(3, "Orange", 20, 2.0);

  // Add the items to the warehouse
  add_item_to_warehouse(warehouse, item1);
  add_item_to_warehouse(warehouse, item2);
  add_item_to_warehouse(warehouse, item3);

  // Print the details of the warehouse
  print_warehouse(warehouse);

  return 0;
}