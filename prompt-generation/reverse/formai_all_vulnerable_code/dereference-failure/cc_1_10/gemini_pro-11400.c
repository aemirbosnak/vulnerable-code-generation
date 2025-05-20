//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A curious struct to hold a drug
struct Drug {
  char* name;
  int quantity;
  float price;
};

// A curious function to create a new drug
struct Drug* create_drug(char* name, int quantity, float price) {
  struct Drug* drug = malloc(sizeof(struct Drug));
  drug->name = malloc(strlen(name) + 1);
  strcpy(drug->name, name);
  drug->quantity = quantity;
  drug->price = price;
  return drug;
}

// A curious function to print a drug
void print_drug(struct Drug* drug) {
  printf("Name: %s\n", drug->name);
  printf("Quantity: %d\n", drug->quantity);
  printf("Price: %.2f\n", drug->price);
}

// A curious function to manage the medical store
void manage_medical_store() {
  // A curious array of drugs
  struct Drug* drugs[] = {
    create_drug("Paracetamol", 100, 10.0),
    create_drug("Ibuprofen", 50, 12.0),
    create_drug("Aspirin", 25, 8.0),
    create_drug("Codeine", 10, 15.0),
    create_drug("Morphine", 5, 20.0),
  };

  // A curious loop to print the drugs
  for (int i = 0; i < 5; i++) {
    print_drug(drugs[i]);
    printf("\n");
  }

  // A curious prompt for the user
  char input[100];
  printf("Enter a drug name to search for: ");
  scanf("%s", input);

  // A curious loop to search for the drug
  int found = 0;
  for (int i = 0; i < 5; i++) {
    if (strcmp(drugs[i]->name, input) == 0) {
      print_drug(drugs[i]);
      found = 1;
      break;
    }
  }

  // A curious message if the drug was not found
  if (!found) {
    printf("Drug not found.\n");
  }
}

int main() {
  manage_medical_store();
  return 0;
}