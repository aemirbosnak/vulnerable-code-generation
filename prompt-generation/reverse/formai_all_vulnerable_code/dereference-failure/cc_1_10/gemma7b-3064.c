//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define a surrealist medical store database structure
typedef struct MedicalStore {
  char name[255];
  int quantity;
  double price;
  struct MedicalStore* next;
} MedicalStore;

// Create a linked list of medical store items
MedicalStore* head = NULL;

// Function to insert a new item into the medical store list
void insertItem(char* name, int quantity, double price) {
  MedicalStore* newNode = (MedicalStore*)malloc(sizeof(MedicalStore));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    MedicalStore* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Function to find an item in the medical store list
MedicalStore* findItem(char* name) {
  MedicalStore* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Function to update the quantity of an item in the medical store list
void updateQuantity(char* name, int newQuantity) {
  MedicalStore* item = findItem(name);
  if (item) {
    item->quantity = newQuantity;
  }
}

// Function to remove an item from the medical store list
void removeItem(char* name) {
  MedicalStore* current = head;
  MedicalStore* previous = NULL;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
  return;
}

// Main function
int main() {
  insertItem("Aspirin", 100, 2.0);
  insertItem("Tylenol", 50, 2.5);
  insertItem("Ibuprofen", 75, 3.0);

  MedicalStore* item = findItem("Tylenol");
  if (item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2lf\n", item->price);
  }

  updateQuantity("Aspirin", 150);

  item = findItem("Aspirin");
  if (item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
  }

  removeItem("Ibuprofen");

  item = findItem("Ibuprofen");
  if (item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
  }

  return 0;
}