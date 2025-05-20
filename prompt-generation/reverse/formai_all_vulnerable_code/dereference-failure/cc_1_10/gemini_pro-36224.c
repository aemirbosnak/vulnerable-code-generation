//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure to store item details
typedef struct Item {
  int id;
  char name[50];
  int quantity;
  float price;
} Item;

// Function to add a new item to the warehouse
void add_item(Item *items, int *num_items, Item new_item) {
  // Increase the size of the items array
  items = (Item *)realloc(items, (*num_items + 1) * sizeof(Item));

  // Add the new item to the array
  items[*num_items] = new_item;

  // Increment the number of items
  (*num_items)++;
}

// Function to search for an item by ID
Item *search_item_by_id(Item *items, int num_items, int id) {
  for (int i = 0; i < num_items; i++) {
    if (items[i].id == id) {
      return &items[i];
    }
  }

  return NULL;
}

// Function to print the details of all items in the warehouse
void print_items(Item *items, int num_items) {
  printf("Warehouse Inventory:\n");
  for (int i = 0; i < num_items; i++) {
    printf("Item ID: %d\n", items[i].id);
    printf("Item Name: %s\n", items[i].name);
    printf("Item Quantity: %d\n", items[i].quantity);
    printf("Item Price: %.2f\n\n", items[i].price);
  }
}

// Main function to simulate the warehouse management system
int main() {
  // Initialize the warehouse with some sample items
  Item items[] = {
    {1, "Apple", 10, 1.50},
    {2, "Banana", 20, 2.00},
    {3, "Orange", 30, 2.50},
  };

  int num_items = sizeof(items) / sizeof(items[0]);

  // Add a new item to the warehouse
  Item new_item = {4, "Grape", 15, 3.00};
  add_item(items, &num_items, new_item);

  // Search for an item by ID
  Item *found_item = search_item_by_id(items, num_items, 3);
  if (found_item) {
    printf("Item found:\n");
    printf("Item ID: %d\n", found_item->id);
    printf("Item Name: %s\n", found_item->name);
    printf("Item Quantity: %d\n", found_item->quantity);
    printf("Item Price: %.2f\n\n", found_item->price);
  } else {
    printf("Item not found.\n");
  }

  // Print the details of all items in the warehouse
  print_items(items, num_items);

  return 0;
}