//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char title[20];
  char content[200];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = malloc(sizeof(Entry));
  printf("Enter title: ");
  scanf("%s", newEntry->title);
  printf("Enter content: ");
  scanf("%s", newEntry->content);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* currentEntry = head;
    while (currentEntry->next) {
      currentEntry = currentEntry->next;
    }
    currentEntry->next = newEntry;
  }
}

void displayEntries() {
  Entry* currentEntry = head;
  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add Entry\n");
    printf("2. Display Entries\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        displayEntries();
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}