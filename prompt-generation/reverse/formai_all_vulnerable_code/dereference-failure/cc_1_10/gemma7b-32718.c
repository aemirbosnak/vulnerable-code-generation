//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_LIST_SIZE 100

typedef struct ListEntry {
  char name[MAX_NAME_LENGTH];
  struct ListEntry* next;
} ListEntry;

ListEntry* head = NULL;

void addToList(char* name) {
  ListEntry* newEntry = malloc(sizeof(ListEntry));
  strcpy(newEntry->name, name);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    ListEntry* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    tail->next = newEntry;
  }
}

void printList() {
  ListEntry* current = head;
  printf("Mailing List:\n");
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

int main() {
  addToList("Fred");
  addToList("Barney");
  addToList("Wilbur");
  addToList("Cecil");
  addToList("Elroy");
  addToList("The Cat");

  printList();

  return 0;
}