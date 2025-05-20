//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a product in the warehouse
typedef struct product {
  int id;               // Unique ID of the product
  char *name;           // Name of the product
  int quantity;        // Quantity of the product in stock
  float price;          // Price of the product per unit
  struct product *next;  // Pointer to the next product in the linked list
} product;

// Structure to represent the warehouse
typedef struct warehouse {
  product *head; // Pointer to the head of the linked list of products
  product *tail; // Pointer to the tail of the linked list of products
} warehouse;

// Function to create a new product
product *create_product(int id, char *name, int quantity, float price) {
  product *new_product = (product *)malloc(sizeof(product));
  new_product->id = id;
  new_product->name = name;
  new_product->quantity = quantity;
  new_product->price = price;
  new_product->next = NULL;
  return new_product;
}

// Function to add a product to the warehouse
void add_product(warehouse *warehouse, product *product) {
  if (warehouse->head == NULL) {
    warehouse->head = product;
    warehouse->tail = product;
  } else {
    warehouse->tail->next = product;
    warehouse->tail = product;
  }
}

// Function to remove a product from the warehouse
void remove_product(warehouse *warehouse, int id) {
  product *current = warehouse->head;
  product *previous = NULL;
  while (current != NULL) {
    if (current->id == id) {
      if (previous == NULL) {
        warehouse->head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }
}

// Function to find a product in the warehouse
product *find_product(warehouse *warehouse, int id) {
  product *current = warehouse->head;
  while (current != NULL) {
    if (current->id == id) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Function to print the contents of the warehouse
void print_warehouse(warehouse *warehouse) {
  product *current = warehouse->head;
  while (current != NULL) {
    printf("Product ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", current->id, current->name, current->quantity, current->price);
    current = current->next;
  }
}

// Function to calculate the total value of the warehouse
float calculate_total_value(warehouse *warehouse) {
  float total_value = 0.0;
  product *current = warehouse->head;
  while (current != NULL) {
    total_value += current->quantity * current->price;
    current = current->next;
  }
  return total_value;
}

// Main function
int main() {
  // Create a new warehouse
  warehouse warehouse = {NULL, NULL};

  // Add some products to the warehouse
  product *product1 = create_product(1, "Apple", 10, 1.0);
  add_product(&warehouse, product1);
  product *product2 = create_product(2, "Banana", 20, 1.5);
  add_product(&warehouse, product2);
  product *product3 = create_product(3, "Orange", 30, 2.0);
  add_product(&warehouse, product3);

  // Print the contents of the warehouse
  printf("Contents of the warehouse:\n");
  print_warehouse(&warehouse);

  // Calculate the total value of the warehouse
  float total_value = calculate_total_value(&warehouse);
  printf("Total value of the warehouse: %.2f\n", total_value);

  // Remove a product from the warehouse
  remove_product(&warehouse, 2);

  // Print the contents of the warehouse
  printf("Contents of the warehouse after removing product 2:\n");
  print_warehouse(&warehouse);

  // Calculate the total value of the warehouse
  total_value = calculate_total_value(&warehouse);
  printf("Total value of the warehouse after removing product 2: %.2f\n", total_value);

  // Find a product in the warehouse
  product *product4 = find_product(&warehouse, 3);
  if (product4 != NULL) {
    printf("Product 3 found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", product4->id, product4->name, product4->quantity, product4->price);
  } else {
    printf("Product 3 not found.\n");
  }

  return 0;
}