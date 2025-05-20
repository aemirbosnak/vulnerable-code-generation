//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct Medicine {
  char name[50];
  char type[50];
  int quantity;
  float price;
} Medicine;

// Define the structure of a node in the linked list
typedef struct Node {
  Medicine medicine;
  struct Node *next;
} Node;

// Define the head of the linked list
Node *head = NULL;

// Function to add a medicine to the linked list
void addMedicine(Medicine medicine) {
  // Create a new node
  Node *newNode = (Node *)malloc(sizeof(Node));

  // Copy the medicine data into the new node
  newNode->medicine = medicine;

  // Set the next pointer of the new node to NULL
  newNode->next = NULL;

  // If the linked list is empty, set the head of the linked list to the new node
  if (head == NULL) {
    head = newNode;
  } else {
    // Find the last node in the linked list
    Node *lastNode = head;
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }

    // Set the next pointer of the last node to the new node
    lastNode->next = newNode;
  }
}

// Function to search for a medicine in the linked list
Node *searchMedicine(char *name) {
  // Traverse the linked list and compare the name of each medicine with the given name
  Node *currentNode = head;
  while (currentNode != NULL) {
    if (strcmp(currentNode->medicine.name, name) == 0) {
      return currentNode;
    }

    // Move to the next node
    currentNode = currentNode->next;
  }

  // If the medicine is not found, return NULL
  return NULL;
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
  // Find the medicine in the linked list
  Node *nodeToDelete = searchMedicine(name);

  // If the medicine is not found, return
  if (nodeToDelete == NULL) {
    return;
  }

  // If the medicine is found, remove it from the linked list
  if (nodeToDelete == head) {
    head = nodeToDelete->next;
  } else {
    // Find the previous node of the medicine to be deleted
    Node *previousNode = head;
    while (previousNode->next != nodeToDelete) {
      previousNode = previousNode->next;
    }

    // Set the next pointer of the previous node to the next pointer of the medicine to be deleted
    previousNode->next = nodeToDelete->next;
  }

  // Free the memory allocated to the medicine to be deleted
  free(nodeToDelete);
}

// Function to print the linked list
void printLinkedList() {
  // Traverse the linked list and print the data of each medicine
  Node *currentNode = head;
  while (currentNode != NULL) {
    printf("Name: %s\n", currentNode->medicine.name);
    printf("Type: %s\n", currentNode->medicine.type);
    printf("Quantity: %d\n", currentNode->medicine.quantity);
    printf("Price: %f\n\n", currentNode->medicine.price);

    // Move to the next node
    currentNode = currentNode->next;
  }
}

// Main function
int main() {
  // Create some medicines
  Medicine medicine1 = {"Paracetamol", "Pain reliever", 100, 10.0};
  Medicine medicine2 = {"Ibuprofen", "Pain reliever", 50, 15.0};
  Medicine medicine3 = {"Aspirin", "Pain reliever", 25, 5.0};

  // Add the medicines to the linked list
  addMedicine(medicine1);
  addMedicine(medicine2);
  addMedicine(medicine3);

  // Print the linked list
  printLinkedList();

  // Search for a medicine
  Node *foundMedicine = searchMedicine("Ibuprofen");

  // If the medicine is found, print its data
  if (foundMedicine != NULL) {
    printf("Found medicine:\n");
    printf("Name: %s\n", foundMedicine->medicine.name);
    printf("Type: %s\n", foundMedicine->medicine.type);
    printf("Quantity: %d\n", foundMedicine->medicine.quantity);
    printf("Price: %f\n", foundMedicine->medicine.price);
  } else {
    printf("Medicine not found.\n");
  }

  // Delete a medicine
  deleteMedicine("Aspirin");

  // Print the linked list again
  printLinkedList();

  return 0;
}