//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *first_name;
  char *last_name;
  char *phone_number;
} contact_t;

// Create a new contact
contact_t *new_contact(const char *first_name, const char *last_name, const char *phone_number) {
  contact_t *contact = malloc(sizeof(contact_t));
  contact->first_name = strdup(first_name);
  contact->last_name = strdup(last_name);
  contact->phone_number = strdup(phone_number);
  return contact;
}

// Free the memory allocated for a contact
void free_contact(contact_t *contact) {
  free(contact->first_name);
  free(contact->last_name);
  free(contact->phone_number);
  free(contact);
}

// Add a contact to the phone book
void add_contact(contact_t **contacts, size_t *num_contacts, contact_t *contact) {
  contacts[*num_contacts] = contact;
  (*num_contacts)++;
}

// Find a contact by first name
contact_t *find_contact_by_first_name(contact_t **contacts, size_t num_contacts, const char *first_name) {
  for (size_t i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->first_name, first_name) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Find a contact by last name
contact_t *find_contact_by_last_name(contact_t **contacts, size_t num_contacts, const char *last_name) {
  for (size_t i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->last_name, last_name) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Find a contact by phone number
contact_t *find_contact_by_phone_number(contact_t **contacts, size_t num_contacts, const char *phone_number) {
  for (size_t i = 0; i < num_contacts; i++) {
    if (strcmp(contacts[i]->phone_number, phone_number) == 0) {
      return contacts[i];
    }
  }
  return NULL;
}

// Print the contacts in the phone book
void print_contacts(contact_t **contacts, size_t num_contacts) {
  for (size_t i = 0; i < num_contacts; i++) {
    printf("%s %s %s\n", contacts[i]->first_name, contacts[i]->last_name, contacts[i]->phone_number);
  }
}

// Free the memory allocated for the phone book
void free_contacts(contact_t **contacts, size_t num_contacts) {
  for (size_t i = 0; i < num_contacts; i++) {
    free_contact(contacts[i]);
  }
  free(contacts);
}

int main() {
  // Create an empty phone book
  contact_t **contacts = malloc(0);
  size_t num_contacts = 0;

  // Add some contacts to the phone book
  add_contact(&contacts, &num_contacts, new_contact("John", "Doe", "555-1212"));
  add_contact(&contacts, &num_contacts, new_contact("Jane", "Doe", "555-1213"));
  add_contact(&contacts, &num_contacts, new_contact("Bob", "Smith", "555-1214"));
  add_contact(&contacts, &num_contacts, new_contact("Alice", "Smith", "555-1215"));

  // Print the contacts in the phone book
  print_contacts(contacts, num_contacts);

  // Find a contact by first name
  contact_t *contact = find_contact_by_first_name(contacts, num_contacts, "John");
  if (contact != NULL) {
    printf("Found contact: %s %s %s\n", contact->first_name, contact->last_name, contact->phone_number);
  } else {
    printf("Contact not found\n");
  }

  // Find a contact by last name
  contact = find_contact_by_last_name(contacts, num_contacts, "Doe");
  if (contact != NULL) {
    printf("Found contact: %s %s %s\n", contact->first_name, contact->last_name, contact->phone_number);
  } else {
    printf("Contact not found\n");
  }

  // Find a contact by phone number
  contact = find_contact_by_phone_number(contacts, num_contacts, "555-1213");
  if (contact != NULL) {
    printf("Found contact: %s %s %s\n", contact->first_name, contact->last_name, contact->phone_number);
  } else {
    printf("Contact not found\n");
  }

  // Free the memory allocated for the phone book
  free_contacts(contacts, num_contacts);

  return 0;
}