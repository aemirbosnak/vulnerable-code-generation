//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_SIZE 1024

typedef struct Entry {
  char *title;
  char *content;
  struct Entry *next;
} Entry;

Entry *head = NULL;

void addEntry() {
  Entry *newEntry = malloc(sizeof(Entry));
  newEntry->title = malloc(MAX_SIZE);
  newEntry->content = malloc(MAX_SIZE);
  newEntry->next = NULL;

  printf("Enter title:");
  scanf("%s", newEntry->title);

  printf("Enter content:");
  scanf("%s", newEntry->content);

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newEntry;
  }
}

void listEntries() {
  Entry *temp = head;
  while (temp) {
    printf("Title: %s\n", temp->title);
    printf("Content: %s\n", temp->content);
    printf("\n");
    temp = temp->next;
  }
}

int main() {
  int choice;

  while (1) {
    printf("1. Add Entry\n");
    printf("2. List Entries\n");
    printf("Enter choice:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        listEntries();
        break;
      default:
        exit(1);
    }
  }

  return 0;
}