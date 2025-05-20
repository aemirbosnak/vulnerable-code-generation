//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct product {
  int id;
  char *code;
  char *name;
  int quantity;
  float price;
};

struct node {
  struct product product;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void add_product(int id, char *code, char *name, int quantity, float price) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->product.id = id;
  new_node->product.code = malloc(strlen(code) + 1);
  strcpy(new_node->product.code, code);
  new_node->product.name = malloc(strlen(name) + 1);
  strcpy(new_node->product.name, name);
  new_node->product.quantity = quantity;
  new_node->product.price = price;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
}

void print_product(struct product product) {
  printf("ID: %d\n", product.id);
  printf("Code: %s\n", product.code);
  printf("Name: %s\n", product.name);
  printf("Quantity: %d\n", product.quantity);
  printf("Price: %.2f\n", product.price);
  printf("\n");
}

void print_inventory() {
  struct node *current = head;
  while (current != NULL) {
    print_product(current->product);
    current = current->next;
  }
}

void delete_product(int id) {
  struct node *current = head;
  struct node *previous = NULL;

  while (current != NULL) {
    if (current->product.id == id) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->product.code);
      free(current->product.name);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void update_product(int id, int quantity) {
  struct node *current = head;

  while (current != NULL) {
    if (current->product.id == id) {
      current->product.quantity = quantity;
      return;
    }
    current = current->next;
  }
}

void search_product(char *code) {
  struct node *current = head;

  while (current != NULL) {
    if (strcmp(current->product.code, code) == 0) {
      print_product(current->product);
      return;
    }
    current = current->next;
  }
}

int main() {
  add_product(1, "ABC123", "Product 1", 10, 10.00);
  add_product(2, "DEF456", "Product 2", 20, 20.00);
  add_product(3, "GHI789", "Product 3", 30, 30.00);

  print_inventory();

  delete_product(2);

  print_inventory();

  update_product(1, 15);

  print_inventory();

  search_product("GHI789");

  return 0;
}