//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
  char *name;
  char *phone;
  struct Contact *next;
} Contact;

// Function to create a new contact
Contact *create_contact(char *name, char *phone) {
  Contact *new_contact = (Contact *)malloc(sizeof(Contact));
  new_contact->name = strdup(name);
  new_contact->phone = strdup(phone);
  new_contact->next = NULL;
  return new_contact;
}

// Function to add a new contact to the phone book
Contact *add_contact(Contact *head, Contact *new_contact) {
  if (head == NULL) {
    return new_contact;
  }
  Contact *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_contact;
  return head;
}

// Function to search for a contact by name
Contact *search_contact(Contact *head, char *name) {
  if (head == NULL) {
    return NULL;
  }
  Contact *current = head;
  while (current != NULL) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Function to print the phone book
void print_phone_book(Contact *head) {
  if (head == NULL) {
    printf("The phone book is empty.\n");
    return;
  }
  Contact *current = head;
  while (current != NULL) {
    printf("%s: %s\n", current->name, current->phone);
    current = current->next;
  }
}

// Function to free the memory allocated for the phone book
void free_phone_book(Contact *head) {
  if (head == NULL) {
    return;
  }
  Contact *current = head;
  while (current != NULL) {
    Contact *next = current->next;
    free(current->name);
    free(current->phone);
    free(current);
    current = next;
  }
}

int main() {
  // Create a new phone book
  Contact *head = NULL;

  // Add some contacts to the phone book
  head = add_contact(head, create_contact("John Doe", "123-456-7890"));
  head = add_contact(head, create_contact("Jane Doe", "123-456-7891"));
  head = add_contact(head, create_contact("John Smith", "123-456-7892"));

  // Print the phone book
  print_phone_book(head);

  // Search for a contact by name
  Contact *contact = search_contact(head, "John Doe");
  if (contact != NULL) {
    printf("Found contact: %s: %s\n", contact->name, contact->phone);
  } else {
    printf("Contact not found.\n");
  }

  // Free the memory allocated for the phone book
  free_phone_book(head);

  return 0;
}