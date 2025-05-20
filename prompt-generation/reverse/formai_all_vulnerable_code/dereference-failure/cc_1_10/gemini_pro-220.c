//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
  int id;
  char *name;
  int quantity;
  float price;
} product;

product *create_product(int id, const char *name, int quantity, float price) {
  product *p = malloc(sizeof(product));
  p->id = id;
  p->name = strdup(name);
  p->quantity = quantity;
  p->price = price;
  return p;
}

void destroy_product(product *p) {
  free(p->name);
  free(p);
}

int main() {
  product *p1 = create_product(1, "Product 1", 10, 10.0);
  product *p2 = create_product(2, "Product 2", 20, 20.0);
  product *p3 = create_product(3, "Product 3", 30, 30.0);

  // Add the products to an array
  product *products[] = {p1, p2, p3};
  int num_products = sizeof(products) / sizeof(product *);

  // Print the products
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s, Quantity: %d, Price: %f\n",
           products[i]->id, products[i]->name, products[i]->quantity, products[i]->price);
  }

  // Update the quantity of the second product
  products[1]->quantity = 15;

  // Print the products again
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s, Quantity: %d, Price: %f\n",
           products[i]->id, products[i]->name, products[i]->quantity, products[i]->price);
  }

  // Destroy the products
  for (int i = 0; i < num_products; i++) {
    destroy_product(products[i]);
  }

  return 0;
}