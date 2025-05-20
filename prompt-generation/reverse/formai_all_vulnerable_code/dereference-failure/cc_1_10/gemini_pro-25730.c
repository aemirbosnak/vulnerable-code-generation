//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char name[50];
  int quantity;
  float price;
};

struct node {
  struct product product;
  struct node *next;
};

struct node *head = NULL;

void insert(struct product product) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->product = product;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    struct node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

void delete(int id) {
  if (head == NULL) {
    printf("Inventory is empty.\n");
    return;
  }

  if (head->product.id == id) {
    struct node *temp = head;
    head = head->next;
    free(temp);
    return;
  }

  struct node *current_node = head;
  struct node *previous_node = NULL;
  while (current_node != NULL && current_node->product.id != id) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  if (current_node == NULL) {
    printf("Product not found.\n");
    return;
  }

  if (previous_node != NULL) {
    previous_node->next = current_node->next;
  }
  free(current_node);
}

void update(struct product product) {
  if (head == NULL) {
    printf("Inventory is empty.\n");
    return;
  }

  struct node *current_node = head;
  while (current_node != NULL && current_node->product.id != product.id) {
    current_node = current_node->next;
  }

  if (current_node == NULL) {
    printf("Product not found.\n");
    return;
  }

  current_node->product = product;
}

void search(int id) {
  if (head == NULL) {
    printf("Inventory is empty.\n");
    return;
  }

  struct node *current_node = head;
  while (current_node != NULL && current_node->product.id != id) {
    current_node = current_node->next;
  }

  if (current_node == NULL) {
    printf("Product not found.\n");
    return;
  }

  printf("ID: %d\n", current_node->product.id);
  printf("Name: %s\n", current_node->product.name);
  printf("Quantity: %d\n", current_node->product.quantity);
  printf("Price: %.2f\n", current_node->product.price);
}

void print() {
  if (head == NULL) {
    printf("Inventory is empty.\n");
    return;
  }

  struct node *current_node = head;
  while (current_node != NULL) {
    printf("ID: %d\n", current_node->product.id);
    printf("Name: %s\n", current_node->product.name);
    printf("Quantity: %d\n", current_node->product.quantity);
    printf("Price: %.2f\n\n", current_node->product.price);
    current_node = current_node->next;
  }
}

int main() {
  struct product product1 = {1, "iPhone 14", 10, 999.00};
  struct product product2 = {2, "Samsung Galaxy S23", 15, 1099.00};
  struct product product3 = {3, "Google Pixel 7", 12, 899.00};
  struct product product4 = {4, "OnePlus 11", 20, 799.00};

  insert(product1);
  insert(product2);
  insert(product3);
  insert(product4);

  print();

  struct product product1_updated = {1, "iPhone 14", 20, 999.00};
  update(product1_updated);

  printf("Updated Inventory:\n");
  print();

  delete(2);

  printf("Inventory after deletion:\n");
  print();

  search(3);

  return 0;
}