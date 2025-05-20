//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct PhoneBookEntry {
  char name[MAX_NAME_LENGTH];
  int number;
  struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, int number) {
  PhoneBookEntry* newEntry = malloc(sizeof(PhoneBookEntry));
  strcpy(newEntry->name, name);
  newEntry->number = number;
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
      printf("Phone number: %d\n", head->number);
      return;
    }
    head = head->next;
  }

  printf("Name not found.\n");
}

int main() {
  PhoneBookEntry* head = NULL;

  insertEntry(head, "John Doe", 12345);
  insertEntry(head, "Jane Doe", 67890);
  insertEntry(head, "Peter Pan", 98412);

  searchEntry(head, "Jane Doe");
  searchEntry(head, "Bob Smith");

  return 0;
}