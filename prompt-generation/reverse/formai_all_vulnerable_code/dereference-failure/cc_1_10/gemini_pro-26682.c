//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char *name;
  int quantity;
  float price;
};

struct warehouse {
  struct product *products;
  int num_products;
  int capacity;
};

struct warehouse *create_warehouse(int capacity) {
  struct warehouse *warehouse = malloc(sizeof(struct warehouse));
  warehouse->products = malloc(sizeof(struct product) * capacity);
  warehouse->num_products = 0;
  warehouse->capacity = capacity;
  return warehouse;
}

void destroy_warehouse(struct warehouse *warehouse) {
  for (int i = 0; i < warehouse->num_products; i++) {
    free(warehouse->products[i].name);
  }
  free(warehouse->products);
  free(warehouse);
}

int add_product(struct warehouse *warehouse, struct product *product) {
  if (warehouse->num_products == warehouse->capacity) {
    return -1;
  }
  warehouse->products[warehouse->num_products++] = *product;
  return 0;
}

struct product *find_product(struct warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (warehouse->products[i].id == id) {
      return &warehouse->products[i];
    }
  }
  return NULL;
}

int remove_product(struct warehouse *warehouse, int id) {
  for (int i = 0; i < warehouse->num_products; i++) {
    if (warehouse->products[i].id == id) {
      for (int j = i; j < warehouse->num_products - 1; j++) {
        warehouse->products[j] = warehouse->products[j + 1];
      }
      warehouse->num_products--;
      return 0;
    }
  }
  return -1;
}

void print_warehouse(struct warehouse *warehouse) {
  printf("Warehouse:\n");
  for (int i = 0; i < warehouse->num_products; i++) {
    printf("  - %s (%d, %f)\n", warehouse->products[i].name, warehouse->products[i].quantity, warehouse->products[i].price);
  }
}

int main() {
  struct warehouse *warehouse = create_warehouse(5);

  struct product product1 = {1, "Apple", 10, 1.00};
  struct product product2 = {2, "Banana", 20, 2.00};
  struct product product3 = {3, "Orange", 30, 3.00};

  add_product(warehouse, &product1);
  add_product(warehouse, &product2);
  add_product(warehouse, &product3);

  print_warehouse(warehouse);

  struct product *product = find_product(warehouse, 2);
  if (product != NULL) {
    printf("Found product: %s\n", product->name);
  } else {
    printf("Product not found.\n");
  }

  remove_product(warehouse, 3);

  print_warehouse(warehouse);

  destroy_warehouse(warehouse);

  return 0;
}