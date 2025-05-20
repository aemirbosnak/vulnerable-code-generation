//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a medicine
typedef struct Medicine {
  char name[50];
  char brand[50];
  int quantity;
  float price;
} Medicine;

// Structure to represent the medical store
typedef struct MedicalStore {
  Medicine *medicines;
  int num_medicines;
} MedicalStore;

// Function to create a new medicine
Medicine *create_medicine(char *name, char *brand, int quantity, float price) {
  Medicine *medicine = (Medicine *)malloc(sizeof(Medicine));
  strcpy(medicine->name, name);
  strcpy(medicine->brand, brand);
  medicine->quantity = quantity;
  medicine->price = price;
  return medicine;
}

// Function to add a medicine to the medical store
void add_medicine(MedicalStore *store, Medicine *medicine) {
  store->medicines = (Medicine *)realloc(store->medicines, (store->num_medicines + 1) * sizeof(Medicine));
  store->medicines[store->num_medicines] = *medicine;
  store->num_medicines++;
}

// Function to search for a medicine in the medical store
Medicine *search_medicine(MedicalStore *store, char *name) {
  for (int i = 0; i < store->num_medicines; i++) {
    if (strcmp(store->medicines[i].name, name) == 0) {
      return &store->medicines[i];
    }
  }
  return NULL;
}

// Function to sell a medicine from the medical store
void sell_medicine(MedicalStore *store, char *name, int quantity) {
  Medicine *medicine = search_medicine(store, name);
  if (medicine == NULL) {
    printf("Medicine not found!\n");
    return;
  }
  if (medicine->quantity < quantity) {
    printf("Insufficient quantity!\n");
    return;
  }
  medicine->quantity -= quantity;
  printf("Medicine sold successfully!\n");
}

// Function to print the medical store
void print_medical_store(MedicalStore *store) {
  printf("Medical Store:\n");
  for (int i = 0; i < store->num_medicines; i++) {
    printf("%s %s %d %f\n", store->medicines[i].name, store->medicines[i].brand, store->medicines[i].quantity, store->medicines[i].price);
  }
}

// Main function
int main() {
  // Create a new medical store
  MedicalStore store;
  store.medicines = NULL;
  store.num_medicines = 0;

  // Add some medicines to the medical store
  Medicine *medicine1 = create_medicine("Paracetamol", "Cipla", 100, 10.0);
  add_medicine(&store, medicine1);
  Medicine *medicine2 = create_medicine("Ibuprofen", "Advil", 50, 15.0);
  add_medicine(&store, medicine2);
  Medicine *medicine3 = create_medicine("Aspirin", "Bayer", 25, 5.0);
  add_medicine(&store, medicine3);

  // Print the medical store
  print_medical_store(&store);

  // Search for a medicine in the medical store
  Medicine *medicine = search_medicine(&store, "Ibuprofen");
  if (medicine != NULL) {
    printf("Medicine found: %s %s %d %f\n", medicine->name, medicine->brand, medicine->quantity, medicine->price);
  } else {
    printf("Medicine not found!\n");
  }

  // Sell a medicine from the medical store
  sell_medicine(&store, "Paracetamol", 20);

  // Print the medical store again
  print_medical_store(&store);

  return 0;
}