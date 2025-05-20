//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct PhoneBookEntry {
  char name[MAX_SIZE];
  char number[MAX_SIZE];
  struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, char* number) {
  PhoneBookEntry* newEntry = (PhoneBookEntry*)malloc(sizeof(PhoneBookEntry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->number, number);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void searchEntry(PhoneBookEntry* head, char* name) {
  PhoneBookEntry* currentEntry = head;

  while (currentEntry) {
    if (strcmp(currentEntry->name, name) == 0) {
      printf("Name: %s\n", currentEntry->name);
      printf("Number: %s\n", currentEntry->number);
      return;
    }

    currentEntry = currentEntry->next;
  }

  printf("No entry found for name: %s\n", name);
}

int main() {
  PhoneBookEntry* head = NULL;

  insertEntry(head, "John Doe", "123-45-678");
  insertEntry(head, "Jane Doe", "456-78-901");
  insertEntry(head, "Peter Pan", "246-89-013");

  searchEntry(head, "Jane Doe");

  return 0;
}