//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Contact {
  char name[MAX_NAME_LENGTH];
  char number[MAX_NAME_LENGTH];
  struct Contact* next;
} Contact;

void insertContact(Contact* head, char* name, char* number) {
  Contact* newContact = malloc(sizeof(Contact));
  strcpy(newContact->name, name);
  strcpy(newContact->number, number);
  newContact->next = NULL;

  if (head == NULL) {
    head = newContact;
  } else {
    Contact* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newContact;
  }
}

void searchContact(Contact* head, char* name) {
  Contact* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Name: %s\n", current->name);
      printf("Number: %s\n", current->number);
      return;
    }
    current = current->next;
  }
  printf("Contact not found.\n");
}

int main() {
  Contact* head = NULL;
  insertContact(head, "John Doe", "123-456-7890");
  insertContact(head, "Jane Doe", "456-789-0123");
  insertContact(head, "Jack Smith", "321-548-9632");

  searchContact(head, "Jane Doe");

  return 0;
}