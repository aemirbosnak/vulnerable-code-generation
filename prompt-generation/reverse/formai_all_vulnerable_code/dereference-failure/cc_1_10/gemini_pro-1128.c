//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a medicine
typedef struct medicine {
  int id;
  char name[50];
  char company[50];
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

// Function to add a new medicine to the linked list
void add_medicine(medicine m) {
  // Create a new node
  node *new_node = (node *)malloc(sizeof(node));

  // Copy the data into the new node
  new_node->data = m;

  // Set the next pointer of the new node to the head of the linked list
  new_node->next = head;

  // Set the head of the linked list to the new node
  head = new_node;
}

// Function to search for a medicine by name
medicine *search_medicine(char *name) {
  // Traverse the linked list
  node *current = head;
  while (current != NULL) {
    // Compare the name of the current medicine with the given name
    if (strcmp(current->data.name, name) == 0) {
      // Return the current medicine
      return &current->data;
    }

    // Move to the next node
    current = current->next;
  }

  // Return NULL if the medicine is not found
  return NULL;
}

// Function to delete a medicine by name
void delete_medicine(char *name) {
  // Traverse the linked list
  node *current = head;
  node *previous = NULL;
  while (current != NULL) {
    // Compare the name of the current medicine with the given name
    if (strcmp(current->data.name, name) == 0) {
      // If this is the first node in the linked list, set the head to the next node
      if (previous == NULL) {
        head = current->next;
      } else {
        // Otherwise, set the next pointer of the previous node to the next node of the current node
        previous->next = current->next;
      }

      // Free the current node
      free(current);

      // Return
      return;
    }

    // Move to the next node
    previous = current;
    current = current->next;
  }
}

// Function to print the linked list
void print_list() {
  // Traverse the linked list
  node *current = head;
  while (current != NULL) {
    // Print the data of the current medicine
    printf("%d %s %s %.2f %d\n", current->data.id, current->data.name, current->data.company, current->data.price, current->data.quantity);

    // Move to the next node
    current = current->next;
  }
}

int main() {
  // Add some medicines to the linked list
  medicine m1 = {1, "Paracetamol", "Cipla", 10.00, 100};
  add_medicine(m1);
  medicine m2 = {2, "Ibuprofen", "Advil", 15.00, 50};
  add_medicine(m2);
  medicine m3 = {3, "Aspirin", "Bayer", 20.00, 25};
  add_medicine(m3);

  // Print the linked list
  printf("Initial list:\n");
  print_list();

  // Search for a medicine by name
  medicine *m = search_medicine("Ibuprofen");
  if (m != NULL) {
    printf("Found medicine:\n");
    printf("%d %s %s %.2f %d\n", m->id, m->name, m->company, m->price, m->quantity);
  } else {
    printf("Medicine not found.\n");
  }

  // Delete a medicine by name
  delete_medicine("Aspirin");

  // Print the linked list
  printf("List after deleting Aspirin:\n");
  print_list();

  return 0;
}