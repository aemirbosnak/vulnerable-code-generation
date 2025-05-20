//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: artistic
// Behold, the Symphony of Inventory!

#include <stdio.h>
#include <stdlib.h>

// The Maestro, Conductor of Products
typedef struct Product {
  char *name;                     // Name of the aria
  int quantity;                   // Number of verses
  float price;                    // Worth in golden notes
} Product;

// The Orchestra, Holding the Products
typedef struct Inventory {
  Product *products;             // Array of instruments
  int size;                       // Number of musicians
  int capacity;                   // Maximum ensemble size
} Inventory;

// Create the Orchestra
Inventory *createInventory(int initialCapacity) {
  Inventory *inventory = malloc(sizeof(Inventory));
  inventory->products = malloc(sizeof(Product) * initialCapacity);
  inventory->size = 0;
  inventory->capacity = initialCapacity;
  return inventory;
}

// Add a New Voice to the Orchestra
void addProduct(Inventory *inventory, Product product) {
  if (inventory->size >= inventory->capacity) {
    inventory->capacity *= 2;
    inventory->products = realloc(inventory->products, sizeof(Product) * inventory->capacity);
  }
  inventory->products[inventory->size++] = product;
}

// Print the Orchestra's Melodies
void printInventory(Inventory *inventory) {
  printf("Inventory:\n");
  for (int i = 0; i < inventory->size; i++) {
    Product product = inventory->products[i];
    printf("  %-20s %4d %6.2f\n", product.name, product.quantity, product.price);
  }
}

// Symphony's End, Orchestra Disbands
void destroyInventory(Inventory *inventory) {
  for (int i = 0; i < inventory->size; i++) {
    free(inventory->products[i].name);
  }
  free(inventory->products);
  free(inventory);
}

// The Grand Performance Begins
int main() {
  // Create the Orchestra's Foundation
  Inventory *inventory = createInventory(10);

  // Introduce the Instruments
  addProduct(inventory, (Product){"Flute", 5, 150.0f});
  addProduct(inventory, (Product){"Oboe", 3, 200.0f});
  addProduct(inventory, (Product){"Clarinet", 4, 175.0f});
  addProduct(inventory, (Product){"Violin", 10, 300.0f});
  addProduct(inventory, (Product){"Cello", 6, 400.0f});

  // Unveil the Orchestra's Grace
  printInventory(inventory);

  // The Encore: Expanding the Symphony
  inventory->capacity *= 2;
  inventory->products = realloc(inventory->products, sizeof(Product) * inventory->capacity);

  // Farewell, Sweet Orchestra
  destroyInventory(inventory);

  return 0; // The Symphony's Silent End
}