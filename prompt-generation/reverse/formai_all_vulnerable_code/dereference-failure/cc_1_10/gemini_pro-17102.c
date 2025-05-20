//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int quantity;
  float price;
} Medicine;

Medicine *inventory;
int inventory_size;

void add_medicine(char *name, int quantity, float price) {
  inventory = realloc(inventory, sizeof(Medicine) * (inventory_size + 1));
  inventory[inventory_size].name = strdup(name);
  inventory[inventory_size].quantity = quantity;
  inventory[inventory_size].price = price;
  inventory_size++;
}

void remove_medicine(char *name) {
  int i;
  for (i = 0; i < inventory_size; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      break;
    }
  }

  if (i == inventory_size) {
    printf("Medicine not found.\n");
    return;
  }

  free(inventory[i].name);
  inventory_size--;

  for (; i < inventory_size; i++) {
    inventory[i] = inventory[i + 1];
  }
}

void update_medicine(char *name, int quantity, float price) {
  int i;
  for (i = 0; i < inventory_size; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      break;
    }
  }

  if (i == inventory_size) {
    printf("Medicine not found.\n");
    return;
  }

  inventory[i].quantity = quantity;
  inventory[i].price = price;
}

void print_inventory() {
  int i;
  for (i = 0; i < inventory_size; i++) {
    printf("%s %d %f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
}

int main() {
  add_medicine("Aspirin", 100, 0.50);
  add_medicine("Ibuprofen", 50, 0.75);
  add_medicine("Acetaminophen", 25, 0.25);

  print_inventory();

  remove_medicine("Ibuprofen");

  print_inventory();

  update_medicine("Aspirin", 200, 0.60);

  print_inventory();

  return 0;
}