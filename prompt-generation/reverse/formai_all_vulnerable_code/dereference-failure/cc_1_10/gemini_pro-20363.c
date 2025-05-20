//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data Structure to store a contact
typedef struct contact {
  char *name;
  char *phone_number;
} contact;

// Function to create a new contact
contact *create_contact(char *name, char *phone_number) {
  contact *new_contact = malloc(sizeof(contact));
  new_contact->name = malloc(strlen(name) + 1);
  strcpy(new_contact->name, name);
  new_contact->phone_number = malloc(strlen(phone_number) + 1);
  strcpy(new_contact->phone_number, phone_number);
  return new_contact;
}

// Function to print a contact
void print_contact(contact *contact) {
  printf("%s: %s\n", contact->name, contact->phone_number);
}

// Function to add a contact to a phone book
void add_contact(contact **phone_book, int *num_contacts, contact *new_contact) {
  phone_book[*num_contacts] = new_contact;
  (*num_contacts)++;
}

// Function to find a contact by name in a phone book
contact *find_contact_by_name(contact **phone_book, int num_contacts, char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      return phone_book[i];
    }
  }
  return NULL;
}

// Function to delete a contact by name from a phone book
void delete_contact_by_name(contact **phone_book, int *num_contacts, char *name) {
  int index = -1;
  for (int i = 0; i < *num_contacts; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      index = i;
      break;
    }
  }
  if (index != -1) {
    free(phone_book[index]->name);
    free(phone_book[index]->phone_number);
    free(phone_book[index]);
    for (int i = index; i < *num_contacts - 1; i++) {
      phone_book[i] = phone_book[i + 1];
    }
    (*num_contacts)--;
  }
}

// Function to print a phone book
void print_phone_book(contact **phone_book, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    print_contact(phone_book[i]);
  }
}

// Function to free the memory allocated for a phone book
void free_phone_book(contact **phone_book, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    free(phone_book[i]->name);
    free(phone_book[i]->phone_number);
    free(phone_book[i]);
  }
  free(phone_book);
}

// Main function
int main() {
  // Create a new phone book
  contact **phone_book = malloc(sizeof(contact *) * 100);
  int num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(phone_book, &num_contacts, create_contact("John Doe", "555-1212"));
  add_contact(phone_book, &num_contacts, create_contact("Jane Doe", "555-1213"));
  add_contact(phone_book, &num_contacts, create_contact("John Smith", "555-1214"));

  // Print the phone book
  printf("Phone Book:\n");
  print_phone_book(phone_book, num_contacts);

  // Find a contact by name
  contact *contact = find_contact_by_name(phone_book, num_contacts, "John Doe");
  if (contact != NULL) {
    printf("Found contact: %s\n", contact->name);
  } else {
    printf("Contact not found.\n");
  }

  // Delete a contact by name
  delete_contact_by_name(phone_book, &num_contacts, "John Smith");

  // Print the phone book after deleting a contact
  printf("Phone Book after deleting a contact:\n");
  print_phone_book(phone_book, num_contacts);

  // Free the memory allocated for the phone book
  free_phone_book(phone_book, num_contacts);

  return 0;
}