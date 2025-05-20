//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
} Contact;

typedef struct {
  Contact *contacts;
  int num_contacts;
} AddressBook;

AddressBook *new_address_book() {
  AddressBook *book = malloc(sizeof(AddressBook));
  book->contacts = NULL;
  book->num_contacts = 0;
  return book;
}

void free_address_book(AddressBook *book) {
  for (int i = 0; i < book->num_contacts; i++) {
    free(book->contacts[i].name);
    free(book->contacts[i].email);
  }
  free(book->contacts);
  free(book);
}

void add_contact(AddressBook *book, char *name, char *email) {
  book->contacts = realloc(book->contacts, (book->num_contacts + 1) * sizeof(Contact));
  book->contacts[book->num_contacts].name = strdup(name);
  book->contacts[book->num_contacts].email = strdup(email);
  book->num_contacts++;
}

Contact *find_contact_by_name(AddressBook *book, char *name) {
  for (int i = 0; i < book->num_contacts; i++) {
    if (strcmp(book->contacts[i].name, name) == 0) {
      return &book->contacts[i];
    }
  }
  return NULL;
}

Contact *find_contact_by_email(AddressBook *book, char *email) {
  for (int i = 0; i < book->num_contacts; i++) {
    if (strcmp(book->contacts[i].email, email) == 0) {
      return &book->contacts[i];
    }
  }
  return NULL;
}

void print_address_book(AddressBook *book) {
  for (int i = 0; i < book->num_contacts; i++) {
    printf("%s (%s)\n", book->contacts[i].name, book->contacts[i].email);
  }
}

int main() {
  AddressBook *book = new_address_book();

  add_contact(book, "John Doe", "john.doe@example.com");
  add_contact(book, "Jane Smith", "jane.smith@example.com");
  add_contact(book, "Bill Jones", "bill.jones@example.com");

  print_address_book(book);

  Contact *contact = find_contact_by_name(book, "John Doe");
  if (contact != NULL) {
    printf("Found contact '%s' with email '%s'\n", contact->name, contact->email);
  } else {
    printf("Contact not found\n");
  }

  contact = find_contact_by_email(book, "jane.smith@example.com");
  if (contact != NULL) {
    printf("Found contact '%s' with email '%s'\n", contact->name, contact->email);
  } else {
    printf("Contact not found\n");
  }

  free_address_book(book);

  return 0;
}