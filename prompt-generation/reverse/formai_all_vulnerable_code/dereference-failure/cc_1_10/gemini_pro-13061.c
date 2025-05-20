//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
  char *name;
  char *email;
  char *phone_number;
} Contact;

// Create a new contact
Contact *new_contact(char *name, char *email, char *phone_number) {
  Contact *contact = malloc(sizeof(Contact));
  contact->name = strdup(name);
  contact->email = strdup(email);
  contact->phone_number = strdup(phone_number);
  return contact;
}

// Free a contact
void free_contact(Contact *contact) {
  free(contact->name);
  free(contact->email);
  free(contact->phone_number);
  free(contact);
}

// Add a contact to the phone book
void add_contact(Contact **contacts, int *num_contacts, Contact *contact) {
  contacts[*num_contacts] = contact;
  (*num_contacts)++;
}

// Find a contact by name
Contact *find_contact_by_name(Contact **contacts, int num_contacts, char *name) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->name, name) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Find a contact by email
Contact *find_contact_by_email(Contact **contacts, int num_contacts, char *email) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->email, email) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Find a contact by phone number
Contact *find_contact_by_phone_number(Contact **contacts, int num_contacts, char *phone_number) {
  for (int i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->phone_number, phone_number) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Print a contact
void print_contact(Contact *contact) {
  printf("Name: %s\n", contact->name);
  printf("Email: %s\n", contact->email);
  printf("Phone Number: %s\n", contact->phone_number);
}

// Print the phone book
void print_phone_book(Contact **contacts, int num_contacts) {
  for (int i = 0; i < num_contacts; i++) {
    print_contact(contacts[i]);
  }
}

// Main function
int main() {
  // Create an empty phone book
  Contact **contacts = malloc(sizeof(Contact *) * MAX_CONTACTS);
  int num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(contacts, &num_contacts, new_contact("Alice", "alice@example.com", "123-456-7890"));
  add_contact(contacts, &num_contacts, new_contact("Bob", "bob@example.com", "234-567-8901"));
  add_contact(contacts, &num_contacts, new_contact("Carol", "carol@example.com", "345-678-9012"));

  // Print the phone book
  print_phone_book(contacts, num_contacts);

  // Find a contact by name
  Contact *contact = find_contact_by_name(contacts, num_contacts, "Alice");
  if (contact != NULL) {
    printf("Found contact by name: ");
    print_contact(contact);
  } else {
    printf("Contact not found\n");
  }

  // Find a contact by email
  contact = find_contact_by_email(contacts, num_contacts, "bob@example.com");
  if (contact != NULL) {
    printf("Found contact by email: ");
    print_contact(contact);
  } else {
    printf("Contact not found\n");
  }

  // Find a contact by phone number
  contact = find_contact_by_phone_number(contacts, num_contacts, "345-678-9012");
  if (contact != NULL) {
    printf("Found contact by phone number: ");
    print_contact(contact);
  } else {
    printf("Contact not found\n");
  }

  // Free the contacts
  for (int i = 0; i < num_contacts; i++) {
    free_contact(contacts[i]);
  }
  free(contacts);

  return 0;
}