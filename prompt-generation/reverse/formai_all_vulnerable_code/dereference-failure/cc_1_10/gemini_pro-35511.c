//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines
#define MAX_MEDICINES 100

// Define the structure of a medicine
typedef struct Medicine {
  char name[50];
  float price;
  int quantity;
} Medicine;

// Define the structure of the medical store
typedef struct MedicalStore {
  Medicine medicines[MAX_MEDICINES];
  int num_medicines;
} MedicalStore;

// Create a new medical store
MedicalStore* create_medical_store() {
  MedicalStore* store = (MedicalStore*)malloc(sizeof(MedicalStore));
  store->num_medicines = 0;
  return store;
}

// Add a new medicine to the medical store
void add_medicine(MedicalStore* store, Medicine medicine) {
  if (store->num_medicines >= MAX_MEDICINES) {
    printf("Error: Maximum number of medicines reached.\n");
    return;
  }

  store->medicines[store->num_medicines] = medicine;
  store->num_medicines++;
}

// Search for a medicine in the medical store by name
Medicine* search_medicine_by_name(MedicalStore* store, char* name) {
  for (int i = 0; i < store->num_medicines; i++) {
    if (strcmp(store->medicines[i].name, name) == 0) {
      return &store->medicines[i];
    }
  }

  return NULL;
}

// Sell a medicine from the medical store
void sell_medicine(MedicalStore* store, char* name, int quantity) {
  Medicine* medicine = search_medicine_by_name(store, name);
  if (medicine == NULL) {
    printf("Error: Medicine not found.\n");
    return;
  }

  if (medicine->quantity < quantity) {
    printf("Error: Insufficient quantity of medicine.\n");
    return;
  }

  medicine->quantity -= quantity;
}

// Print the list of all medicines in the medical store
void print_medicines(MedicalStore* store) {
  printf("List of all medicines:\n");
  for (int i = 0; i < store->num_medicines; i++) {
    printf("%s %f %d\n", store->medicines[i].name, store->medicines[i].price, store->medicines[i].quantity);
  }
}

// Main function
int main() {
  // Create a new medical store
  MedicalStore* store = create_medical_store();

  // Add some medicines to the medical store
  Medicine medicine1 = {"Paracetamol", 10.0, 100};
  add_medicine(store, medicine1);
  Medicine medicine2 = {"Ibuprofen", 15.0, 50};
  add_medicine(store, medicine2);
  Medicine medicine3 = {"Aspirin", 5.0, 200};
  add_medicine(store, medicine3);

  // Print the list of all medicines
  print_medicines(store);

  // Sell some medicines
  sell_medicine(store, "Paracetamol", 50);
  sell_medicine(store, "Ibuprofen", 25);

  // Print the list of all medicines
  print_medicines(store);

  // Free the memory allocated for the medical store
  free(store);

  return 0;
}