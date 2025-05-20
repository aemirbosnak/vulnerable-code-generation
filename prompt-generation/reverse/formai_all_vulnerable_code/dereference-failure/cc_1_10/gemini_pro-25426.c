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

  // Initialize the new node
  new_node->data = m;
  new_node->next = NULL;

  // If the linked list is empty, set the head to the new node
  if (head == NULL) {
    head = new_node;
  } else {
    // Otherwise, add the new node to the end of the linked list
    node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Function to search for a medicine in the linked list
node *search_medicine(char *name) {
  // Start at the head of the linked list
  node *current_node = head;

  // While the current node is not NULL and the name does not match, move to the next node
  while (current_node != NULL && strcmp(current_node->data.name, name) != 0) {
    current_node = current_node->next;
  }

  // Return the current node
  return current_node;
}

// Function to delete a medicine from the linked list
void delete_medicine(char *name) {
  // Find the medicine in the linked list
  node *node_to_delete = search_medicine(name);

  // If the medicine was found, delete it
  if (node_to_delete != NULL) {
    // If the medicine is the head of the linked list, set the head to the next node
    if (node_to_delete == head) {
      head = head->next;
    } else {
      // Otherwise, find the previous node and set its next pointer to the next node of the medicine to be deleted
      node *previous_node = head;
      while (previous_node->next != node_to_delete) {
        previous_node = previous_node->next;
      }
      previous_node->next = node_to_delete->next;
    }

    // Free the memory allocated to the medicine
    free(node_to_delete);
  }
}

// Function to print the linked list
void print_list() {
  // Start at the head of the linked list
  node *current_node = head;

  // While the current node is not NULL, print the medicine and move to the next node
  while (current_node != NULL) {
    printf("%s %d %f\n", current_node->data.name, current_node->data.quantity, current_node->data.price);
    current_node = current_node->next;
  }
}

// Function to get the total price of all the medicines in the linked list
float get_total_price() {
  // Start at the head of the linked list
  node *current_node = head;

  // Initialize the total price to 0
  float total_price = 0;

  // While the current node is not NULL, add the price of the medicine to the total price and move to the next node
  while (current_node != NULL) {
    total_price += current_node->data.price * current_node->data.quantity;
    current_node = current_node->next;
  }

  // Return the total price
  return total_price;
}

// Main function
int main() {
  // Add some medicines to the linked list
  medicine m1 = {"Aspirin", 100, 1.0};
  add_medicine(m1);
  medicine m2 = {"Ibuprofen", 50, 2.0};
  add_medicine(m2);
  medicine m3 = {"Acetaminophen", 25, 3.0};
  add_medicine(m3);

  // Print the linked list
  printf("The linked list of medicines is:\n");
  print_list();

  // Search for a medicine in the linked list
  char *name = "Ibuprofen";
  node *found_node = search_medicine(name);
  if (found_node != NULL) {
    printf("The medicine %s was found in the linked list.\n", name);
  } else {
    printf("The medicine %s was not found in the linked list.\n", name);
  }

  // Delete a medicine from the linked list
  name = "Acetaminophen";
  delete_medicine(name);

  // Print the linked list
  printf("The linked list of medicines after deleting %s is:\n", name);
  print_list();

  // Get the total price of all the medicines in the linked list
  float total_price = get_total_price();
  printf("The total price of all the medicines in the linked list is: %f\n", total_price);

  return 0;
}