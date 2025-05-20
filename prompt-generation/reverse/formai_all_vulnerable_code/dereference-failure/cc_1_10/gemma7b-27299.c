//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char title[20];
  char content[2000];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  printf("Enter title: ");
  scanf("%s", newEntry->title);
  printf("Enter content: ");
  scanf("%s", newEntry->content);
  newEntry->next = head;
  head = newEntry;
}

void listEntries() {
  Entry* currentEntry = head;
  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

void searchEntries() {
  char searchTerm[20];
  printf("Enter search term: ");
  scanf("%s", searchTerm);

  Entry* currentEntry = head;
  while (currentEntry) {
    if (strstr(currentEntry->title, searchTerm) || strstr(currentEntry->content, searchTerm)) {
      printf("Title: %s\n", currentEntry->title);
      printf("Content: %s\n", currentEntry->content);
      printf("\n");
    }
    currentEntry = currentEntry->next;
  }
}

int main() {
  int choice;

  while (1) {
    printf("Enter 1 to add an entry, 2 to list entries, 3 to search entries, or 4 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        listEntries();
        break;
      case 3:
        searchEntries();
        break;
      case 4:
        exit(0);
    }
  }

  return 0;
}