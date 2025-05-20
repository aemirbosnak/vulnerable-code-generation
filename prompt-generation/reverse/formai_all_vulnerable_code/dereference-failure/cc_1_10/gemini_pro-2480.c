//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the inventory
#define MAX_ITEMS 100

// Define the structure of an item in the inventory
typedef struct {
  char name[50];
  int quantity;
  float price;
} Item;

// Define the structure of the inventory
typedef struct {
  Item items[MAX_ITEMS];
  int num_items;
} Inventory;

// Create a new inventory
Inventory* create_inventory() {
  Inventory* inventory = (Inventory*)malloc(sizeof(Inventory));
  inventory->num_items = 0;
  return inventory;
}

// Add an item to the inventory
void add_item(Inventory* inventory, Item item) {
  // Check if the inventory is full
  if (inventory->num_items == MAX_ITEMS) {
    printf("Error: Inventory is full.\n");
    return;
  }

  // Add the item to the inventory
  inventory->items[inventory->num_items++] = item;
}

// Remove an item from the inventory
void remove_item(Inventory* inventory, char* name) {
  // Find the item in the inventory
  int index = -1;
  for (int i = 0; i < inventory->num_items; i++) {
    if (strcmp(inventory->items[i].name, name) == 0) {
      index = i;
      break;
    }
  }

  // Check if the item was found
  if (index == -1) {
    printf("Error: Item not found.\n");
    return;
  }

  // Remove the item from the inventory
  for (int i = index; i < inventory->num_items - 1; i++) {
    inventory->items[i] = inventory->items[i + 1];
  }
  inventory->num_items--;
}

// Print the inventory
void print_inventory(Inventory* inventory) {
  printf("Inventory:\n");
  for (int i = 0; i < inventory->num_items; i++) {
    printf("  %s %d %.2f\n", inventory->items[i].name, inventory->items[i].quantity, inventory->items[i].price);
  }
}

// Get the total value of the inventory
float get_total_value(Inventory* inventory) {
  float total_value = 0;
  for (int i = 0; i < inventory->num_items; i++) {
    total_value += inventory->items[i].quantity * inventory->items[i].price;
  }
  return total_value;
}

// Main function
int main() {
  // Create a new inventory
  Inventory* inventory = create_inventory();

  // Add some items to the inventory
  Item item1 = {"Aspirin", 100, 0.50};
  add_item(inventory, item1);
  Item item2 = {"Ibuprofen", 50, 0.75};
  add_item(inventory, item2);
  Item item3 = {"Acetaminophen", 25, 1.00};
  add_item(inventory, item3);

  // Print the inventory
  print_inventory(inventory);

  // Get the total value of the inventory
  float total_value = get_total_value(inventory);
  printf("Total value: %.2f\n", total_value);

  // Remove an item from the inventory
  remove_item(inventory, "Ibuprofen");

  // Print the inventory again
  print_inventory(inventory);

  // Free the memory allocated for the inventory
  free(inventory);

  return 0;
}