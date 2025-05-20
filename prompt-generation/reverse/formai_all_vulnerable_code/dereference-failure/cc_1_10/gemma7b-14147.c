//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char name[MAX_ENTRIES];
  int number;
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name, int number) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->number = number;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newEntry;
  }

  return head;
}

int searchEntry(Entry* head, char* name) {
  Entry* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current->number;
    }
    current = current->next;
  }

  return -1;
}

int main() {
  Entry* phoneBook = NULL;
  phoneBook = insertEntry(phoneBook, "Donald Knuth", 1234);
  phoneBook = insertEntry(phoneBook, "Terry Tao", 5678);
  phoneBook = insertEntry(phoneBook, "Charles Babb", 9124);

  int number = searchEntry(phoneBook, "Donald Knuth");
  if (number != -1) {
    printf("Donald Knuth's number is: %d\n", number);
  } else {
    printf("Entry not found.\n");
  }

  return 0;
}