//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of contacts
#define MAX_CONTACTS 100

// Define the structure of a contact
typedef struct {
  char name[50];
  char number[20];
  char email[50];
} contact;

// Define the structure of the phone book
typedef struct {
  contact contacts[MAX_CONTACTS];
  int num_contacts;
} phone_book;

// Create a new phone book
phone_book* create_phone_book() {
  phone_book* pb = malloc(sizeof(phone_book));
  pb->num_contacts = 0;
  return pb;
}

// Add a new contact to the phone book
void add_contact(phone_book* pb, char* name, char* number, char* email) {
  strcpy(pb->contacts[pb->num_contacts].name, name);
  strcpy(pb->contacts[pb->num_contacts].number, number);
  strcpy(pb->contacts[pb->num_contacts].email, email);
  pb->num_contacts++;
}

// Search for a contact in the phone book by name
contact* search_contact_by_name(phone_book* pb, char* name) {
  for (int i = 0; i < pb->num_contacts; i++) {
    if (strcmp(pb->contacts[i].name, name) == 0) {
      return &pb->contacts[i];
    }
  }
  return NULL;
}

// Search for a contact in the phone book by number
contact* search_contact_by_number(phone_book* pb, char* number) {
  for (int i = 0; i < pb->num_contacts; i++) {
    if (strcmp(pb->contacts[i].number, number) == 0) {
      return &pb->contacts[i];
    }
  }
  return NULL;
}

// Search for a contact in the phone book by email
contact* search_contact_by_email(phone_book* pb, char* email) {
  for (int i = 0; i < pb->num_contacts; i++) {
    if (strcmp(pb->contacts[i].email, email) == 0) {
      return &pb->contacts[i];
    }
  }
  return NULL;
}

// Print the phone book
void print_phone_book(phone_book* pb) {
  for (int i = 0; i < pb->num_contacts; i++) {
    printf("%s %s %s\n", pb->contacts[i].name, pb->contacts[i].number, pb->contacts[i].email);
  }
}

// Main function
int main() {
  // Create a new phone book
  phone_book* pb = create_phone_book();

  // Add some contacts to the phone book
  add_contact(pb, "John Doe", "555-1212", "john.doe@example.com");
  add_contact(pb, "Jane Doe", "555-1213", "jane.doe@example.com");
  add_contact(pb, "John Smith", "555-1214", "john.smith@example.com");
  add_contact(pb, "Jane Smith", "555-1215", "jane.smith@example.com");

  // Print the phone book
  print_phone_book(pb);

  // Search for a contact by name
  contact* c = search_contact_by_name(pb, "John Doe");
  if (c != NULL) {
    printf("Found contact: %s %s %s\n", c->name, c->number, c->email);
  } else {
    printf("Contact not found.\n");
  }

  // Search for a contact by number
  c = search_contact_by_number(pb, "555-1212");
  if (c != NULL) {
    printf("Found contact: %s %s %s\n", c->name, c->number, c->email);
  } else {
    printf("Contact not found.\n");
  }

  // Search for a contact by email
  c = search_contact_by_email(pb, "john.doe@example.com");
  if (c != NULL) {
    printf("Found contact: %s %s %s\n", c->name, c->number, c->email);
  } else {
    printf("Contact not found.\n");
  }

  return 0;
}