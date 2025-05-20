//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A contact struct
typedef struct contact {
  char *name;
  char *number;
} contact;

// A phone book struct
typedef struct phone_book {
  contact *contacts;
  int size; // Number of contacts in the phone book
  int capacity; // Maximum number of contacts the phone book can hold
} phone_book;

// Create a new phone book
phone_book *create_phone_book(int initial_capacity) {
  phone_book *pb = malloc(sizeof(phone_book));
  pb->contacts = malloc(sizeof(contact) * initial_capacity);
  pb->size = 0;
  pb->capacity = initial_capacity;
  return pb;
}

// Add a contact to the phone book
void add_contact(phone_book *pb, char *name, char *number) {
  // Check if the phone book is full
  if (pb->size >= pb->capacity) {
    // Reallocate the phone book to double its current capacity
    pb->contacts = realloc(pb->contacts, sizeof(contact) * pb->capacity * 2);
    pb->capacity *= 2;
  }

  // Add the contact to the phone book
  pb->contacts[pb->size].name = strdup(name);
  pb->contacts[pb->size].number = strdup(number);
  pb->size++;
}

// Get a contact from the phone book by name
contact *get_contact_by_name(phone_book *pb, char *name) {
  for (int i = 0; i < pb->size; i++) {
    if (strcmp(pb->contacts[i].name, name) == 0) {
      return &pb->contacts[i];
    }
  }

  return NULL;
}

// Get a contact from the phone book by number
contact *get_contact_by_number(phone_book *pb, char *number) {
  for (int i = 0; i < pb->size; i++) {
    if (strcmp(pb->contacts[i].number, number) == 0) {
      return &pb->contacts[i];
    }
  }

  return NULL;
}

// Print the phone book
void print_phone_book(phone_book *pb) {
  for (int i = 0; i < pb->size; i++) {
    printf("%s: %s\n", pb->contacts[i].name, pb->contacts[i].number);
  }
}

// Free the phone book
void free_phone_book(phone_book *pb) {
  for (int i = 0; i < pb->size; i++) {
    free(pb->contacts[i].name);
    free(pb->contacts[i].number);
  }
  free(pb->contacts);
  free(pb);
}

int main() {
  // Create a new phone book
  phone_book *pb = create_phone_book(10);

  // Add some contacts to the phone book
  add_contact(pb, "John Doe", "555-1212");
  add_contact(pb, "Jane Doe", "555-1213");
  add_contact(pb, "John Smith", "555-1214");
  add_contact(pb, "Jane Smith", "555-1215");

  // Print the phone book
  print_phone_book(pb);

  // Get a contact from the phone book by name
  contact *contact = get_contact_by_name(pb, "John Doe");
  if (contact != NULL) {
    printf("Found contact: %s: %s\n", contact->name, contact->number);
  } else {
    printf("Contact not found.\n");
  }

  // Get a contact from the phone book by number
  contact = get_contact_by_number(pb, "555-1213");
  if (contact != NULL) {
    printf("Found contact: %s: %s\n", contact->name, contact->number);
  } else {
    printf("Contact not found.\n");
  }

  // Free the phone book
  free_phone_book(pb);

  return 0;
}