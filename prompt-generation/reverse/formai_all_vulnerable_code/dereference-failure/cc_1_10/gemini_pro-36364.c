//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the warehouse structure
typedef struct {
  char *name;
  int capacity;
  int stock;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse(char *name, int capacity) {
  warehouse *w = malloc(sizeof(warehouse));
  w->name = strdup(name);
  w->capacity = capacity;
  w->stock = 0;
  return w;
}

// Destroy a warehouse
void destroy_warehouse(warehouse *w) {
  free(w->name);
  free(w);
}

// Add stock to a warehouse
void add_stock(warehouse *w, int amount) {
  w->stock += amount;
  if (w->stock > w->capacity) {
    printf("Warning: Warehouse '%s' is now overstocked\n", w->name);
  }
}

// Remove stock from a warehouse
void remove_stock(warehouse *w, int amount) {
  w->stock -= amount;
  if (w->stock < 0) {
    printf("Error: Warehouse '%s' now has negative stock\n", w->name);
  }
}

// Print the details of a warehouse
void print_warehouse(warehouse *w) {
  printf("Name: %s\n", w->name);
  printf("Capacity: %d\n", w->capacity);
  printf("Stock: %d\n", w->stock);
}

// Main function
int main() {
  // Create a new warehouse
  warehouse *w1 = create_warehouse("Warehouse 1", 100);

  // Add some stock to the warehouse
  add_stock(w1, 50);

  // Print the details of the warehouse
  print_warehouse(w1);

  // Remove some stock from the warehouse
  remove_stock(w1, 25);

  // Print the details of the warehouse
  print_warehouse(w1);

  // Destroy the warehouse
  destroy_warehouse(w1);

  return 0;
}