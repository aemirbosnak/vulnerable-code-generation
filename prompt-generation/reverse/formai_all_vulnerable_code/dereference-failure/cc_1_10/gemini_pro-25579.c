//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
  char name[50];
  char manufacturer[50];
  int quantity;
  float price;
} medicine;

// Define the structure of a node in the linked list
typedef struct node {
  medicine data;
  struct node *next;
} node;

// Define the head of the linked list
node *head = NULL;

// Function to insert a medicine into the linked list
void insert_medicine(medicine m) {
  // Create a new node
  node *new_node = (node *)malloc(sizeof(node));

  // Copy the data into the new node
  new_node->data = m;

  // Insert the new node at the beginning of the linked list
  new_node->next = head;
  head = new_node;
}

// Function to delete a medicine from the linked list
void delete_medicine(char *name) {
  // Find the node containing the medicine to be deleted
  node *current_node = head;
  node *previous_node = NULL;
  while (current_node != NULL && strcmp(current_node->data.name, name) != 0) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  // If the medicine was not found, return
  if (current_node == NULL) {
    return;
  }

  // If the medicine was found, delete the node
  if (previous_node == NULL) {
    head = current_node->next;
  } else {
    previous_node->next = current_node->next;
  }

  // Free the memory allocated to the node
  free(current_node);
}

// Function to search for a medicine in the linked list
medicine *search_medicine(char *name) {
  // Find the node containing the medicine to be searched
  node *current_node = head;
  while (current_node != NULL && strcmp(current_node->data.name, name) != 0) {
    current_node = current_node->next;
  }

  // If the medicine was not found, return NULL
  if (current_node == NULL) {
    return NULL;
  }

  // If the medicine was found, return the medicine
  return &current_node->data;
}

// Function to display the linked list of medicines
void display_medicines() {
  // Traverse the linked list and display each medicine
  node *current_node = head;
  while (current_node != NULL) {
    printf("%s %s %d %.2f\n", current_node->data.name, current_node->data.manufacturer, current_node->data.quantity, current_node->data.price);
    current_node = current_node->next;
  }
}

// Main function
int main() {
  // Create some medicines
  medicine m1 = {"Paracetamol", "GlaxoSmithKline", 100, 10.0};
  medicine m2 = {"Ibuprofen", "Pfizer", 50, 15.0};
  medicine m3 = {"Aspirin", "Bayer", 25, 5.0};

  // Insert the medicines into the linked list
  insert_medicine(m1);
  insert_medicine(m2);
  insert_medicine(m3);

  // Display the linked list of medicines
  printf("Medicines in the store:\n");
  display_medicines();

  // Search for a medicine
  char *name = "Ibuprofen";
  medicine *m = search_medicine(name);
  if (m != NULL) {
    printf("Medicine found:\n%s %s %d %.2f\n", m->name, m->manufacturer, m->quantity, m->price);
  } else {
    printf("Medicine not found.\n");
  }

  // Delete the medicine
  name = "Aspirin";
  delete_medicine(name);

  // Display the linked list of medicines
  printf("Medicines in the store after deletion:\n");
  display_medicines();

  return 0;
}