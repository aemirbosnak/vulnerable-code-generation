//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  char *name;
  int quantity;
  float price;
};

struct inventory {
  struct product *products;
  int num_products;
};

struct inventory *create_inventory(int num_products) {
  struct inventory *inv = malloc(sizeof(struct inventory));
  inv->products = malloc(sizeof(struct product) * num_products);
  inv->num_products = num_products;
  return inv;
}

void destroy_inventory(struct inventory *inv) {
  for (int i = 0; i < inv->num_products; i++) {
    free(inv->products[i].name);
  }
  free(inv->products);
  free(inv);
}

void add_product(struct inventory *inv, char *name, int quantity, float price) {
  struct product *p = &inv->products[inv->num_products];
  p->name = strdup(name);
  p->quantity = quantity;
  p->price = price;
  inv->num_products++;
}

void remove_product(struct inventory *inv, char *name) {
  for (int i = 0; i < inv->num_products; i++) {
    if (strcmp(inv->products[i].name, name) == 0) {
      free(inv->products[i].name);
      for (int j = i + 1; j < inv->num_products; j++) {
        inv->products[j - 1] = inv->products[j];
      }
      inv->num_products--;
      break;
    }
  }
}

void print_inventory(struct inventory *inv) {
  for (int i = 0; i < inv->num_products; i++) {
    printf("%s %d %f\n", inv->products[i].name, inv->products[i].quantity, inv->products[i].price);
  }
}

int main() {
  struct inventory *inv = create_inventory(0);
  add_product(inv, "Apple", 10, 1.0);
  add_product(inv, "Orange", 5, 1.5);
  add_product(inv, "Banana", 20, 2.0);
  print_inventory(inv);
  remove_product(inv, "Orange");
  print_inventory(inv);
  destroy_inventory(inv);
  return 0;
}