//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the store
#define MAX_ITEMS 100

// Define the structure of an item in the store
typedef struct item {
  char name[50];
  int quantity;
  float price;
} item;

// Define the structure of the medical store
typedef struct medical_store {
  item items[MAX_ITEMS];
  int num_items;
} medical_store;

// Create a new medical store
medical_store* create_medical_store() {
  medical_store* store = malloc(sizeof(medical_store));
  if (store == NULL) {
    return NULL;
  }

  store->num_items = 0;

  return store;
}

// Add an item to the medical store
int add_item(medical_store* store, item* item) {
  if (store->num_items >= MAX_ITEMS) {
    return -1;
  }

  store->items[store->num_items++] = *item;

  return 0;
}

// Remove an item from the medical store
int remove_item(medical_store* store, char* name) {
  int i;

  for (i = 0; i < store->num_items; i++) {
    if (strcmp(store->items[i].name, name) == 0) {
      break;
    }
  }

  if (i == store->num_items) {
    return -1;
  }

  store->num_items--;

  for (; i < store->num_items; i++) {
    store->items[i] = store->items[i + 1];
  }

  return 0;
}

// Find an item in the medical store
item* find_item(medical_store* store, char* name) {
  int i;

  for (i = 0; i < store->num_items; i++) {
    if (strcmp(store->items[i].name, name) == 0) {
      return &store->items[i];
    }
  }

  return NULL;
}

// Print the medical store
void print_medical_store(medical_store* store) {
  int i;

  printf("Medical Store:\n");
  printf("---------------------------------------------------\n");
  printf("| Name | Quantity | Price |\n");
  printf("---------------------------------------------------\n");
  for (i = 0; i < store->num_items; i++) {
    printf("| %-20s | %-8d | %-6.2f |\n", store->items[i].name, store->items[i].quantity, store->items[i].price);
  }
  printf("---------------------------------------------------\n");
}

// Main function
int main() {
  medical_store* store = create_medical_store();

  item item1 = {"Paracetamol", 100, 10.0};
  add_item(store, &item1);

  item item2 = {"Ibuprofen", 50, 15.0};
  add_item(store, &item2);

  item item3 = {"Aspirin", 25, 7.5};
  add_item(store, &item3);

  print_medical_store(store);

  item* item = find_item(store, "Paracetamol");
  if (item != NULL) {
    printf("Found item: %s, quantity: %d, price: %.2f\n", item->name, item->quantity, item->price);
  } else {
    printf("Item not found.\n");
  }

  remove_item(store, "Ibuprofen");

  print_medical_store(store);

  return 0;
}