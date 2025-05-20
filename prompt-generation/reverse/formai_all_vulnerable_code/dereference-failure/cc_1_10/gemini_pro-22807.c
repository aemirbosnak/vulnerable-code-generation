//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
  int id;
  char name[50];
  float price;
  int quantity;
} product;

product *inventory;
int num_products = 0;
int max_products = 100;

void init_inventory() {
  inventory = malloc(sizeof(product) * max_products);
  num_products = 0;
}

void add_product(product p) {
  if (num_products >= max_products) {
    max_products *= 2;
    inventory = realloc(inventory, sizeof(product) * max_products);
  }
  inventory[num_products++] = p;
}

void remove_product(int id) {
  int i;
  for (i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      inventory[i] = inventory[num_products - 1];
      num_products--;
      return;
    }
  }
}

product *get_product(int id) {
  int i;
  for (i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      return &inventory[i];
    }
  }
  return NULL;
}

void print_inventory() {
  int i;
  printf("Inventory:\n");
  for (i = 0; i < num_products; i++) {
    printf("%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

int main() {
  init_inventory();

  product p1 = {1, "Product 1", 10.0, 5};
  add_product(p1);

  product p2 = {2, "Product 2", 20.0, 10};
  add_product(p2);

  product *p3 = get_product(1);
  if (p3 != NULL) {
    printf("Product 1: %s %.2f %d\n", p3->name, p3->price, p3->quantity);
  }

  remove_product(2);

  print_inventory();

  return 0;
}