//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a contact
typedef struct contact {
  char *name;
  char *number;
} contact;

// Linked list node
typedef struct node {
  contact *data;
  struct node *next;
} node;

// Function to create a new contact
contact *create_contact(char *name, char *number) {
  contact *new_contact = (contact *)malloc(sizeof(contact));
  new_contact->name = strdup(name);
  new_contact->number = strdup(number);
  return new_contact;
}

// Function to add a contact to the phone book
void add_contact(node **head, contact *new_contact) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = new_contact;
  new_node->next = *head;
  *head = new_node;
}

// Function to print the phone book
void print_phone_book(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%s: %s\n", current->data->name, current->data->number);
    current = current->next;
  }
}

// Function to search for a contact by name
contact *search_contact(node *head, char *name) {
  node *current = head;
  while (current != NULL) {
    if (strcmp(current->data->name, name) == 0) {
      return current->data;
    }
    current = current->next;
  }
  return NULL;
}

// Function to delete a contact by name
void delete_contact(node **head, char *name) {
  node *current = *head;
  node *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->data->name, name) == 0) {
      if (previous == NULL) {
        *head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->data->name);
      free(current->data->number);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

// Main function
int main() {
  // Create an empty phone book
  node *head = NULL;

  // Add some contacts to the phone book
  contact *john = create_contact("John Doe", "555-1212");
  add_contact(&head, john);
  contact *jane = create_contact("Jane Doe", "555-1213");
  add_contact(&head, jane);
  contact *bob = create_contact("Bob Smith", "555-1214");
  add_contact(&head, bob);

  // Print the phone book
  printf("Phone Book:\n");
  print_phone_book(head);

  // Search for a contact by name
  contact *found_contact = search_contact(head, "John Doe");
  if (found_contact != NULL) {
    printf("Found contact: %s\n", found_contact->name);
  } else {
    printf("Contact not found.\n");
  }

  // Delete a contact by name
  delete_contact(&head, "Bob Smith");
  printf("Phone Book after deleting Bob Smith:\n");
  print_phone_book(head);

  // Free the memory allocated for the phone book
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current->data->name);
    free(current->data->number);
    free(current);
    current = next;
  }

  return 0;
}