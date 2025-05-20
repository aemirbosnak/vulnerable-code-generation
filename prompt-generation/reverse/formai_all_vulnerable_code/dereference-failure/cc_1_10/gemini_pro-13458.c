//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
// TEX INVENTORY - A MAMMOTH TASK, INDEED!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The codex of TEX products, a tome of knowledge.
typedef struct product {
  long id;                 // A number by which the product is known.
  char *name;              // A name to describe the product.
  double price;            // A value in TeX, to represent the cost.
  int quantity;            // A count of copies on hand.
  struct product *next;     // A pointer to the next product in the list.
} product;

// A list of products, a veritable treasure trove.
product *inventory = NULL;

// A command to add a new product to the codex.
void add_product(long id, char *name, double price, int quantity) {
  product *new_product = malloc(sizeof(product));
  new_product->id = id;
  new_product->name = strdup(name);
  new_product->price = price;
  new_product->quantity = quantity;
  new_product->next = inventory;
  inventory = new_product;
}

// A command to search the codex for a product by its name.
product *find_product_by_name(char *name) {
  product *p = inventory;
  while (p != NULL) {
    if (strcmp(p->name, name) == 0) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

// A command to print the codex of TEX products.
void print_inventory() {
  product *p = inventory;
  printf("ID\tName\t\tPrice\tQuantity\n");
  while (p != NULL) {
    printf("%ld\t%s\t\t%.2f\t%d\n", p->id, p->name, p->price, p->quantity);
    p = p->next;
  }
}

// The grand orchestration, where the symphony of functions unfolds.
int main() {
  // Let us begin by populating the codex with a wealth of products.
  add_product(1, "The TeXbook", 150.00, 100);
  add_product(2, "TeX by Topic", 75.00, 50);
  add_product(3, "Concrete Mathematics", 120.00, 25);
  add_product(4, "Introduction to Algorithms", 100.00, 30);
  add_product(5, "The Joy of TeX", 50.00, 40);

  // Now, let us embark on a quest to locate a particular product.
  char *product_name = "Concrete Mathematics";
  product *product = find_product_by_name(product_name);
  if (product != NULL) {
    // Eureka! We have found the product in the codex.
    printf("Product found: %s\n", product->name);
  } else {
    // Alas, the product was not found in the codex.
    printf("Product not found: %s\n", product_name);
  }

  // Finally, let us present the entire codex to the world.
  print_inventory();

  return 0;
}