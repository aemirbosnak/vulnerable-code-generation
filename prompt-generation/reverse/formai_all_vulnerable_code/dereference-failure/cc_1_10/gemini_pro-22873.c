//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main structure for the medical store
struct medical_store {
  char name[50];  // The name of the medical store
  int num_items;  // The number of items in the store
  struct item *items;  // An array of items in the store
};

// The structure for an item in the medical store
struct item {
  char name[50];  // The name of the item
  int quantity;  // The quantity of the item in the store
  float price;  // The price of the item
};

// A function to create a new medical store
struct medical_store *create_medical_store(char *name) {
  struct medical_store *store = malloc(sizeof(struct medical_store));
  strcpy(store->name, name);
  store->num_items = 0;
  store->items = NULL;
  return store;
}

// A function to add an item to the medical store
void add_item(struct medical_store *store, char *name, int quantity, float price) {
  struct item *item = malloc(sizeof(struct item));
  strcpy(item->name, name);
  item->quantity = quantity;
  item->price = price;
  store->items = realloc(store->items, sizeof(struct item) * (store->num_items + 1));
  store->items[store->num_items] = *item;
  store->num_items++;
}

// A function to print the medical store
void print_medical_store(struct medical_store *store) {
  printf("Medical Store: %s\n", store->name);
  printf("Number of items: %d\n", store->num_items);
  for (int i = 0; i < store->num_items; i++) {
    printf("Item %d:\n", i + 1);
    printf("Name: %s\n", store->items[i].name);
    printf("Quantity: %d\n", store->items[i].quantity);
    printf("Price: %f\n", store->items[i].price);
  }
}

// A function to free the memory allocated for the medical store
void free_medical_store(struct medical_store *store) {
  for (int i = 0; i < store->num_items; i++) {
    free(store->items[i].name);
  }
  free(store->items);
  free(store);
}

// The main function
int main() {
  // Create a new medical store
  struct medical_store *store = create_medical_store("The Surrealist Pharmacy");

  // Add some items to the store
  add_item(store, "Dream Elixir", 10, 9.99);
  add_item(store, "Hallucinogenic Mushrooms", 5, 19.99);
  add_item(store, "Time Warp Potion", 1, 99.99);

  // Print the medical store
  print_medical_store(store);

  // Free the memory allocated for the medical store
  free_medical_store(store);

  return 0;
}