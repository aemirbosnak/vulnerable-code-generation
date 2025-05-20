//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 25
#define MAX_ADDRESS_LENGTH 100

struct Contact {
  char name[MAX_NAME_LENGTH];
  char address[MAX_ADDRESS_LENGTH];
  struct Contact* next;
};

struct Contact* createContact(char* name, char* address) {
  struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));
  strcpy(newContact->name, name);
  strcpy(newContact->address, address);
  newContact->next = NULL;
  return newContact;
}

struct Contact* addContact(struct Contact* head, char* name, char* address) {
  struct Contact* newContact = createContact(name, address);
  if (head == NULL) {
    head = newContact;
  } else {
    struct Contact* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newContact;
  }
  return head;
}

void printContacts(struct Contact* head) {
  struct Contact* temp = head;
  while (temp) {
    printf("%s: %s\n", temp->name, temp->address);
    temp = temp->next;
  }
}

int main() {
  struct Contact* head = NULL;

  // Add some contacts
  addContact(head, "Sherlock Holmes", "221B Baker St.");
  addContact(head, "John Watson", "221B Baker St.");
  addContact(head, "Dr. Watson", "221B Baker St.");

  // Print the contacts
  printContacts(head);

  return 0;
}