//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contact structure
typedef struct {
  char name[50];
  char number[20];
} Contact;

// Phone book structure
typedef struct {
  Contact *contacts;
  int num_contacts;
} PhoneBook;

// Create a new phone book
PhoneBook *create_phone_book() {
  PhoneBook *phone_book = malloc(sizeof(PhoneBook));
  phone_book->contacts = NULL;
  phone_book->num_contacts = 0;
  return phone_book;
}

// Add a contact to the phone book
void add_contact(PhoneBook *phone_book, Contact *contact) {
  phone_book->contacts = realloc(phone_book->contacts, sizeof(Contact) * (phone_book->num_contacts + 1));
  phone_book->contacts[phone_book->num_contacts] = *contact;
  phone_book->num_contacts++;
}

// Search for a contact in the phone book
Contact *search_contact(PhoneBook *phone_book, char *name) {
  for (int i = 0; i < phone_book->num_contacts; i++) {
    if (strcmp(phone_book->contacts[i].name, name) == 0) {
      return &phone_book->contacts[i];
    }
  }
  return NULL;
}

// Print the phone book
void print_phone_book(PhoneBook *phone_book) {
  for (int i = 0; i < phone_book->num_contacts; i++) {
    printf("%s: %s\n", phone_book->contacts[i].name, phone_book->contacts[i].number);
  }
}

// Free the memory allocated for the phone book
void free_phone_book(PhoneBook *phone_book) {
  free(phone_book->contacts);
  free(phone_book);
}

// Main function
int main() {
  // Create a new phone book
  PhoneBook *phone_book = create_phone_book();

  // Add some contacts to the phone book
  Contact contact1 = {"John Doe", "123-456-7890"};
  add_contact(phone_book, &contact1);
  Contact contact2 = {"Jane Doe", "098-765-4321"};
  add_contact(phone_book, &contact2);

  // Search for a contact in the phone book
  Contact *contact = search_contact(phone_book, "John Doe");
  if (contact != NULL) {
    printf("Found contact: %s (%s)\n", contact->name, contact->number);
  } else {
    printf("Contact not found.\n");
  }

  // Print the phone book
  print_phone_book(phone_book);

  // Free the memory allocated for the phone book
  free_phone_book(phone_book);

  return 0;
}