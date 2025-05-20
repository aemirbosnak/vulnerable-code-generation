//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct Medicine {
  char name[50];
  int quantity;
  float price;
  struct Medicine *next;
} Medicine;

// Function to add a medicine to the store
void addMedicine(Medicine **head, char *name, int quantity, float price) {
  Medicine *newMedicine = (Medicine *)malloc(sizeof(Medicine));
  strcpy(newMedicine->name, name);
  newMedicine->quantity = quantity;
  newMedicine->price = price;
  newMedicine->next = NULL;

  if (*head == NULL) {
    *head = newMedicine;
  } else {
    Medicine *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newMedicine;
  }
}

// Function to search for a medicine in the store
Medicine *searchMedicine(Medicine *head, char *name) {
  Medicine *temp = head;
  while (temp != NULL) {
    if (strcmp(temp->name, name) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

// Function to sell a medicine from the store
void sellMedicine(Medicine **head, char *name, int quantity) {
  Medicine *medicine = searchMedicine(*head, name);
  if (medicine != NULL) {
    if (medicine->quantity >= quantity) {
      medicine->quantity -= quantity;
      printf("Medicine sold successfully!\n");
    } else {
      printf("Insufficient quantity of medicine in stock.\n");
    }
  } else {
    printf("Medicine not found in stock.\n");
  }
}

// Function to print the list of medicines in the store
void printMedicines(Medicine *head) {
  Medicine *temp = head;
  while (temp != NULL) {
    printf("Name: %s\n", temp->name);
    printf("Quantity: %d\n", temp->quantity);
    printf("Price: %.2f\n\n", temp->price);
    temp = temp->next;
  }
}

// Main function
int main() {
  Medicine *head = NULL;

  // Add some medicines to the store
  addMedicine(&head, "Paracetamol", 100, 10.0);
  addMedicine(&head, "Ibuprofen", 50, 15.0);
  addMedicine(&head, "Aspirin", 75, 12.0);

  // Search for a medicine in the store
  Medicine *medicine = searchMedicine(head, "Paracetamol");
  if (medicine != NULL) {
    printf("Medicine found in stock.\n");
  } else {
    printf("Medicine not found in stock.\n");
  }

  // Sell a medicine from the store
  sellMedicine(&head, "Ibuprofen", 25);

  // Print the list of medicines in the store
  printf("List of medicines in stock:\n\n");
  printMedicines(head);

  return 0;
}