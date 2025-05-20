//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20

typedef struct {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
  char phone[MAX_PHONE_LEN];
} Contact;

typedef struct {
  Contact* contacts;
  size_t size;
} ContactList;

void addContact(ContactList* list, Contact c) {
  list->size++;
  list->contacts = (Contact*)realloc(list->contacts, list->size * sizeof(Contact));
  list->contacts[list->size - 1] = c;
}

Contact* searchByName(ContactList* list, char* name) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->contacts[i].name, name) == 0) {
      return &list->contacts[i];
    }
  }
  return NULL;
}

Contact* searchByEmail(ContactList* list, char* email) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->contacts[i].email, email) == 0) {
      return &list->contacts[i];
    }
  }
  return NULL;
}

void printContact(Contact* c) {
  printf("Name: %s\n", c->name);
  printf("Email: %s\n", c->email);
  printf("Phone: %s\n", c->phone);
}

void printContacts(ContactList* list) {
  for (int i = 0; i < list->size; i++) {
    printf("Contact #%d:\n", i+1);
    printContact(&list->contacts[i]);
    printf("\n");
  }
}

int main() {
  ContactList list = { .size = 0, .contacts = NULL };
  Contact c1 = { "Alice", "alice@example.com", "123-456-7890" };
  Contact c2 = { "Bob", "bob@example.com", "234-567-8901" };
  addContact(&list, c1);
  addContact(&list, c2);
  printf("All contacts:\n");
  printContacts(&list);
  printf("\n");
  printf("Searching for Alice by name:\n");
  Contact* c = searchByName(&list, "Alice");
  if (c != NULL) {
    printContact(c);
  } else {
    printf("Alice not found\n");
  }
  printf("\n");
  printf("Searching for bob@example.com by email:\n");
  c = searchByEmail(&list, "bob@example.com");
  if (c != NULL) {
    printContact(c);
  } else {
    printf("bob@example.com not found\n");
  }
  free(list.contacts);
  return 0;
}