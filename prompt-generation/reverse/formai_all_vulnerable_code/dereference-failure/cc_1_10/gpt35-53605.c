//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

// define new weight type
typedef struct {
  float value; // weight in kg
  char unit[3]; // weight unit
} Weight;

// define product type
typedef struct {
  char name[50]; // product name
  int id; // product id
  Weight weight; // product weight
} Product;

// define warehouse type
typedef struct {
  Product *products; // array of products
  int count; // total products count
} Warehouse;

// function to add a new product to the warehouse
void addProduct(Warehouse *wh, char name[], int id, float weight, char unit[]) {
  wh->count++;
  wh->products = realloc(wh->products, wh->count * sizeof(Product));
  Product newProduct;
  newProduct.id = id;
  newProduct.weight.value = weight;
  strcpy(newProduct.weight.unit, unit);
  strcpy(newProduct.name, name);
  wh->products[wh->count-1] = newProduct;
  printf("New product '%s' added to warehouse with id %d.\n", name, id);
}

// function to print all products in the warehouse
void displayProducts(Warehouse *wh) {
  printf("Warehouse contains %d products.\n", wh->count);
  for(int i = 0; i < wh->count; i++) {
    printf("Product %d: Name: %s, ID: %d, Weight: %.2f%s.\n", i+1, wh->products[i].name, wh->products[i].id, wh->products[i].weight.value, wh->products[i].weight.unit);
  }
}

int main() {
  Warehouse *wh = malloc(sizeof(Warehouse));
  wh->count = 0; // initialize warehouse products count
  wh->products = NULL; // initialize warehouse products array

  addProduct(wh, "Flour", 101, 2.5, "kg");
  addProduct(wh, "Sugar", 102, 1.5, "kg");
  addProduct(wh, "Rice", 103, 3, "kg");

  displayProducts(wh);

  free(wh->products);
  free(wh);
  return 0;
}