//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
};

struct MailingList {
  struct Node* head;
  struct Node* tail;
  int size;
};

void insertAtTail(struct MailingList* list, char* name) {
  struct Node* newNode = malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
  } else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->size++;
}

void printList(struct MailingList* list) {
  struct Node* current = list->head;
  while (current) {
    printf("%s ", current->name);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct MailingList* list = malloc(sizeof(struct MailingList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  insertAtTail(list, "John Doe");
  insertAtTail(list, "Jane Doe");
  insertAtTail(list, "Bill Smith");

  printList(list);

  return 0;
}