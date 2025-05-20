//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
  char *name;
  int quantity;
  float price;
} Product;

typedef struct ProductNode {
  Product *product;
  struct ProductNode *next;
} ProductNode;

ProductNode *head = NULL;

void addProduct(Product *product) {
  ProductNode *node = malloc(sizeof(ProductNode));
  node->product = product;
  node->next = head;
  head = node;
}

Product *findProduct(char *name) {
  ProductNode *current = head;
  while (current != NULL) {
    if (strcmp(current->product->name, name) == 0) {
      return current->product;
    }
    current = current->next;
  }
  return NULL;
}

void removeProduct(char *name) {
  ProductNode *current = head;
  ProductNode *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->product->name, name) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->product->name);
      free(current->product);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void updateProductQuantity(char *name, int quantity) {
  Product *product = findProduct(name);
  if (product != NULL) {
    product->quantity = quantity;
  }
}

void updateProductPrice(char *name, float price) {
  Product *product = findProduct(name);
  if (product != NULL) {
    product->price = price;
  }
}

void printInventory() {
  ProductNode *current = head;
  while (current != NULL) {
    printf("%s: %d @ %.2f\n", current->product->name, current->product->quantity, current->product->price);
    current = current->next;
  }
}

int main() {
  Product *product1 = malloc(sizeof(Product));
  product1->name = "Sword";
  product1->quantity = 10;
  product1->price = 100.00;
  addProduct(product1);

  Product *product2 = malloc(sizeof(Product));
  product2->name = "Shield";
  product2->quantity = 5;
  product2->price = 50.00;
  addProduct(product2);

  Product *product3 = malloc(sizeof(Product));
  product3->name = "Bow and Arrow";
  product3->quantity = 20;
  product3->price = 75.00;
  addProduct(product3);

  printInventory();

  updateProductQuantity("Sword", 15);
  updateProductPrice("Shield", 75.00);

  printInventory();

  removeProduct("Bow and Arrow");

  printInventory();

  return 0;
}