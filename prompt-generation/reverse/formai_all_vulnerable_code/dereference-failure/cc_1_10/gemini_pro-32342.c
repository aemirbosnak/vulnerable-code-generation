//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inventory struct
struct inventory {
  char *name;
  int quantity;
  float price;
};

// Warehouse struct
struct warehouse {
  char *name;
  struct inventory *inventory;
  int num_items;
};

// Create a new warehouse
struct warehouse *create_warehouse(char *name) {
  struct warehouse *warehouse = malloc(sizeof(struct warehouse));
  warehouse->name = strdup(name);
  warehouse->inventory = NULL;
  warehouse->num_items = 0;
  return warehouse;
}

// Add an item to a warehouse
void add_item(struct warehouse *warehouse, char *name, int quantity, float price) {
  // Check if the item already exists
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->inventory[i].name, name) == 0) {
      // If the item already exists, just update the quantity
      warehouse->inventory[i].quantity += quantity;
      return;
    }
  }

  // If the item does not exist, add it to the inventory
  warehouse->inventory = realloc(warehouse->inventory, (warehouse->num_items + 1) * sizeof(struct inventory));
  warehouse->inventory[warehouse->num_items].name = strdup(name);
  warehouse->inventory[warehouse->num_items].quantity = quantity;
  warehouse->inventory[warehouse->num_items].price = price;
  warehouse->num_items++;
}

// Remove an item from a warehouse
void remove_item(struct warehouse *warehouse, char *name) {
  // Check if the item exists
  for (int i = 0; i < warehouse->num_items; i++) {
    if (strcmp(warehouse->inventory[i].name, name) == 0) {
      // If the item exists, remove it from the inventory
      free(warehouse->inventory[i].name);
      warehouse->inventory[i] = warehouse->inventory[warehouse->num_items - 1];
      warehouse->num_items--;
      return;
    }
  }
}

// Get the total value of a warehouse's inventory
float get_total_value(struct warehouse *warehouse) {
  float total_value = 0;
  for (int i = 0; i < warehouse->num_items; i++) {
    total_value += warehouse->inventory[i].quantity * warehouse->inventory[i].price;
  }
  return total_value;
}

// Print the inventory of a warehouse
void print_inventory(struct warehouse *warehouse) {
  printf("Inventory for warehouse %s:\n", warehouse->name);
  for (int i = 0; i < warehouse->num_items; i++) {
    printf("  %s: %d units, %.2f gold\n", warehouse->inventory[i].name, warehouse->inventory[i].quantity, warehouse->inventory[i].price);
  }
  printf("Total value: %.2f gold\n", get_total_value(warehouse));
}

// Free the memory allocated for a warehouse
void destroy_warehouse(struct warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_items; i++) {
    free(warehouse->inventory[i].name);
  }
  free(warehouse->inventory);
  free(warehouse->name);
  free(warehouse);
}

int main() {
  // Create a new warehouse
  struct warehouse *warehouse = create_warehouse("Blacksmith's Guild");

  // Add some items to the warehouse
  add_item(warehouse, "Iron bars", 100, 1.0);
  add_item(warehouse, "Steel plates", 50, 2.0);
  add_item(warehouse, "Swords", 25, 10.0);
  add_item(warehouse, "Axes", 20, 8.0);
  add_item(warehouse, "Hammers", 15, 5.0);

  // Print the inventory of the warehouse
  print_inventory(warehouse);

  // Remove an item from the warehouse
  remove_item(warehouse, "Axes");

  // Print the inventory of the warehouse again
  print_inventory(warehouse);

  // Destroy the warehouse
  destroy_warehouse(warehouse);

  return 0;
}