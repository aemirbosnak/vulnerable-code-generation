//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Product Structure
typedef struct {
  int id;
  char name[50];
  int stock;
  float price;
} Product;

// Database Structure
typedef struct {
  Product *products;
  int size;
  int count;
} Database;

// Function to initialize database with a given size
void initDatabase(Database *database, int size) {
  database->products = malloc(sizeof(Product) * size);
  database->size = size;
  database->count = 0;
}

// Function to add a new product to database
void addProduct(Database *database, Product product) {
  if (database->count == database->size) {
    printf("Error: The database is full.\n");
    return;
  }

  for (int i = 0; i < database->count; i++) {
    if (database->products[i].id == product.id) {
      printf("Error: A product with this id already exists.\n");
      return;
    }
  }

  database->products[database->count++] = product;
}

// Function to remove product from database
void removeProduct(Database *database, int id) {
  int index = -1;

  for (int i = 0; i < database->count; i++) {
    if (database->products[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Error: No product with this id.\n");
    return;
  }

  for (int i = index; i < database->count - 1; i++) {
    database->products[i] = database->products[i + 1];
  }

  database->count--;
}

// Function to find product by id
Product *findProductById(Database *database, int id) {
  for (int i = 0; i < database->count; i++) {
    if (database->products[i].id == id) {
      return &database->products[i];
    }
  }

  return NULL;
}

// Function to print database
void printDatabase(Database *database) {
  printf("Product Inventory System\n");
  printf("Id\tName\t\tStock\tPrice\n");

  for (int i = 0; i < database->count; i++) {
    printf("%d\t%s\t\t%d\t%.2f\n",
        database->products[i].id,
        database->products[i].name,
        database->products[i].stock,
        database->products[i].price);
  }
}

// Main function
int main() {
  Database database;
  initDatabase(&database, 10);

  // Add products to database
  addProduct(&database, (Product) { 1, "Product 1", 10, 5.99 });
  addProduct(&database, (Product) { 2, "Product 2", 5, 9.99 });
  addProduct(&database, (Product) { 3, "Product 3", 20, 3.99 });

  // Print database
  printDatabase(&database);

  // Remove a product from the database
  removeProduct(&database, 2);

  // Print database again
  printDatabase(&database);

  // Find a product by id and update its price
  Product *product = findProductById(&database, 1);
  if (product != NULL) {
    product->price = 6.99;
  }

  // Print database once again
  printDatabase(&database);

  // Free memory allocated for database
  free(database.products);

  return 0;
}