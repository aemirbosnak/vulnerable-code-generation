//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *name;
  int quantity;
  float price;
} Medicine;

typedef struct {
  Medicine *medicines;
  int num_medicines;
} MedicalStore;

MedicalStore *create_medical_store() {
  MedicalStore *store = malloc(sizeof(MedicalStore));
  store->medicines = NULL;
  store->num_medicines = 0;
  return store;
}

void add_medicine(MedicalStore *store, Medicine *medicine) {
  store->medicines = realloc(store->medicines, sizeof(Medicine) * (store->num_medicines + 1));
  store->medicines[store->num_medicines++] = *medicine;
}

Medicine *find_medicine(MedicalStore *store, char *name) {
  for (int i = 0; i < store->num_medicines; i++) {
    if (strcmp(store->medicines[i].name, name) == 0) {
      return &store->medicines[i];
    }
  }
  return NULL;
}

void print_medical_store(MedicalStore *store) {
  printf("Medical Store:\n");
  for (int i = 0; i < store->num_medicines; i++) {
    printf("  %s: %d, $%.2f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
  }
}

int main() {
  MedicalStore *store = create_medical_store();

  Medicine medicine1 = {"Aspirin", 100, 0.50};
  add_medicine(store, &medicine1);

  Medicine medicine2 = {"Ibuprofen", 50, 1.00};
  add_medicine(store, &medicine2);

  Medicine medicine3 = {"Paracetamol", 25, 0.25};
  add_medicine(store, &medicine3);

  print_medical_store(store);

  Medicine *medicine = find_medicine(store, "Ibuprofen");
  if (medicine != NULL) {
    printf("Found medicine: %s\n", medicine->name);
  } else {
    printf("Medicine not found.\n");
  }

  return 0;
}