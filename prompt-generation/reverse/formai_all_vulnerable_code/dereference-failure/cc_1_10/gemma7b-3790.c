//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char name[20];
  char number[20];
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head) {
  Entry* newEntry = malloc(sizeof(Entry));
  newEntry->next = NULL;

  printf("Enter name: ");
  scanf("%s", newEntry->name);

  printf("Enter number: ");
  scanf("%s", newEntry->number);

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void searchEntry(Entry* head) {
  char searchName[20];

  printf("Enter name: ");
  scanf("%s", searchName);

  Entry* currentEntry = head;

  while (currentEntry) {
    if (strcmp(currentEntry->name, searchName) == 0) {
      printf("Name: %s\n", currentEntry->name);
      printf("Number: %s\n", currentEntry->number);
      break;
    }
    currentEntry = currentEntry->next;
  }

  if (currentEntry == NULL) {
    printf("Entry not found.\n");
  }
}

int main() {
  Entry* head = NULL;

  while (1) {
    printf("Enter command (add/search/exit): ");
    char command[20];
    scanf("%s", command);

    switch (command[0]) {
      case 'a':
        head = insertEntry(head);
        break;
      case 's':
        searchEntry(head);
        break;
      case 'e':
        exit(0);
    }
  }

  return 0;
}