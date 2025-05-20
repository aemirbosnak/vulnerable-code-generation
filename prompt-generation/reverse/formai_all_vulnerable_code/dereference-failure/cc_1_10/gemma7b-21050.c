//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
} Node;

typedef struct MailingList {
  Node* head;
  int size;
} MailingList;

void insert_node(MailingList* list, char* name) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->name, name);
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
  } else {
    list->head->next = new_node;
  }

  list->size++;
}

void print_list(MailingList* list) {
  Node* current_node = list->head;
  while (current_node) {
    printf("%s ", current_node->name);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  MailingList* list = (MailingList*)malloc(sizeof(MailingList));
  list->head = NULL;
  list->size = 0;

  insert_node(list, "John Doe");
  insert_node(list, "Jane Doe");
  insert_node(list, "Peter Pan");

  print_list(list);

  return 0;
}