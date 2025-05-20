//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures

struct Item {
  char name[50];
  int quantity;
  float price;
};

struct Node {
  struct Item item;
  struct Node *next;
};

// Function prototypes

void add_item(struct Node **head, struct Item item);
void delete_item(struct Node **head, char *name);
void search_item(struct Node *head, char *name);
void print_list(struct Node *head);

// Main function

int main() {
  // Create a linked list to store the items
  struct Node *head = NULL;

  // Add some items to the list
  struct Item item1 = {"Aspirin", 10, 0.50};
  add_item(&head, item1);

  struct Item item2 = {"Ibuprofen", 20, 1.00};
  add_item(&head, item2);

  struct Item item3 = {"Acetaminophen", 30, 1.50};
  add_item(&head, item3);

  // Print the list of items
  print_list(head);

  // Search for an item in the list
  char *name = "Ibuprofen";
  search_item(head, name);

  // Delete an item from the list
  name = "Aspirin";
  delete_item(&head, name);

  // Print the list of items
  print_list(head);

  return 0;
}

// Function definitions

void add_item(struct Node **head, struct Item item) {
  // Create a new node
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

  // Copy the item into the new node
  new_node->item = item;

  // Insert the new node at the beginning of the list
  new_node->next = *head;
  *head = new_node;
}

void delete_item(struct Node **head, char *name) {
  // Find the node to be deleted
  struct Node *current = *head;
  struct Node *previous = NULL;

  while (current != NULL && strcmp(current->item.name, name) != 0) {
    previous = current;
    current = current->next;
  }

  // If the node was found, delete it
  if (current != NULL) {
    if (previous == NULL) {
      *head = current->next;
    } else {
      previous->next = current->next;
    }

    free(current);
  }
}

void search_item(struct Node *head, char *name) {
  // Find the node with the given name
  struct Node *current = head;

  while (current != NULL && strcmp(current->item.name, name) != 0) {
    current = current->next;
  }

  // If the node was found, print its details
  if (current != NULL) {
    printf("Item found:\n");
    printf("Name: %s\n", current->item.name);
    printf("Quantity: %d\n", current->item.quantity);
    printf("Price: %f\n", current->item.price);
  } else {
    printf("Item not found.\n");
  }
}

void print_list(struct Node *head) {
  // Traverse the list and print the details of each item
  struct Node *current = head;

  while (current != NULL) {
    printf("Item:\n");
    printf("Name: %s\n", current->item.name);
    printf("Quantity: %d\n", current->item.quantity);
    printf("Price: %f\n", current->item.price);

    current = current->next;
  }
}