//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char title[50];
  char content[200];
  int mood;
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry() {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  newEntry->next = head;
  head = newEntry;

  printf("Enter the title of your entry:");
  scanf("%s", newEntry->title);

  printf("Enter the content of your entry:");
  scanf("%s", newEntry->content);

  printf("Enter your mood for this entry (happy, sad, neutral):");
  scanf("%s", &newEntry->mood);
}

void listEntries() {
  Entry* currentEntry = head;
  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("Mood: %s\n", currentEntry->mood);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  int choice;

  while (1) {
    printf("Welcome to the digital diary!\n");
    printf("1. Add an entry\n");
    printf("2. List entries\n");
    printf("Enter your choice:");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry();
        break;
      case 2:
        listEntries();
        break;
      default:
        printf("Invalid choice\n");
    }

    printf("Would you like to continue? (Y/N): ");
    char continueChoice;
    scanf("%c", &continueChoice);

    if (continueChoice == 'N') {
      break;
    }
  }

  return 0;
}