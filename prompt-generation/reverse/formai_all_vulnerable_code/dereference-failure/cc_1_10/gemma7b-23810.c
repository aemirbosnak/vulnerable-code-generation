//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry {
  char name[MAX_NAME_LENGTH];
  char number[20];
  struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, char* number) {
  PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->number, number);
  newEntry->next = NULL;

  if (head == NULL) {
    return newEntry;
  }

  head->next = insertEntry(head->next, name, number);

  return head;
}

void searchEntry(PhoneBookEntry* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      printf("Phone number: %s\n", head->number);
      return;
    }

    head = head->next;
  }

  printf("Name not found.\n");
}

int main() {
  PhoneBookEntry* head = NULL;

  insertEntry(head, "John Doe", "555-123-4567");
  insertEntry(head, "Jane Doe", "555-456-7890");
  insertEntry(head, "Peter Pan", "555-246-3811");

  searchEntry(head, "Jane Doe");

  return 0;
}