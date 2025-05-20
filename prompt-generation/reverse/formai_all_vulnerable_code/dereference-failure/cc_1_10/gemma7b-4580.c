//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 255
#define MAX_MSG_LEN 1024

typedef struct MailListEntry {
  char name[MAX_NAME_LEN];
  char message[MAX_MSG_LEN];
  struct MailListEntry* next;
} MailListEntry;

typedef struct MailListManager {
  MailListEntry* head;
  MailListEntry* tail;
} MailListManager;

void addEntry(MailListManager* manager, char* name, char* message) {
  MailListEntry* newEntry = malloc(sizeof(MailListEntry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->message, message);
  newEntry->next = NULL;

  if (manager->head == NULL) {
    manager->head = newEntry;
    manager->tail = newEntry;
  } else {
    manager->tail->next = newEntry;
    manager->tail = newEntry;
  }
}

void printEntries(MailListManager* manager) {
  MailListEntry* currentEntry = manager->head;
  while (currentEntry) {
    printf("Name: %s\n", currentEntry->name);
    printf("Message: %s\n", currentEntry->message);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  MailListManager* manager = malloc(sizeof(MailListManager));
  manager->head = NULL;
  manager->tail = NULL;

  addEntry(manager, "John Doe", "This is a message from John Doe.");
  addEntry(manager, "Jane Doe", "This is a message from Jane Doe.");
  addEntry(manager, "Bill Smith", "This is a message from Bill Smith.");

  printEntries(manager);

  return 0;
}