//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
  char name[50];
  char manufacturer[50];
  float price;
  int quantity;
} medicine;

// Define the structure of a node in the linked list
typedef struct node {
  medicine data;
  struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to add a medicine to the linked list
void addMedicine(char *name, char *manufacturer, float price, int quantity) {
  // Create a new node
  node *new_node = (node *)malloc(sizeof(node));

  // Populate the data in the new node
  strcpy(new_node->data.name, name);
  strcpy(new_node->data.manufacturer, manufacturer);
  new_node->data.price = price;
  new_node->data.quantity = quantity;

  // Insert the new node at the beginning of the linked list
  new_node->next = head;
  head = new_node;
}

// Function to search for a medicine in the linked list
node *searchMedicine(char *name) {
  // Traverse the linked list
  node *current_node = head;
  while (current_node != NULL) {
    // Check if the name of the current node matches the name of the medicine being searched for
    if (strcmp(current_node->data.name, name) == 0) {
      // Return the current node if the medicine is found
      return current_node;
    }

    // Move to the next node
    current_node = current_node->next;
  }

  // Return NULL if the medicine is not found
  return NULL;
}

// Function to delete a medicine from the linked list
void deleteMedicine(char *name) {
  // Search for the medicine in the linked list
  node *node_to_delete = searchMedicine(name);

  // Check if the medicine was found
  if (node_to_delete == NULL) {
    printf("Medicine not found\n");
    return;
  }

  // If the medicine is the first node in the linked list
  if (node_to_delete == head) {
    // Update the head of the linked list
    head = node_to_delete->next;
  } else {
    // Traverse the linked list to find the node before the node to be deleted
    node *previous_node = head;
    while (previous_node->next != node_to_delete) {
      previous_node = previous_node->next;
    }

    // Update the next pointer of the previous node to skip the node to be deleted
    previous_node->next = node_to_delete->next;
  }

  // Free the memory allocated for the node to be deleted
  free(node_to_delete);

  printf("Medicine deleted successfully\n");
}

// Function to display the medicines in the linked list
void displayMedicines() {
  // Traverse the linked list
  node *current_node = head;
  while (current_node != NULL) {
    // Print the data of the current node
    printf("Name: %s\n", current_node->data.name);
    printf("Manufacturer: %s\n", current_node->data.manufacturer);
    printf("Price: %.2f\n", current_node->data.price);
    printf("Quantity: %d\n\n", current_node->data.quantity);

    // Move to the next node
    current_node = current_node->next;
  }
}

// Main function
int main() {
  // Add some medicines to the linked list
  addMedicine("Paracetamol", "GlaxoSmithKline", 10.00, 50);
  addMedicine("Ibuprofen", "Pfizer", 15.00, 30);
  addMedicine("Aspirin", "Bayer", 5.00, 100);

  // Search for a medicine in the linked list
  node *found_node = searchMedicine("Paracetamol");
  if (found_node != NULL) {
    printf("Medicine found:\n");
    printf("Name: %s\n", found_node->data.name);
    printf("Manufacturer: %s\n", found_node->data.manufacturer);
    printf("Price: %.2f\n", found_node->data.price);
    printf("Quantity: %d\n\n", found_node->data.quantity);
  } else {
    printf("Medicine not found\n");
  }

  // Delete a medicine from the linked list
  deleteMedicine("Ibuprofen");

  // Display the medicines in the linked list
  displayMedicines();

  return 0;
}