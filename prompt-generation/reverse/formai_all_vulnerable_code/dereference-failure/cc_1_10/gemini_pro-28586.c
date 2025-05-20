//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 256
#define MAX_EMAIL_LENGTH 256
#define MAX_LIST_SIZE 1000

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} contact;

typedef struct {
  contact contacts[MAX_LIST_SIZE];
  int size;
} mailing_list;

// Create a new mailing list
mailing_list* create_mailing_list() {
  mailing_list* list = (mailing_list*)malloc(sizeof(mailing_list));
  list->size = 0;
  return list;
}

// Add a contact to the mailing list
void add_contact(mailing_list* list, const char* name, const char* email) {
  if (list->size == MAX_LIST_SIZE) {
    printf("Error: Mailing list is full\n");
    return;
  }

  strcpy(list->contacts[list->size].name, name);
  strcpy(list->contacts[list->size].email, email);
  list->size++;
}

// Remove a contact from the mailing list
void remove_contact(mailing_list* list, const char* email) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->contacts[i].email, email) == 0) {
      // Found the contact to remove

      // Shift the remaining contacts down one position
      for (int j = i + 1; j < list->size; j++) {
        list->contacts[j - 1] = list->contacts[j];
      }

      // Decrement the size of the list
      list->size--;

      return;
    }
  }

  // Contact not found
  printf("Error: Contact not found\n");
}

// Print the contacts in the mailing list
void print_contacts(mailing_list* list) {
  for (int i = 0; i < list->size; i++) {
    printf("%s <%s>\n", list->contacts[i].name, list->contacts[i].email);
  }
}

// Send a message to all contacts in the mailing list
void send_message(mailing_list* list, const char* subject, const char* body) {
  for (int i = 0; i < list->size; i++) {
    // Simulate sending an email to the contact
    printf("Sending message to %s <%s>\n", list->contacts[i].name, list->contacts[i].email);
    printf("Subject: %s\n", subject);
    printf("Body: %s\n", body);
  }
}

int main() {
  // Create a new mailing list
  mailing_list* list = create_mailing_list();

  // Add some contacts to the mailing list
  add_contact(list, "John Doe", "john.doe@example.com");
  add_contact(list, "Jane Smith", "jane.smith@example.com");
  add_contact(list, "Bill Jones", "bill.jones@example.com");

  // Print the contacts in the mailing list
  print_contacts(list);

  // Send a message to all contacts in the mailing list
  send_message(list, "Hello from the mailing list", "This is a test message");

  // Remove a contact from the mailing list
  remove_contact(list, "bill.jones@example.com");

  // Print the contacts in the mailing list again
  print_contacts(list);

  // Free the memory allocated for the mailing list
  free(list);

  return 0;
}