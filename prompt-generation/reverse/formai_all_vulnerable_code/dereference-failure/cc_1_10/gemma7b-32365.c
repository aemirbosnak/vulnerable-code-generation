//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;

typedef struct List {
  Node* head;
  Node* tail;
} List;

List* CreateList() {
  List* list = malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void InsertTail(List* list, char data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
}

void TraverseList(List* list) {
  Node* node = list->head;
  while (node) {
    printf("%c ", node->data);
    node = node->next;
  }
}

int main() {
  time_t start, end;
  List* list = CreateList();

  start = time(NULL);

  // Insert data into the list
  InsertTail(list, 'a');
  InsertTail(list, 'b');
  InsertTail(list, 'c');
  InsertTail(list, 'd');
  InsertTail(list, 'e');

  TraverseList(list);

  end = time(NULL);

  printf("\nTime taken: %ld seconds", end - start);

  return 0;
}