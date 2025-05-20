//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Node {
  char name[MAX_NAME_LENGTH];
  struct Node* next;
} Node;

typedef struct List {
  Node* head;
  Node* tail;
} List;

void add_node(List* list, char* name) {
  Node* new_node = malloc(sizeof(Node));
  strcpy(new_node->name, name);
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

void print_list(List* list) {
  Node* current = list->head;
  while (current) {
    printf("%s\n", current->name);
    current = current->next;
  }
}

void remove_node(List* list, char* name) {
  Node* previous = NULL;
  Node* current = list->head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        list->head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Error: Node not found.\n");
}

int main() {
  List* list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;

  add_node(list, "John Doe");
  add_node(list, "Jane Doe");
  add_node(list, "Peter Pan");

  print_list(list);

  remove_node(list, "Jane Doe");

  print_list(list);

  return 0;
}