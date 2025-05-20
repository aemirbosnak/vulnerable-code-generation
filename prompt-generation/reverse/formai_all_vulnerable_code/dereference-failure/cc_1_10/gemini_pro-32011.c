//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
  char name[50];
  int quantity;
  float price;
} medicine;

// Define the structure of a medical store
typedef struct medical_store {
  char name[50];
  char address[100];
  char phone[20];
  medicine *medicines;
  int num_medicines;
} medical_store;

// Create a new medical store
medical_store *create_medical_store(char *name, char *address, char *phone) {
  medical_store *store = malloc(sizeof(medical_store));
  strcpy(store->name, name);
  strcpy(store->address, address);
  strcpy(store->phone, phone);
  store->medicines = NULL;
  store->num_medicines = 0;
  return store;
}

// Add a new medicine to a medical store
void add_medicine(medical_store *store, char *name, int quantity, float price) {
  store->medicines = realloc(store->medicines, (store->num_medicines + 1) * sizeof(medicine));
  strcpy(store->medicines[store->num_medicines].name, name);
  store->medicines[store->num_medicines].quantity = quantity;
  store->medicines[store->num_medicines].price = price;
  store->num_medicines++;
}

// Print the details of a medical store
void print_medical_store(medical_store *store) {
  printf("Name: %s\n", store->name);
  printf("Address: %s\n", store->address);
  printf("Phone: %s\n", store->phone);
  printf("Medicines:\n");
  for (int i = 0; i < store->num_medicines; i++) {
    printf("  %s: %d units, $%.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
  }
}

// Free the memory allocated for a medical store
void free_medical_store(medical_store *store) {
  free(store->medicines);
  free(store);
}

// Main function
int main() {
  // Create a new medical store
  medical_store *store = create_medical_store("ABC Medical Store", "123 Main Street", "555-1212");

  // Add some medicines to the store
  add_medicine(store, "Aspirin", 100, 0.50);
  add_medicine(store, "Ibuprofen", 50, 1.00);
  add_medicine(store, "Acetaminophen", 75, 0.75);

  // Print the details of the store
  print_medical_store(store);

  // Free the memory allocated for the store
  free_medical_store(store);

  return 0;
}