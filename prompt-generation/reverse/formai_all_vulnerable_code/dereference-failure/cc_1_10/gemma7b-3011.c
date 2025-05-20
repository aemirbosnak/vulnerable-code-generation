//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct DigitalDiaryEntry {
  char title[MAX_BUFFER_SIZE];
  char content[MAX_BUFFER_SIZE];
  struct DigitalDiaryEntry* nextEntry;
} DigitalDiaryEntry;

DigitalDiaryEntry* createEntry(char* title, char* content) {
  DigitalDiaryEntry* newEntry = malloc(sizeof(DigitalDiaryEntry));

  strcpy(newEntry->title, title);
  strcpy(newEntry->content, content);

  newEntry->nextEntry = NULL;

  return newEntry;
}

void addEntry(DigitalDiaryEntry* head, char* title, char* content) {
  DigitalDiaryEntry* newEntry = createEntry(title, content);

  if (head == NULL) {
    head = newEntry;
  } else {
    head->nextEntry = newEntry;
  }
}

void printEntries(DigitalDiaryEntry* head) {
  while (head) {
    printf("Title: %s\n", head->title);
    printf("Content: %s\n", head->content);
    printf("\n");
    head = head->nextEntry;
  }
}

int main() {
  DigitalDiaryEntry* head = NULL;

  addEntry(head, "My First Entry", "This is my first entry in the digital diary.");
  addEntry(head, "My Second Entry", "This is my second entry in the digital diary.");

  printEntries(head);

  return 0;
}