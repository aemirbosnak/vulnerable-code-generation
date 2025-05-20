//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a medicine
typedef struct Medicine {
  char name[20];
  int quantity;
  float price;
} Medicine;

// Create a linked list of medicines
typedef struct MedicineNode {
  Medicine medicine;
  struct MedicineNode* next;
} MedicineNode;

// Function to insert a medicine into the linked list
void insertMedicine(MedicineNode** head, Medicine medicine) {
  MedicineNode* newNode = (MedicineNode*)malloc(sizeof(MedicineNode));
  newNode->medicine = medicine;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

// Function to search for a medicine in the linked list
MedicineNode* searchMedicine(MedicineNode* head, char* name) {
  while (head) {
    if (strcmp(head->medicine.name, name) == 0) {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

int main() {
  // Create a linked list of medicines
  MedicineNode* head = NULL;

  // Insert some medicines into the linked list
  insertMedicine(&head, (Medicine){.name = "Acetaminophen", .quantity = 100, .price = 5.0});
  insertMedicine(&head, (Medicine){.name = "Ibuprofen", .quantity = 50, .price = 7.0});
  insertMedicine(&head, (Medicine){.name = "Tylenol", .quantity = 20, .price = 4.0});

  // Search for a medicine in the linked list
  MedicineNode* foundNode = searchMedicine(head, "Acetaminophen");

  // Print the found medicine
  if (foundNode) {
    printf("Name: %s\n", foundNode->medicine.name);
    printf("Quantity: %d\n", foundNode->medicine.quantity);
    printf("Price: %.2f\n", foundNode->medicine.price);
  } else {
    printf("Medicine not found.\n");
  }

  return 0;
}