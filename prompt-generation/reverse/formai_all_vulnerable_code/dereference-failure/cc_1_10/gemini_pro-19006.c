//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char *name;
  int quantity;
  double price;
} product;

product *products;
int num_products;

void add_product(int id, char *name, int quantity, double price) {
  products = realloc(products, (num_products + 1) * sizeof(product));
  products[num_products].id = id;
  products[num_products].name = strdup(name);
  products[num_products].quantity = quantity;
  products[num_products].price = price;
  num_products++;
}

void print_products() {
  for (int i = 0; i < num_products; i++) {
    printf("Product %d: %s, Quantity: %d, Price: %f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
  }
}

void search_product(int id) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      printf("Product %d: %s, Quantity: %d, Price: %f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
      return;
    }
  }
  printf("Product not found!\n");
}

void update_product(int id, int quantity) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      products[i].quantity = quantity;
      printf("Product %d updated!\n", products[i].id);
      return;
    }
  }
  printf("Product not found!\n");
}

void delete_product(int id) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == id) {
      free(products[i].name);
      for (int j = i + 1; j < num_products; j++) {
        products[j - 1] = products[j];
      }
      num_products--;
      printf("Product %d deleted!\n", id);
      return;
    }
  }
  printf("Product not found!\n");
}

int main() {
  add_product(1, "Apple", 10, 1.0);
  add_product(2, "Orange", 5, 1.5);
  add_product(3, "Banana", 15, 2.0);

  print_products();

  search_product(2);
  update_product(3, 20);
  delete_product(1);

  print_products();

  return 0;
}