//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
// Chapter 12, Section 12.2, page 279
// A Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drugs in the inventory.
#define MAX_DRUGS 100

// Define the structure of a drug.
typedef struct drug {
  char name[50];
  int quantity;
  float price;
} drug_t;

// Define the structure of the inventory.
typedef struct inventory {
  drug_t drugs[MAX_DRUGS];
  int num_drugs;
} inventory_t;

// Create a new inventory.
inventory_t *new_inventory() {
  inventory_t *inv = malloc(sizeof(inventory_t));
  inv->num_drugs = 0;
  return inv;
}

// Add a drug to the inventory.
void add_drug(inventory_t *inv, char *name, int quantity, float price) {
  if (inv->num_drugs == MAX_DRUGS) {
    printf("Error: The inventory is full.\n");
    return;
  }

  strcpy(inv->drugs[inv->num_drugs].name, name);
  inv->drugs[inv->num_drugs].quantity = quantity;
  inv->drugs[inv->num_drugs].price = price;
  inv->num_drugs++;
}

// Remove a drug from the inventory.
void remove_drug(inventory_t *inv, char *name) {
  int i;

  for (i = 0; i < inv->num_drugs; i++) {
    if (strcmp(inv->drugs[i].name, name) == 0) {
      inv->drugs[i] = inv->drugs[inv->num_drugs - 1];
      inv->num_drugs--;
      return;
    }
  }

  printf("Error: The drug '%s' is not in the inventory.\n", name);
}

// Search for a drug in the inventory.
drug_t *search_drug(inventory_t *inv, char *name) {
  int i;

  for (i = 0; i < inv->num_drugs; i++) {
    if (strcmp(inv->drugs[i].name, name) == 0) {
      return &inv->drugs[i];
    }
  }

  return NULL;
}

// Print the inventory.
void print_inventory(inventory_t *inv) {
  int i;

  printf("Inventory:\n");
  for (i = 0; i < inv->num_drugs; i++) {
    printf("  %s: %d units, $%.2f each\n", inv->drugs[i].name, inv->drugs[i].quantity, inv->drugs[i].price);
  }
}

// Main function.
int main() {
  inventory_t *inv = new_inventory();

  add_drug(inv, "Aspirin", 100, 0.50);
  add_drug(inv, "Ibuprofen", 50, 1.00);
  add_drug(inv, "Acetaminophen", 25, 0.75);

  print_inventory(inv);

  drug_t *drug = search_drug(inv, "Ibuprofen");
  if (drug != NULL) {
    printf("Found %s: %d units, $%.2f each\n", drug->name, drug->quantity, drug->price);
  } else {
    printf("Drug not found.\n");
  }

  remove_drug(inv, "Ibuprofen");

  print_inventory(inv);

  return 0;
}