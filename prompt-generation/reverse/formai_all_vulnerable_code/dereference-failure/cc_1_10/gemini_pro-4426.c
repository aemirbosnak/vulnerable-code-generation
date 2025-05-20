//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a product structure
typedef struct Product {
  int id;
  char *name;
  int quantity;
  double price;
} Product;

// Define a linked list node
typedef struct Node {
  Product product;
  struct Node *next;
} Node;

// Create a new product
Product *createProduct(int id, char *name, int quantity, double price) {
  Product *product = (Product *)malloc(sizeof(Product));
  product->id = id;
  product->name = strdup(name);
  product->quantity = quantity;
  product->price = price;
  return product;
}

// Create a new node
Node *createNode(Product product) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->product = product;
  node->next = NULL;
  return node;
}

// Add a product to the linked list
void addProduct(Node **head, Product product) {
  Node *node = createNode(product);
  node->next = *head;
  *head = node;
}

// Remove a product from the linked list
void removeProduct(Node **head, int id) {
  Node *current = *head;
  Node *previous = NULL;

  while (current != NULL) {
    if (current->product.id == id) {
      if (previous == NULL) {
        *head = current->next;
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

// Find a product by ID
Product *findProduct(Node *head, int id) {
  Node *current = head;

  while (current != NULL) {
    if (current->product.id == id) {
      return &current->product;
    }
    current = current->next;
  }

  return NULL;
}

// Print the linked list
void printLinkedList(Node *head) {
  Node *current = head;

  while (current != NULL) {
    printf("Product ID: %d\n", current->product.id);
    printf("Product Name: %s\n", current->product.name);
    printf("Product Quantity: %d\n", current->product.quantity);
    printf("Product Price: %.2f\n\n", current->product.price);
    current = current->next;
  }
}

// Destroy the linked list
void destroyLinkedList(Node *head) {
  Node *current = head;

  while (current != NULL) {
    Node *next = current->next;
    free(current->product.name);
    free(current);
    current = next;
  }
}

int main() {
  // Create a linked list
  Node *head = NULL;

  // Add some products to the linked list
  addProduct(&head, *createProduct(1, "Apple", 10, 1.00));
  addProduct(&head, *createProduct(2, "Orange", 5, 2.00));
  addProduct(&head, *createProduct(3, "Banana", 15, 0.50));

  // Print the linked list
  printf("The products in the inventory are:\n\n");
  printLinkedList(head);

  // Find a product by ID
  Product *product = findProduct(head, 2);

  // If the product was found, print it
  if (product != NULL) {
    printf("\nFound the product with ID %d:\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Product Quantity: %d\n", product->quantity);
    printf("Product Price: %.2f\n", product->price);
  } else {
    printf("\nProduct with ID %d not found.\n", 2);
  }

  // Remove a product from the linked list
  removeProduct(&head, 3);

  // Print the linked list
  printf("\nThe products in the inventory after removing product with ID 3 are:\n\n");
  printLinkedList(head);

  // Destroy the linked list
  destroyLinkedList(head);

  return 0;
}