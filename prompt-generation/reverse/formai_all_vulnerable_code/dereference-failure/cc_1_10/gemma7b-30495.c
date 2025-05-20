//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EMAIL_LENGTH 255

typedef struct MailListEntry {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  struct MailListEntry* next;
} MailListEntry;

MailListEntry* insertEntry(MailListEntry* head, char* name, char* email) {
  MailListEntry* newEntry = (MailListEntry*)malloc(sizeof(MailListEntry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->email, email);
  newEntry->next = NULL;

  if (head == NULL) {
    return newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

void printEntries(MailListEntry* head) {
  MailListEntry* currentEntry = head;

  while (currentEntry) {
    printf("Name: %s\n", currentEntry->name);
    printf("Email: %s\n", currentEntry->email);
    printf("\n");

    currentEntry = currentEntry->next;
  }
}

int main() {
  MailListEntry* head = NULL;

  insertEntry(head, "John Doe", "john.doe@gmail.com");
  insertEntry(head, "Jane Doe", "jane.doe@gmail.com");
  insertEntry(head, "Bob Smith", "bob.smith@gmail.com");

  printEntries(head);

  return 0;
}