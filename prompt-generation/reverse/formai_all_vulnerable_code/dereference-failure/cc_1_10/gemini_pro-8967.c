//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a contact
typedef struct Contact {
  char *name;
  char *number;
} Contact;

// Function to create a new contact
Contact *create_contact(char *name, char *number) {
  Contact *contact = malloc(sizeof(Contact));
  contact->name = strdup(name);
  contact->number = strdup(number);
  return contact;
}

// Function to print a contact
void print_contact(Contact *contact) {
  printf("%s: %s\n", contact->name, contact->number);
}

// Function to add a contact to a phone book
void add_contact(Contact ***phone_book, int *num_contacts, Contact *contact) {
  *phone_book = realloc(*phone_book, (*num_contacts + 1) * sizeof(Contact *));
  (*phone_book)[*num_contacts] = contact;
  (*num_contacts)++;
}

// Function to search for a contact in a phone book
Contact *search_contact(Contact **phone_book, int num_contacts, char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      return phone_book[i];
    }
  }
  return NULL;
}

// Function to delete a contact from a phone book
void delete_contact(Contact ***phone_book, int *num_contacts, Contact *contact) {
  for (int i = 0; i < *num_contacts; i++) {
    if (phone_book[i] == contact) {
      for (int j = i; j < *num_contacts - 1; j++) {
        phone_book[j] = phone_book[j + 1];
      }
      (*num_contacts)--;
      return;
    }
  }
}

// Function to print all the contacts in a phone book
void print_phone_book(Contact **phone_book, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    print_contact(phone_book[i]);
  }
}

// Main function
int main() {
  // Create a new phone book
  Contact **phone_book = NULL;
  int num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(&phone_book, &num_contacts, create_contact("Alice", "555-1212"));
  add_contact(&phone_book, &num_contacts, create_contact("Bob", "555-1213"));
  add_contact(&phone_book, &num_contacts, create_contact("Carol", "555-1214"));

  // Print the phone book
  printf("Phone Book:\n");
  print_phone_book(phone_book, num_contacts);

  // Search for a contact in the phone book
  Contact *contact = search_contact(phone_book, num_contacts, "Bob");

  // Print the contact's information
  if (contact != NULL) {
    printf("Found contact: ");
    print_contact(contact);
  } else {
    printf("Contact not found.\n");
  }

  // Delete a contact from the phone book
  delete_contact(&phone_book, &num_contacts, contact);

  // Print the phone book
  printf("Phone Book:\n");
  print_phone_book(phone_book, num_contacts);

  // Free the memory allocated for the phone book
  for (int i = 0; i < num_contacts; i++) {
    free(phone_book[i]);
  }
  free(phone_book);

  return 0;
}