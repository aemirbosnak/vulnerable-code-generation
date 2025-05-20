//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct contact {
  char *name;
  char *number;
} contact;

// Create an array of contacts
contact contacts[MAX_CONTACTS];

// Initialize the number of contacts to 0
int num_contacts = 0;

// Function to add a new contact
void add_contact(char *name, char *number) {
  // Check if the array of contacts is full
  if (num_contacts == MAX_CONTACTS) {
    printf("The phone book is full. Cannot add new contact.\n");
    return;
  }

  // Allocate memory for the new contact
  contacts[num_contacts].name = malloc(strlen(name) + 1);
  contacts[num_contacts].number = malloc(strlen(number) + 1);

  // Copy the name and number to the new contact
  strcpy(contacts[num_contacts].name, name);
  strcpy(contacts[num_contacts].number, number);

  // Increment the number of contacts
  num_contacts++;
}

// Function to find a contact by name
contact *find_contact(char *name) {
  // Iterate over the array of contacts
  for (int i = 0; i < num_contacts; i++) {
    // Check if the name matches the search term
    if (strcmp(contacts[i].name, name) == 0) {
      // Return the contact
      return &contacts[i];
    }
  }

  // Return NULL if the contact was not found
  return NULL;
}

// Function to print the phone book
void print_phone_book() {
  // Iterate over the array of contacts
  for (int i = 0; i < num_contacts; i++) {
    // Print the contact's name and number
    printf("%s: %s\n", contacts[i].name, contacts[i].number);
  }
}

// Function to free the memory allocated to the contacts
void free_contacts() {
  // Iterate over the array of contacts
  for (int i = 0; i < num_contacts; i++) {
    // Free the memory allocated to the contact's name and number
    free(contacts[i].name);
    free(contacts[i].number);
  }
}

// Main function
int main() {
  // Add some contacts to the phone book
  add_contact("John Doe", "555-123-4567");
  add_contact("Jane Doe", "555-234-5678");
  add_contact("Bob Smith", "555-345-6789");

  // Print the phone book
  print_phone_book();

  // Find a contact by name
  contact *contact = find_contact("John Doe");

  // Print the contact's name and number
  printf("Name: %s, Number: %s\n", contact->name, contact->number);

  // Free the memory allocated to the contacts
  free_contacts();

  return 0;
}