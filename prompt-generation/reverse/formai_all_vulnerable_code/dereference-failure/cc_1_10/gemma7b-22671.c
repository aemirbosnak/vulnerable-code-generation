//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct MailingListEntry {
  char name[MAX_NAME_LENGTH];
  char email[MAX_NAME_LENGTH];
  struct MailingListEntry* next;
} MailingListEntry;

MailingListEntry* InsertMailingListEntry(MailingListEntry* head, char* name, char* email) {
  MailingListEntry* newEntry = (MailingListEntry*)malloc(sizeof(MailingListEntry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->email, email);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    MailingListEntry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newEntry;
  }

  return head;
}

void PrintMailingList(MailingListEntry* head) {
  MailingListEntry* current = head;
  while (current) {
    printf("%s - %s\n", current->name, current->email);
    current = current->next;
  }
}

int main() {
  MailingListEntry* head = NULL;

  InsertMailingListEntry(head, "John Doe", "john.doe@example.com");
  InsertMailingListEntry(head, "Jane Doe", "jane.doe@example.com");
  InsertMailingListEntry(head, "Bill Smith", "bill.smith@example.com");

  PrintMailingList(head);

  return 0;
}