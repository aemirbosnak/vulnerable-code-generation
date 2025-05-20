//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  char name[50];
  int quantity;
  float price;
} Item;

Item* create_item(char* name, int quantity, float price);
void print_item(Item* item);
void print_inventory(Item** inventory, int size);
void add_item_to_inventory(Item*** inventory, int* size, Item* item);
void remove_item_from_inventory(Item*** inventory, int* size, char* name);

int main() {
  Item* item1 = create_item("apple", 10, 1.50);
  Item* item2 = create_item("banana", 7, 0.75);
  Item* item3 = create_item("orange", 5, 2.00);

  Item** inventory = NULL;
  int size = 0;

  add_item_to_inventory(&inventory, &size, item1);
  add_item_to_inventory(&inventory, &size, item2);
  add_item_to_inventory(&inventory, &size, item3);

  printf("Initial inventory:\n");
  print_inventory(inventory, size);

  // remove banana
  remove_item_from_inventory(&inventory, &size, "banana");

  // add more apples
  Item* item4 = create_item("apple", 5, 1.50);
  add_item_to_inventory(&inventory, &size, item4);

  printf("Updated inventory:\n");
  print_inventory(inventory, size);

  return 0;
}

Item* create_item(char* name, int quantity, float price) {
  Item* item = (Item*) malloc(sizeof(Item));

  strcpy(item->name, name);
  item->quantity = quantity;
  item->price = price;

  return item;
}

void print_item(Item* item) {
  printf("%s - Quantity: %d, Price: $%.2f\n", item->name, item->quantity, item->price);
}

void print_inventory(Item** inventory, int size) {
  for (int i = 0; i < size; i++) {
    print_item(inventory[i]);
  }

  printf("\n");
}

void add_item_to_inventory(Item*** inventory, int* size, Item* item) {
  *size += 1;
  *inventory = (Item**) realloc(*inventory, *size * sizeof(Item*));
  (*inventory)[*size - 1] = item;
}

void remove_item_from_inventory(Item*** inventory, int* size, char* name) {
  int index = -1;

  for (int i = 0; i < *size; i++) {
    if (strcmp((*inventory)[i]->name, name) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Item %s not found in inventory.\n", name);
    return;
  }

  free((*inventory)[index]);

  for (int i = index + 1; i < *size; i++) {
    (*inventory)[i - 1] = (*inventory)[i];
  }

  *size -= 1;
  *inventory = (Item**) realloc(*inventory, *size * sizeof(Item*));
}