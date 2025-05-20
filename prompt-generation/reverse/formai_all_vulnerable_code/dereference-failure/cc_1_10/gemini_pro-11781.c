//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
typedef struct Product {
  int id;
  char *name;
  float price;
  int quantity;
} Product;

// Node structure
typedef struct Node {
  Product product;
  struct Node *next;
} Node;

// Head of the linked list
Node *head = NULL;

// Add a product to the inventory
void add_product(Product product) {
  // Create a new node
  Node *new_node = malloc(sizeof(Node));
  new_node->product = product;
  new_node->next = NULL;

  // Add the new node to the beginning of the linked list
  if (head == NULL) {
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
}

// Remove a product from the inventory
void remove_product(int id) {
  // Find the product to be removed
  Node *current = head;
  Node *previous = NULL;
  while (current != NULL && current->product.id != id) {
    previous = current;
    current = current->next;
  }

  // If the product was found, remove it from the linked list
  if (current != NULL) {
    if (previous == NULL) {
      head = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
  }
}

// Update a product's quantity
void update_quantity(int id, int quantity) {
  // Find the product to be updated
  Node *current = head;
  while (current != NULL && current->product.id != id) {
    current = current->next;
  }

  // If the product was found, update its quantity
  if (current != NULL) {
    current->product.quantity = quantity;
  }
}

// Print the inventory
void print_inventory() {
  // Iterate over the linked list and print each product
  Node *current = head;
  while (current != NULL) {
    printf("Product ID: %d\n", current->product.id);
    printf("Product Name: %s\n", current->product.name);
    printf("Product Price: %f\n", current->product.price);
    printf("Product Quantity: %d\n\n", current->product.quantity);
    current = current->next;
  }
}

// Main function
int main() {
  // Create some products
  Product product1 = {1, "iPhone 13 Pro", 999.99, 10};
  Product product2 = {2, "Samsung Galaxy S22 Ultra", 1099.99, 15};
  Product product3 = {3, "Google Pixel 6 Pro", 899.99, 20};

  // Add the products to the inventory
  add_product(product1);
  add_product(product2);
  add_product(product3);

  // Print the inventory
  print_inventory();

  // Remove a product from the inventory
  remove_product(2);

  // Update a product's quantity
  update_quantity(1, 15);

  // Print the inventory again
  print_inventory();

  return 0;
}